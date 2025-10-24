#!/usr/bin/env python3

"""
원본 윈치 코드를 정확히 기반으로 한 GKUSV 윈치 제어 노드 - 수정된 버전
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool, String

import os
import time
import json
import math

# 원본 코드와 동일한 import
from zaber_motion import Units, Library
from zaber_motion.ascii import Connection

class GKUSVWinchControllerNode(Node):
    """원본 윈치 코드 로직을 그대로 구현한 ROS 노드"""
    
    def __init__(self):
        super().__init__('gkusv_winch_controller')
        
        # 파라미터 선언
        self.declare_parameter('port', '/dev/ttyACM3')
        self.declare_parameter('simulation_mode', False)
        
        # 원본 코드의 전역 변수들을 그대로 인스턴스 변수로
        self.PORT_NAME = self.get_parameter('port').get_parameter_value().string_value
        self.LOG_FILE = 'motor_position_log.json'
        self.HOME_POSITION_FILE = 'home_position_log.json'  # 홈 포지션 파일 추가
        self.ANGULAR_SPEED_NMS34 = 90        # (90 degree / 1 sec), (360 degree / 4 sec)
        self.ANGULAR_SPEED_NMS23 = 212.5     # (212.5 degree / 1 sec), (850 degree / 4 sec), (7 mm / 4 sec), 850 degree = 7 mm linear movement
        self.Measurement_depth_Max = 10.09   # Unit: meter
        self.LIMIT_MAX_NMS34 = 4500
        self.LIMIT_MIN_NMS34 = 0     # unit: degree, 360 degrees * 12.5 rev = 4500 degree
        self.LIMIT_MAX_NMS23 = 0
        self.LIMIT_MIN_NMS23 = -10625     # unit: degree, 850 degrees * 12.5 rev = 10625 degree
        
        # 홈 포지션 관리
        self.home_position = None
        
        # 하드웨어 객체들
        self.connection = None
        self.devices = None
        self.nms34 = None
        self.nms23 = None
        self.is_connected = False
        
        # ROS2 Publishers
        self.current_depth_publisher = self.create_publisher(Float32, 'winch_current_depth', 10)
        self.error_publisher = self.create_publisher(String, 'winch_error', 10)
        
        # ROS2 Subscribers
        self.target_depth_subscriber = self.create_subscription(
            Float32, 'winch_target_depth', self.target_depth_callback, 10)
        self.emergency_stop_subscriber = self.create_subscription(
            Bool, 'winch_emergency_stop', self.emergency_stop_callback, 10)
        self.connect_subscriber = self.create_subscription(
            Bool, 'winch_connect', self.connect_callback, 10)
        # 홈 포지션 관련 구독자 추가
        self.set_home_subscriber = self.create_subscription(
            Bool, 'winch_set_home', self.set_home_callback, 10)
        self.go_home_subscriber = self.create_subscription(
            Bool, 'winch_go_home', self.go_home_callback, 10)
        
        # 상태 발행 타이머
        self.status_timer = self.create_timer(1.0, self.publish_current_status)
        
        self.get_logger().info(f'윈치 제어 노드 시작 - 포트: {self.PORT_NAME}')
        
        # 자동 연결 시도
        try:
            self.init_connection()
            self.device_setting()
            self.load_home_position()  # 홈 포지션 로드
            self.get_logger().info('윈치 초기화 완료')
        except Exception as e:
            self.get_logger().error(f'윈치 초기화 실패: {str(e)}')

    def init_connection(self):
        """원본 코드의 init_connection() 함수 그대로"""
        Library.enable_device_db_store()
        
        self.connection = Connection.open_serial_port(self.PORT_NAME)
        self.devices = self.connection.detect_devices()
        if not self.devices:
            print("Device recognition failure. Initialization using generic_command.")
            self.connection.generic_command("device restore")
            time.sleep(2)
            self.devices = self.connection.detect_devices()
            if not self.devices:
                raise RuntimeError("Device recognition failure.")
        
        if len(self.devices) < 1:
            raise RuntimeError("Need 2 motors. (MNS34, MNS23)")
            
        self.is_connected = True
        return self.connection, self.devices

    def device_setting(self):
        """원본 코드의 device_setting() 함수 그대로"""
        self.nms34 = self.devices[0].get_axis(2)  # MNS34 motor
        self.nms23 = self.devices[0].get_axis(1)  # MNS23 motor

        self.nms34.settings.set('limit.max', self.LIMIT_MAX_NMS34, Units.ANGLE_DEGREES)
        self.nms34.settings.set('limit.min', self.LIMIT_MIN_NMS34, Units.ANGLE_DEGREES)
        self.nms23.settings.set('limit.max', self.LIMIT_MAX_NMS23, Units.ANGLE_DEGREES)
        self.nms23.settings.set('limit.min', self.LIMIT_MIN_NMS23, Units.ANGLE_DEGREES)

        self.nms34.settings.set('maxspeed', self.ANGULAR_SPEED_NMS34, Units.ANGULAR_VELOCITY_DEGREES_PER_SECOND)
        self.nms23.settings.set('maxspeed', self.ANGULAR_SPEED_NMS23, Units.ANGULAR_VELOCITY_DEGREES_PER_SECOND)
        return self.nms23, self.nms34

    def save_position(self, pos_NMS34, pos_NMS23):
        """원본 코드의 save_position() 함수 수정된 버전"""
        try:
            with open(self.LOG_FILE, 'w') as f:
                json.dump({'NMS34_deg': pos_NMS34, 'NMS23_deg': pos_NMS23}, f)
        except Exception as e:
            self.get_logger().error(f"Error saving position: {e}")
        return pos_NMS34, pos_NMS23

    def save_home_position(self):
        """현재 위치를 홈 포지션으로 저장"""
        cur_pos_NMS34, cur_pos_NMS23 = self.cur_motor_position()
        home_data = {
            'NMS34_deg': cur_pos_NMS34,
            'NMS23_deg': cur_pos_NMS23,
            'depth_meter': 0.00224275 * cur_pos_NMS34,
            'timestamp': time.time()
        }
        
        try:
            with open(self.HOME_POSITION_FILE, 'w') as f:
                json.dump(home_data, f, indent=2)
            self.home_position = home_data
            self.get_logger().info(f"홈 포지션 저장: {home_data['depth_meter']:.2f}m")
            return True
        except Exception as e:
            self.get_logger().error(f"홈 포지션 저장 실패: {e}")
            return False

    def load_home_position(self):
        """저장된 홈 포지션 로드"""
        try:
            if os.path.exists(self.HOME_POSITION_FILE):
                with open(self.HOME_POSITION_FILE, 'r') as f:
                    self.home_position = json.load(f)
                self.get_logger().info(f"홈 포지션 로드: {self.home_position['depth_meter']:.2f}m")
            else:
                self.get_logger().info("저장된 홈 포지션이 없습니다")
        except Exception as e:
            self.get_logger().error(f"홈 포지션 로드 실패: {e}")

    def last_motor_position(self):
        """원본 코드의 last_motor_position() 함수 그대로"""
        if os.path.exists(self.LOG_FILE):
            with open(self.LOG_FILE, 'r') as f:
                data = json.load(f)
                last_NMS34 = data.get('NMS34_deg')
                last_NMS23 = data.get('NMS23_deg')
                return last_NMS34, last_NMS23
        else:
            cur_pos_NMS34, cur_pos_NMS23 = self.cur_motor_position()
            last_NMS34, last_NMS23 = self.save_position(cur_pos_NMS34, cur_pos_NMS23)
            return last_NMS34, last_NMS23

    def cur_motor_position(self):
        """원본 코드의 cur_motor_position() 함수 그대로"""
        if not self.is_connected or not self.nms34 or not self.nms23:
            return 0.0, 0.0
        cur_pos_NMS34 = self.nms34.get_position(Units.ANGLE_DEGREES)
        cur_pos_NMS23 = self.nms23.get_position(Units.ANGLE_DEGREES)
        return cur_pos_NMS34, cur_pos_NMS23

    def set_motor_position(self, target_pos_sensor):
        """홈 포지션 기준으로 동작하는 모터 제어"""
        if not self.is_connected:
            self.get_logger().error("윈치가 연결되지 않았습니다")
            return
            
        # 홈 포지션이 설정되어 있으면 홈 기준으로, 없으면 절대 위치로
        if self.home_position:
            # 홈 포지션 기준 상대 이동
            home_actual_depth = self.home_position['depth_meter']
            actual_target_pos = home_actual_depth + target_pos_sensor
            print(f"홈 기준 이동: {target_pos_sensor:.2f}m -> 실제 위치: {actual_target_pos:.2f}m")
        else:
            # 홈이 없으면 절대 위치
            actual_target_pos = target_pos_sensor
            print(f"절대 위치 이동: {target_pos_sensor:.2f}m")
        
        # 범위 체크
        if actual_target_pos < 0 or actual_target_pos > self.Measurement_depth_Max:
            self.get_logger().error(f"목표 위치 {actual_target_pos:.2f}m가 범위를 벗어났습니다 (0-{self.Measurement_depth_Max}m)")
            return
            
        # ----------------------------------------------------------------------
        # X: sensor position under water (meter), Y: motor angle (degree)
        # NMS34: Y = 445.88 * X + 1e^-12
        # NMS23: Y = 1052.8 * X + 6e^-12
        # ----------------------------------------------------------------------
        # X: motor angle (degree), Y: sensor position under water (meter)
        # NMS34: Y = 0.00224275 * X
        # NMS23: Y = 0.00094987 * X
        # ----------------------------------------------------------------------
        # X: NMS23 angle (degree), Y: sensor cable guide position (millimeter)
        # Y = 0.008235 * X
        # ----------------------------------------------------------------------

        last_pos_NMS34, last_pos_NMS23 = self.last_motor_position()
        last_pos_sensor = 0.00224275 * last_pos_NMS34
        lat_pos_cable_guide = 0.008235 * last_pos_NMS23 * (-1)  # Negative movement due to the NMS23 Max pos = 0
        if last_pos_NMS34 and last_pos_NMS23 is not None:
            print("----------------------------------------------------------------")
            print(f"Last NMS34 position: {last_pos_NMS34:.2f} degree")
            print(f"Last NMS23 position: {last_pos_NMS23:.2f} degree")
            print(f"Last sensor position: {last_pos_sensor:.2f} meter under water")
            print(f"Last cable-guide position: {lat_pos_cable_guide:.2f} millimeter")
            print(" ")
        else:
            print("No motor_position_log.json exist")

        self.nms23.settings.set('pos', last_pos_NMS23, Units.ANGLE_DEGREES)
        self.nms34.settings.set('pos', last_pos_NMS34, Units.ANGLE_DEGREES)

        cur_pos_NMS34, cur_pos_NMS23 = self.cur_motor_position()
        print(f"Set NMS34 position: {cur_pos_NMS34:.2f} degree")
        print(f"Set NMS23 position: {cur_pos_NMS23:.2f} degree")
        print(" ")

        # 실제 타겟 위치를 사용해서 계산
        target_pos_NMS34 = 445.88 * actual_target_pos + 1 * math.exp(-12)
        target_pos_NMS23 = (1052.8 * actual_target_pos + 6 * math.exp(-12)) * (-1)  # Negative movement due to the NMS23 Max pos = 0
        
        self.nms34.move_absolute(target_pos_NMS34, Units.ANGLE_DEGREES, wait_until_idle=False)
        self.nms23.move_absolute(target_pos_NMS23, Units.ANGLE_DEGREES, wait_until_idle=False)

        # 원본 코드와 정확히 동일한 루프
        while self.nms34.is_busy() or self.nms23.is_busy():
            cur_pos_NMS34 = self.nms34.get_position(Units.ANGLE_DEGREES)
            cur_pos_NMS23 = self.nms23.get_position(Units.ANGLE_DEGREES)
            self.save_position(cur_pos_NMS34, cur_pos_NMS23)

        cur_pos_sensor = 0.00224275 * target_pos_NMS34
        cur_pos_cable_guide = 0.008235 * target_pos_NMS23 * (-1)    # Negative movement due to the NMS23 Max pos = 0

        print(f"Current NMS34 position: {cur_pos_NMS34:.2f} degree")
        print(f"Current NMS23 position: {cur_pos_NMS23:.2f} degree")
        print(f"Current sensor position: {cur_pos_sensor:.2f} meter under water")
        if self.home_position:
            cur_actual_depth = 0.00224275 * cur_pos_NMS34
            relative_depth = cur_actual_depth - self.home_position['depth_meter']
            print(f"홈 기준 상대 깊이: {relative_depth:.2f} meter")
        print(f"Current cable-guide position: {cur_pos_cable_guide:.2f} millimeter")
        print("----------------------------------------------------------------")
        print(" ")

    def target_depth_callback(self, msg):
        """ROS 토픽으로 수심 설정 - 스레딩 제거"""
        input_measurement_depth = msg.data
        
        self.get_logger().info(f"Set the measurement depth under water (meter): {input_measurement_depth}")
        
        if 0 <= input_measurement_depth <= self.Measurement_depth_Max:
            target_pos_sensor = input_measurement_depth
            # 원본처럼 직접 호출 (스레딩 제거)
            self.set_motor_position(target_pos_sensor)
        else:
            print("Out of Range")
            self.get_logger().error("Out of Range")

    def set_home_callback(self, msg):
        """현재 위치를 홈 포지션으로 설정"""
        if msg.data:
            success = self.save_home_position()
            if success:
                self.get_logger().info("현재 위치를 홈 포지션으로 설정했습니다")
            else:
                self.get_logger().error("홈 포지션 설정 실패")

    def go_home_callback(self, msg):
        """홈 포지션으로 이동"""
        if msg.data and self.home_position:
            home_actual_depth = self.home_position['depth_meter']
            target_pos_NMS34 = 445.88 * home_actual_depth + 1 * math.exp(-12)
            target_pos_NMS23 = (1052.8 * home_actual_depth + 6 * math.exp(-12)) * (-1)
            
            self.get_logger().info(f"홈 포지션으로 이동: {home_actual_depth:.2f}m")
            
            self.nms34.move_absolute(target_pos_NMS34, Units.ANGLE_DEGREES, wait_until_idle=False)
            self.nms23.move_absolute(target_pos_NMS23, Units.ANGLE_DEGREES, wait_until_idle=False)
            
            while self.nms34.is_busy() or self.nms23.is_busy():
                cur_pos_NMS34 = self.nms34.get_position(Units.ANGLE_DEGREES)
                cur_pos_NMS23 = self.nms23.get_position(Units.ANGLE_DEGREES)
                self.save_position(cur_pos_NMS34, cur_pos_NMS23)
            
            self.get_logger().info("홈 포지션 도달 완료")
        elif msg.data and not self.home_position:
            self.get_logger().error("홈 포지션이 설정되지 않았습니다")

    def emergency_stop_callback(self, msg):
        """비상 정지"""
        if msg.data and self.is_connected:
            try:
                if self.nms34:
                    self.nms34.stop()
                if self.nms23:
                    self.nms23.stop()
                self.get_logger().warn('비상 정지 실행')
            except Exception as e:
                self.get_logger().error(f'비상 정지 실패: {str(e)}')

    def connect_callback(self, msg):
        """연결/해제 명령"""
        if msg.data:
            try:
                self.init_connection()
                self.device_setting()
                self.get_logger().info('윈치 재연결 완료')
            except Exception as e:
                self.get_logger().error(f'윈치 연결 실패: {str(e)}')
        else:
            self.disconnect()

    def disconnect(self):
        """연결 해제"""
        try:
            if self.connection:
                self.connection.close()
            self.is_connected = False
            self.get_logger().info('윈치 연결 해제됨')
        except Exception as e:
            self.get_logger().error(f'연결 해제 실패: {str(e)}')

    def publish_current_status(self):
        """현재 상태 발행 - 홈 기준 위치"""
        if self.is_connected:
            try:
                if self.home_position:
                    # 홈 기준 상대 깊이
                    cur_pos_NMS34, cur_pos_NMS23 = self.cur_motor_position()
                    current_actual_depth = 0.00224275 * cur_pos_NMS34
                    relative_depth = current_actual_depth - self.home_position['depth_meter']
                    depth_msg = Float32()
                    depth_msg.data = relative_depth
                    self.current_depth_publisher.publish(depth_msg)
                else:
                    # 홈이 없으면 절대 깊이
                    cur_pos_NMS34, cur_pos_NMS23 = self.cur_motor_position()
                    absolute_depth = 0.00224275 * cur_pos_NMS34
                    depth_msg = Float32()
                    depth_msg.data = absolute_depth
                    self.current_depth_publisher.publish(depth_msg)
            except Exception as e:
                pass  # 에러 시 조용히 넘어감

    def destroy_node(self):
        """노드 종료"""
        self.get_logger().info('윈치 노드 종료 중...')
        try:
            if self.connection:
                self.connection.close()
        except:
            pass
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    
    try:
        winch_controller = GKUSVWinchControllerNode()
        rclpy.spin(winch_controller)
    except KeyboardInterrupt:
        print("Quit")
    except Exception as e:
        print(f"Error occurs: {e}")
    finally:
        try:
            winch_controller.destroy_node()
        except:
            pass
        rclpy.shutdown()

if __name__ == '__main__':
    main()