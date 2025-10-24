import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from gkusv_driver_interface.msg import UsvWaterSensor
import subprocess
import time
import re
from datetime import datetime

class WaterSensorPublisher(Node):
    def __init__(self):
        super().__init__('water_sensor_publisher')
        
        # 파라미터 선언 - 'device'로 통일
        self.declare_parameter('device', '/dev/ttyUSB2')
        self.declare_parameter('slave_address', 20)
        self.declare_parameter('publish_rate', 0.5)  # 2초에 1번 (0.5Hz)
        
        # 파라미터 값 가져오기
        self.device = self.get_parameter('device').get_parameter_value().string_value
        self.slave_address = self.get_parameter('slave_address').get_parameter_value().integer_value
        publish_rate = self.get_parameter('publish_rate').get_parameter_value().double_value
        
        # 센서 정의
        self.sensors = {
            1: {'name': 'pH', 'unit': 'pH', 'register': 1000},
            2: {'name': 'Voltage', 'unit': 'mV', 'register': 2000},
            3: {'name': 'Temperature', 'unit': '°C', 'register': 3000},
            4: {'name': 'Salinity', 'unit': 'PSU', 'register': 4000},
            5: {'name': 'Pressure_mbar', 'unit': 'mbar', 'register': 5000},
            6: {'name': 'Conductivity', 'unit': 'μS/c', 'register': 6000}
        }
        
        # 센서 범위 캐시
        self.sensor_ranges = {}
        
        self.get_logger().info(f'Water Sensor Publisher 시작')
        self.get_logger().info(f'장치: {self.device}, 슬레이브 주소: {self.slave_address}')
        self.get_logger().info(f'발행 주기: {publish_rate}Hz ({1.0/publish_rate:.1f}초 간격)')
        
        # 센서 범위 초기화
        self.get_logger().info('센서 범위 초기화 중...')
        self.initialize_ranges()
        self.get_logger().info('센서 범위 초기화 완료')
        
        # ROS 퍼블리셔 및 타이머 설정 (초기화 후에 시작)
        self.publisher_ = self.create_publisher(UsvWaterSensor, 'water_sensor_data', 10)
        self.timer = self.create_timer(1.0/publish_rate, self.publish_water_sensor_data)

    def initialize_ranges(self):
        """모든 센서의 범위를 미리 읽어서 캐싱"""
        for sensor_id in sorted(self.sensors.keys()):
            info = self.sensors[sensor_id]
            range_value = self.read_sensor_range(sensor_id)
            self.get_logger().info(
                f"  센서 {sensor_id} ({info['name']:15s}): 범위 = {range_value}"
            )

    def read_sensor_value(self, register):
        """단일 센서 값 읽기"""
        cmd = [
            'mbpoll',
            '-b9600', '-Pnone', '-s2', '-0',
            f'-a{self.slave_address}',
            f'-r{register}',
            '-c2',
            '-1',
            self.device
        ]
        
        try:
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=5
            )
            
            if result.returncode == 0:
                target_register = register + 1
                pattern = f'\\[{target_register}\\]:'
                
                for line in result.stdout.split('\n'):
                    if re.search(pattern, line):
                        match = re.search(f'\\[{target_register}\\]:\\s+(\\d+)', line)
                        if match:
                            return int(match.group(1))
            return None
            
        except subprocess.TimeoutExpired:
            self.get_logger().warn(f'센서 읽기 타임아웃 (레지스터 {register})')
            return None
        except Exception as e:
            self.get_logger().warn(f'센서 읽기 오류 (레지스터 {register}): {e}')
            return None

    def read_sensor_range(self, sensor_id):
        """센서 범위 읽기 (캐시 우선)"""
        if sensor_id in self.sensor_ranges:
            return self.sensor_ranges[sensor_id]
        
        range_register = 1064 + (sensor_id - 1) * 1000
        
        cmd = [
            'mbpoll',
            '-b9600', '-Pnone', '-s2', '-0',
            f'-a{self.slave_address}',
            f'-r{range_register}',
            '-c1',
            '-1',
            self.device
        ]
        
        try:
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=5
            )
            
            if result.returncode == 0:
                pattern = f'\\[{range_register}\\]:'
                for line in result.stdout.split('\n'):
                    if re.search(pattern, line):
                        match = re.search(f'\\[{range_register}\\]:\\s+(\\d+)', line)
                        if match:
                            range_value = int(match.group(1))
                            self.sensor_ranges[sensor_id] = range_value
                            return range_value
            
            self.sensor_ranges[sensor_id] = 3
            return 3
            
        except:
            self.sensor_ranges[sensor_id] = 3
            return 3

    def apply_scaling(self, raw_value, range_value):
        """범위에 따른 스케일링"""
        if raw_value is None:
            return None
            
        scaling_factors = {
            0: 1000, 1: 100, 2: 10, 3: 1, 4: 1, 5: 1, 6: 1, 7: 1
        }
        
        scale = scaling_factors.get(range_value, 1)
        return raw_value / scale if scale != 0 else raw_value

    def publish_water_sensor_data(self):
        """수질 센서 데이터 읽기 및 발행"""
        msg = UsvWaterSensor()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "water_sensor"
        
        successful_reads = 0
        sensor_values = {}
        
        for sensor_id in sorted(self.sensors.keys()):
            info = self.sensors[sensor_id]
            
            # 원시 값 읽기
            raw_value = self.read_sensor_value(info['register'])
            
            if raw_value is not None:
                # 캐시된 범위 값 사용
                range_value = self.sensor_ranges.get(sensor_id, 3)
                scaled_value = self.apply_scaling(raw_value, range_value)
                
                # 메시지에 값 설정
                if sensor_id == 1:
                    msg.ph = float(scaled_value)
                elif sensor_id == 2:
                    msg.voltage = float(scaled_value)
                elif sensor_id == 3:
                    msg.temperature = float(scaled_value)
                elif sensor_id == 4:
                    msg.salinity = float(scaled_value)
                elif sensor_id == 5:
                    msg.pressure_mbar = float(scaled_value)
                elif sensor_id == 6:
                    msg.conductivity = float(scaled_value)
                
                sensor_values[info['name']] = scaled_value
                successful_reads += 1
                
            else:
                # 읽기 실패 시 -1.0으로 설정
                if sensor_id == 1:
                    msg.ph = -1.0
                elif sensor_id == 2:
                    msg.voltage = -1.0
                elif sensor_id == 3:
                    msg.temperature = -1.0
                elif sensor_id == 4:
                    msg.salinity = -1.0
                elif sensor_id == 5:
                    msg.pressure_mbar = -1.0
                elif sensor_id == 6:
                    msg.conductivity = -1.0
                
                self.get_logger().warn(f'센서 {sensor_id} ({info["name"]}) 읽기 실패')
        
        # 메시지 발행
        self.publisher_.publish(msg)
        
        # 로깅
        if successful_reads > 0:
            values_str = ', '.join([f"{k}={v:.2f}" for k, v in sensor_values.items()])
            self.get_logger().info(f'발행: {values_str}')
        else:
            self.get_logger().error('모든 센서 읽기 실패')

def main(args=None):
    rclpy.init(args=args)
    water_sensor_publisher = WaterSensorPublisher()
    
    try:
        rclpy.spin(water_sensor_publisher)
    except KeyboardInterrupt:
        water_sensor_publisher.get_logger().info("Water Sensor Publisher 종료")
    finally:
        water_sensor_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
