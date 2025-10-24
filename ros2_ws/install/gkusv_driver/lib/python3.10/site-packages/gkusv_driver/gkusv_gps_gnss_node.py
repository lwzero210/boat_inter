import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from gkusv_driver_interface.msg import UsvGps
import serial
import time
from pyubx2 import UBXReader, UBXMessage, SET
import logging
import threading
import socket
import base64
import select
import errno
from datetime import datetime

class NTRIPClient:
    def __init__(self, host, port, mountpoint, username, password, logger):
        self.host = host
        self.port = port
        self.mountpoint = mountpoint
        self.username = username
        self.password = password
        self.socket = None
        self.running = False
        self.buffer = b""
        self.logger = logger
        self.rtcm_count = 0
        self.last_rtcm_time = time.time()
        self.connected = False  # 추가

    def connect(self):
        try:
            self.logger.info(f"Connecting to NTRIP server {self.host}:{self.port}...")
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.settimeout(10)  # 타임아웃 추가
            self.socket.connect((self.host, self.port))
            self.logger.info("Socket connection established")

            auth = base64.b64encode(f"{self.username}:{self.password}".encode()).decode()
            request = (
                f"GET /{self.mountpoint} HTTP/1.1\r\n"
                f"Host: {self.host}:{self.port}\r\n"
                f"Ntrip-Version: Ntrip/2.0\r\n"
                f"User-Agent: NTRIP PythonClient/1.0\r\n"
                f"Authorization: Basic {auth}\r\n"
                "\r\n"
            )

            self.logger.info(f"Sending request to mountpoint: {self.mountpoint}")
            self.socket.send(request.encode())

            headers = []
            while True:
                line = b""
                while b"\r\n" not in line:
                    byte = self.socket.recv(1)
                    if not byte:
                        raise Exception("Connection closed while reading headers")
                    line += byte

                line = line.decode('utf-8', errors='ignore').strip()
                if not line:
                    break
                headers.append(line)
                self.logger.info(f"Received header: {line}")

            if any("200 OK" in header for header in headers):
                self.logger.info("NTRIP connection successful!")
                self.socket.setblocking(False)
                self.connected = True  # 추가
                return True
            else:
                self.logger.error("NTRIP connection failed - Authentication error or invalid mountpoint")
                self.connected = False  # 추가
                return False

        except Exception as e:
            self.logger.error(f"NTRIP connection failed: {str(e)}")
            self.connected = False  # 추가
            if self.socket:
                try:
                    self.socket.close()
                except:
                    pass
                self.socket = None
            return False

    def read_rtcm(self):
        if not self.connected:  # 수정
            return None
            
        try:
            ready = select.select([self.socket], [], [], 1.0)
            if not ready[0]:
                if time.time() - self.last_rtcm_time > 5:
                    self.logger.warning("No RTCM data received for 5 seconds")
                return None

            data = self.socket.recv(1024)
            if not data:
                self.logger.warning("Server closed connection")
                self.connected = False  # 추가
                return None

            rtcm_messages = []
            i = 0
            while i < len(data):
                if data[i] == 0xD3:
                    if i + 2 < len(data):
                        length = ((data[i + 1] & 0x3) << 8) | data[i + 2]
                        total_length = length + 6

                        if i + total_length <= len(data):
                            rtcm_msg = data[i:i + total_length]
                            msg_type = (data[i + 3] << 4) | (data[i + 4] >> 4)
                            rtcm_messages.append(rtcm_msg)
                            i += total_length
                            continue
                i += 1

            if rtcm_messages:
                self.rtcm_count += len(rtcm_messages)
                self.last_rtcm_time = time.time()
                self.logger.info(f"Received {len(rtcm_messages)} RTCM messages (Total: {self.rtcm_count})")
                return b''.join(rtcm_messages)
            return None

        except socket.error as e:
            if e.errno in (errno.EAGAIN, errno.EWOULDBLOCK):
                return None
            self.logger.error(f"RTCM read error: {str(e)}")
            self.connected = False  # 추가
            return None

    def close(self):
        self.connected = False  # 추가
        if self.socket:
            try:
                self.socket.close()
                self.logger.info("NTRIP connection closed")
            except Exception as e:
                self.logger.error(f"Error closing NTRIP connection: {str(e)}")

class ZEDF9P_RTK_Node(Node):
    def __init__(self):
        super().__init__('zed_f9p_rtk_node')
        
        # Parameters
        self.declare_parameter('port', '/dev/ttyACM1')
        self.declare_parameter('baud_rate', 115200)
        self.declare_parameter('ntrip_host', 'gnssdata.or.kr')
        self.declare_parameter('ntrip_port', 2101)
        self.declare_parameter('ntrip_mountpoint', 'YECH-RTCM31')
        self.declare_parameter('ntrip_username', 'tomaqui@naver.com')
        self.declare_parameter('ntrip_password', 'gnss')
        self.declare_parameter('publish_rate', 1.0)

        # Get parameters
        self.port = self.get_parameter('port').value
        self.baud_rate = self.get_parameter('baud_rate').value
        self.ntrip_host = self.get_parameter('ntrip_host').value
        self.ntrip_port = self.get_parameter('ntrip_port').value
        self.ntrip_mountpoint = self.get_parameter('ntrip_mountpoint').value
        self.ntrip_username = self.get_parameter('ntrip_username').value
        self.ntrip_password = self.get_parameter('ntrip_password').value
        self.publish_rate = self.get_parameter('publish_rate').value

        # Initialize publisher
        self.publisher = self.create_publisher(UsvGps, 'gps_data', 10)
        
        # Initialize variables
        self.serial_port = None
        self.running = False
        self.ntrip_client = None
        self.ntrip_thread = None
        
        # NTRIP 재연결 관련 변수 추가
        self.ntrip_connected = False
        self.ntrip_retry_thread = None
        self.ntrip_retry_count = 0
        
        self.fix_type_names = {
            0: "No Fix",
            1: "Dead Reckoning",
            2: "2D Fix",
            3: "3D Fix",
            4: "GNSS Fix",
            5: "RTK Float",
            6: "RTK Fixed"
        }
        
        # Initialize statistics
        self.msg_count = 0
        self.last_status = None

        # Connect and start
        self.initialize()

    def initialize(self):
        # 기존 구조 유지하되 NTRIP 실패 시에도 GPS 시작하도록 수정
        if self.connect():
            if self.enable_nav_pvt():
                # NTRIP 클라이언트 시작 (실패해도 계속 진행)
                self.start_ntrip_client()
                # NTRIP 재시도 스레드 시작 (추가)
                self.start_ntrip_retry_thread()
                # GPS 모니터링은 항상 시작
                self.start_monitoring()

    def connect(self):
        try:
            self.serial_port = serial.Serial(
                port=self.port,
                baudrate=self.baud_rate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=1
            )
            self.get_logger().info(f"Connected to {self.port} at {self.baud_rate} baud")
            return True
        except serial.SerialException as e:
            self.get_logger().error(f"Connection failed: {str(e)}")
            return False

    def _send_ubx_message(self, msg):
        if not self.serial_port:
            return False
        try:
            self.serial_port.write(msg.serialize())
            time.sleep(0.1)
            return True
        except Exception as e:
            self.get_logger().error(f"Failed to send message: {str(e)}")
            return False

    def enable_nav_pvt(self):
        try:
            payload = bytearray([0x01, 0x07, 0x01])
            msg = UBXMessage(0x06, 0x01, SET, payload=payload)
            if self._send_ubx_message(msg):
                self.get_logger().info("NAV-PVT message enabled")
                return True
            return False
        except Exception as e:
            self.get_logger().error(f"Failed to enable NAV-PVT: {str(e)}")
            return False

    def start_ntrip_client(self):
        # 수정: 실패해도 True 반환하여 GPS 모니터링이 시작되도록 함
        try:
            self.ntrip_client = NTRIPClient(
                self.ntrip_host,
                self.ntrip_port,
                self.ntrip_mountpoint,
                self.ntrip_username,
                self.ntrip_password,
                self.get_logger()
            )
            if self.ntrip_client.connect():
                self.ntrip_connected = True
                self.ntrip_thread = threading.Thread(target=self._ntrip_worker)
                self.ntrip_thread.daemon = True
                self.ntrip_thread.start()
                self.get_logger().info("NTRIP client started successfully")
            else:
                self.ntrip_connected = False
                self.get_logger().warning("Initial NTRIP connection failed, will retry in background")
        except Exception as e:
            self.ntrip_connected = False
            self.get_logger().error(f"NTRIP client initialization error: {str(e)}")
        
        return True  # 항상 True 반환

    def start_ntrip_retry_thread(self):
        # 추가: NTRIP 재시도 스레드
        if not self.ntrip_connected:
            self.ntrip_retry_thread = threading.Thread(target=self._ntrip_retry_worker)
            self.ntrip_retry_thread.daemon = True
            self.ntrip_retry_thread.start()
            self.get_logger().info("NTRIP retry thread started")

    def _ntrip_retry_worker(self):
        # 추가: NTRIP 재연결 워커
        self.get_logger().info("NTRIP retry worker started")
        
        while rclpy.ok():
            try:
                # 연결되지 않은 경우에만 재시도
                if not self.ntrip_connected:
                    self.ntrip_retry_count += 1
                    self.get_logger().info(f"NTRIP reconnection attempt #{self.ntrip_retry_count}")
                    
                    # 기존 클라이언트 정리
                    if self.ntrip_client:
                        try:
                            self.ntrip_client.close()
                        except:
                            pass
                    
                    # 새 클라이언트 생성 및 연결 시도
                    self.ntrip_client = NTRIPClient(
                        self.ntrip_host,
                        self.ntrip_port,
                        self.ntrip_mountpoint,
                        self.ntrip_username,
                        self.ntrip_password,
                        self.get_logger()
                    )
                    
                    if self.ntrip_client.connect():
                        self.ntrip_connected = True
                        self.get_logger().info(f"NTRIP reconnection successful! (attempt #{self.ntrip_retry_count})")
                        
                        # 새 워커 스레드 시작
                        if self.ntrip_thread is None or not self.ntrip_thread.is_alive():
                            self.ntrip_thread = threading.Thread(target=self._ntrip_worker)
                            self.ntrip_thread.daemon = True
                            self.ntrip_thread.start()
                            self.get_logger().info("NTRIP worker restarted")
                        
                        # 재연결 성공 시 이 스레드 종료
                        break
                    else:
                        self.get_logger().warning(f"NTRIP reconnection failed (attempt #{self.ntrip_retry_count}), retrying in 15 seconds...")
                        time.sleep(15)
                
            except Exception as e:
                self.get_logger().error(f"NTRIP retry worker error: {str(e)}")
                time.sleep(15)

    def _ntrip_worker(self):
        # 수정: 연결 상태 체크 추가
        self.running = True
        while self.running and rclpy.ok():
            try:
                if self.ntrip_client and self.ntrip_client.connected:
                    rtcm_data = self.ntrip_client.read_rtcm()
                    if rtcm_data:
                        self.serial_port.write(rtcm_data)
                        self.serial_port.flush()
                else:
                    # 연결이 끊어진 경우
                    self.get_logger().warning("NTRIP connection lost, will reconnect")
                    self.ntrip_connected = False
                    # 재시도 스레드 다시 시작
                    if not self.ntrip_retry_thread or not self.ntrip_retry_thread.is_alive():
                        self.start_ntrip_retry_thread()
                    break
                    
            except Exception as e:
                self.get_logger().error(f"NTRIP worker error: {str(e)}")
                self.ntrip_connected = False
                break
                
            time.sleep(0.1)

    def start_monitoring(self):
        self.running = True
        self.get_logger().info("Starting GPS monitoring...")
        ubr = UBXReader(self.serial_port)
        
        while self.running and rclpy.ok():
            try:
                (raw_data, parsed_data) = ubr.read()
                if parsed_data and hasattr(parsed_data, 'identity') and parsed_data.identity == 'NAV-PVT':
                    self.msg_count += 1
                    
                    # Create and publish ROS message
                    msg = UsvGps()
                    msg.header = Header()
                    msg.header.stamp = self.get_clock().now().to_msg()
                    msg.header.frame_id = "rtk"
                    
                    fix_type = getattr(parsed_data, 'fixType', 0)
                    msg.status = fix_type
                    msg.latitude = getattr(parsed_data, 'lat', 0)
                    msg.longitude = getattr(parsed_data, 'lon', 0)
                    msg.height = getattr(parsed_data, 'height', 0) / 1000.0
                    msg.accuracy = getattr(parsed_data, 'hAcc', 0) / 1000.0
                    msg.cs = float(getattr(parsed_data, 'carrSoln', 0))

                    # 로깅에 NTRIP 상태 추가
                    if fix_type != self.last_status or self.msg_count % 20 == 0:
                        status_str = self.fix_type_names.get(fix_type, "Unknown")
                        ntrip_status = "Connected" if self.ntrip_connected else "Disconnected"
                        self.get_logger().info(f"""
RTK Status Update (msg #{self.msg_count}):
Fix Type: {status_str}
Position: {msg.latitude}N, {msg.longitude}E
Height: {msg.height:.2f}m
Accuracy: {msg.accuracy:.3f}m
NTRIP: {ntrip_status} (retry #{self.ntrip_retry_count})
""")
                        self.last_status = fix_type
                    
                    self.publisher.publish(msg)

            except Exception as e:
                self.get_logger().error(f"Monitoring error: {str(e)}")
                time.sleep(0.1)

    def destroy_node(self):
        self.running = False
        if self.ntrip_client:
            self.ntrip_client.close()
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()
            self.get_logger().info("Serial port closed")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ZEDF9P_RTK_Node()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
