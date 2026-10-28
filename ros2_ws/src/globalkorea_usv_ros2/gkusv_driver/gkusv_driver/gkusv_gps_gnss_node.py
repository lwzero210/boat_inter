import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from gkusv_driver_interface.msg import UsvGps  # your_package는 실제 패키지 이름으로 변경해야 함
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

    def connect(self):
        try:
            self.logger.info(f"Connecting to NTRIP server {self.host}:{self.port}...")
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
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
                self.logger.info("✅ NTRIP connection successful!")
                self.socket.setblocking(False)
                return True
            else:
                self.logger.error("❌ NTRIP connection failed - Authentication error or invalid mountpoint")
                return False

        except Exception as e:
            self.logger.error(f"❌ NTRIP connection failed: {str(e)}")
            return False

    def read_rtcm(self):
        try:
            ready = select.select([self.socket], [], [], 1.0)
            if not ready[0]:
                # 마지막 RTCM 데이터 수신 후 5초가 지났다면 경고
                if time.time() - self.last_rtcm_time > 5:
                    self.logger.warning("⚠️ No RTCM data received for 5 seconds")
                return None

            data = self.socket.recv(1024)
            if not data:
                self.logger.warning("Server closed connection")
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
                self.logger.info(f"📡 Received {len(rtcm_messages)} RTCM messages (Total: {self.rtcm_count})")
                return b''.join(rtcm_messages)
            return None

        except socket.error as e:
            if e.errno in (errno.EAGAIN, errno.EWOULDBLOCK):
                return None
            self.logger.error(f"RTCM read error: {str(e)}")
            return None

    def close(self):
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
        self.declare_parameter('publish_rate', 1.0)  # Hz

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
        if self.connect():
            if self.enable_nav_pvt():
                if self.start_ntrip_client():
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
            self.get_logger().info(f"✅ Connected to {self.port} at {self.baud_rate} baud")
            return True
        except serial.SerialException as e:
            self.get_logger().error(f"❌ Connection failed: {str(e)}")
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
                self.get_logger().info("✅ NAV-PVT message enabled")
                return True
            return False
        except Exception as e:
            self.get_logger().error(f"❌ Failed to enable NAV-PVT: {str(e)}")
            return False

    def start_ntrip_client(self):
        self.ntrip_client = NTRIPClient(
            self.ntrip_host,
            self.ntrip_port,
            self.ntrip_mountpoint,
            self.ntrip_username,
            self.ntrip_password,
            self.get_logger()
        )
        if self.ntrip_client.connect():
            self.ntrip_thread = threading.Thread(target=self._ntrip_worker)
            self.ntrip_thread.daemon = True
            self.ntrip_thread.start()
            return True
        return False

    def _ntrip_worker(self):
        self.running = True
        while self.running and rclpy.ok():
            rtcm_data = self.ntrip_client.read_rtcm()
            if rtcm_data:
                self.serial_port.write(rtcm_data)
                self.serial_port.flush()
            time.sleep(0.1)

    def start_monitoring(self):
        self.running = True
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
                    # msg.latitude = getattr(parsed_data, 'lat', 0) / 1e7
                    # msg.longitude = getattr(parsed_data, 'lon', 0) / 1e7
                    msg.latitude = getattr(parsed_data, 'lat', 0)
                    msg.longitude = getattr(parsed_data, 'lon', 0)
                    msg.height = getattr(parsed_data, 'height', 0) / 1000.0
                    msg.accuracy = getattr(parsed_data, 'hAcc', 0) / 1000.0
                    msg.cs = float(getattr(parsed_data, 'carrSoln', 0))

                    # Only log if status changes or every 10 messages
                    if fix_type != self.last_status or self.msg_count % 10 == 0:
                        status_str = self.fix_type_names.get(fix_type, "Unknown")
                        self.get_logger().info(f"""
📍 RTK Status Update (msg #{self.msg_count}):
Fix Type: {status_str}
Position: {msg.latitude}°N, {msg.longitude}°E
Height: {msg.height:.2f}m
Accuracy: {msg.accuracy:.3f}m
Carrier Solution: {msg.cs}
""")
                        self.last_status = fix_type
                    
                    self.publisher.publish(msg)

            except Exception as e:
                # 에러 발생시에도 기본값 전송
                # msg = UsvGps()
                # msg.header = Header()
                # msg.header.stamp = self.get_clock().now().to_msg()
                # msg.header.frame_id = "rtk"
                
                # msg.status = 0
                # msg.latitude = 0.0
                # msg.longitude = 0.0
                # msg.height = 0.0
                # msg.accuracy = 0.0
                # msg.cs = 0.0
                
                # self.publisher.publish(msg)
                self.get_logger().error(f"❌ Monitoring error: {str(e)}")
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