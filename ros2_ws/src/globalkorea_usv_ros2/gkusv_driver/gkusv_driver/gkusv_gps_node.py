import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from gkusv_driver_interface.msg import UsvGps  # 커스텀 메시지
import serial
import time
from pyubx2 import UBXReader, UBXMessage, SET
import logging

# 로깅 설정
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class ZEDF9P_RTK(Node):
    def __init__(self):
        super().__init__('zedf9p_rtk_node')
        self.publisher_ = self.create_publisher(UsvGps, 'gps_data', 10)
        self.port = '/dev/ttyACM1'
        self.baud_rate = 115200
        self.serial_port = None
        self.running = False

        if self.connect():
            self.configure_rtk_base()
            self.start_monitoring()

    def connect(self):
        """RTK 장비 시리얼 연결"""
        try:
            self.serial_port = serial.Serial(
                port=self.port,
                baudrate=self.baud_rate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=1
            )
            logger.info(f"Connected to {self.port}")
            return True
        except serial.SerialException as e:
            logger.error(f"Connection failed: {str(e)}")
            return False

    def _send_ubx_message(self, msg):
        """UBX 메시지 전송"""
        if not self.serial_port:
            return False
        try:
            self.serial_port.write(msg.serialize())
            time.sleep(0.1)
            return True
        except Exception as e:
            logger.error(f"Failed to send message: {str(e)}")
            return False

    def enable_nav_pvt(self):
        """NAV-PVT 메시지를 활성화"""
        try:
            payload = bytearray([0x01, 0x07, 0x01])  # NAV-PVT 메시지를 활성화하는 명령
            msg = UBXMessage(0x06, 0x01, SET, payload=payload)
            self._send_ubx_message(msg)
            logger.info("NAV-PVT message enabled")
        except Exception as e:
            logger.error(f"Failed to enable NAV-PVT: {str(e)}")

    def configure_rtk_base(self):
        """RTK Base Station 설정"""
        try:
            payload = bytearray([
                0x00, 0x00, 0x01, 0x00,  # TMODE3 설정 (Survey-In 모드)
                0x00, 0x00, 0x00, 0x00,  # ecefXOrLat
                0x00, 0x00, 0x00, 0x00,  # ecefYOrLon
                0x00, 0x00, 0x00, 0x00,  # ecefZOrAlt
                0x00, 0x00, 0x00, 0x00,  # 추가 데이터
                0x10, 0x27, 0x00, 0x00,  # Accuracy 설정 (10000)
                0x3C, 0x00, 0x00, 0x00,  # Survey-In 최소 시간 (60초)
                0x50, 0xC3, 0x00, 0x00   # Survey-In 정확도 (50000)
            ])

            msg = UBXMessage(0x06, 0x71, SET, payload=payload)
            self._send_ubx_message(msg)
            logger.info("RTK Base Station TMODE3 설정 완료")

            # RTCM 메시지 활성화
            rtcm_msgs = [(1005, 1), (1077, 1), (1087, 1), (1127, 1), (1230, 1)]
            for msg_id, rate in rtcm_msgs:
                rtcm_payload = bytearray([0xF5, msg_id & 0xFF, rate])
                cfg_msg = UBXMessage(0x06, 0x01, SET, payload=rtcm_payload)
                self._send_ubx_message(cfg_msg)
                logger.info(f"RTCM message {msg_id} configured with rate {rate}")

        except Exception as e:
            logger.error(f"Base configuration failed: {str(e)}")

    def read_survey_in_status(self):
        """Survey-in 상태 읽기"""
        try:
            msg = UBXMessage(0x01, 0x3B, SET, payload=bytearray([]))
            self._send_ubx_message(msg)
            
            ubr = UBXReader(self.serial_port)
            (raw_data, parsed_data) = ubr.read()
            if parsed_data and hasattr(parsed_data, 'identity') and parsed_data.identity == 'NAV-SVIN':
                active = getattr(parsed_data, 'active', 0)
                valid = getattr(parsed_data, 'valid', 0)
                dur = getattr(parsed_data, 'dur', 0)
                meanAcc = getattr(parsed_data, 'meanAcc', 0)

                if active:
                    logger.info(f"Survey-in 진행 중: Duration={dur}s, Accuracy={meanAcc/10000:.4f}m")
                elif valid:
                    logger.info("Survey-in 완료")
                else:
                    logger.info("Survey-in 상태 없음")
        except Exception as e:
            logger.error(f"Survey-in 상태 읽기 실패: {str(e)}")

    def start_monitoring(self):
        """1Hz 주기로 GPS 데이터를 읽어 ROS2 토픽으로 발행"""
        self.running = True
        ubr = UBXReader(self.serial_port)
        last_update_time = 0

        while self.running:
            try:
                current_time = time.time()
                if current_time - last_update_time >= 1.0:  # 1Hz
                    (raw_data, parsed_data) = ubr.read()
                    if parsed_data and hasattr(parsed_data, 'identity') and parsed_data.identity == 'NAV-PVT':
                        gps_message = UsvGps()
                        gps_message.header = Header()
                        gps_message.header.stamp = self.get_clock().now().to_msg()
                        gps_message.header.frame_id = "gps"

                        gps_message.status = getattr(parsed_data, 'fixType', 0)
                        gps_message.accuracy = getattr(parsed_data, 'hAcc', 0) / 1000.0
                        gps_message.latitude = getattr(parsed_data, 'lat', 0) 
                        gps_message.longitude = getattr(parsed_data, 'lon', 0)
                        gps_message.height = getattr(parsed_data, 'height', 0) / 1000.0

                        self.publisher_.publish(gps_message)
                        last_update_time = current_time

            except Exception as e:
                logger.error(f"Monitoring error: {str(e)}")
                time.sleep(0.1)

    def stop_monitoring(self):
        """모니터링 종료"""
        self.running = False

    def close(self):
        """RTK 및 ROS2 노드 종료"""
        self.stop_monitoring()
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()
            logger.info("Connection closed")


def main(args=None):
    rclpy.init(args=args)
    node = ZEDF9P_RTK()
    rclpy.spin(node)
    node.close()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
