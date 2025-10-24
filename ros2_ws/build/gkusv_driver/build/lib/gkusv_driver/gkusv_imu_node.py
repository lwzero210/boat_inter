import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from geometry_msgs.msg import Vector3
from sensor_msgs.msg import Temperature
from gkusv_driver_interface.msg import UsvImu  # 커스텀 메시지 사용
import serial
import time
import math

class IMUPublisher(Node):
    def __init__(self):
        super().__init__('imu_publisher')
        self.publisher_ = self.create_publisher(UsvImu, 'imu_data', 10)
        self.timer = self.create_timer(0.1, self.publish_imu_data)  # 10Hz
        self.sensor = IAHRS('/dev/ttyUSB0')  # 포트 이름은 시스템에 맞게 수정

    def publish_imu_data(self):
        data_types = [
            ('e', 'Euler Angles', ['Roll', 'Pitch', 'Yaw']),
            ('a', 'Acceleration', ['X', 'Y', 'Z']),
            ('t', 'Temperature', ['Temp']),
            ('m', 'Magnetic Field', ['X', 'Y', 'Z'])
        ]

        results = {}
        for command, name, labels in data_types:
            self.sensor.request_data(command)
            data = self.sensor.read_data()
            parsed_data = self.sensor.parse_data(data, command)
            if parsed_data:
                results[name] = dict(zip(labels, parsed_data))

        if results:
            msg = UsvImu()
            msg.header = Header()
            msg.header.stamp = self.get_clock().now().to_msg()

            msg.euler_angles = Vector3(
                x=results['Euler Angles'].get('Roll', 0.0),
                y=results['Euler Angles'].get('Pitch', 0.0),
                z=results['Euler Angles'].get('Yaw', 0.0)
            )

            msg.acceleration = Vector3(
                x=results['Acceleration'].get('X', 0.0),
                y=results['Acceleration'].get('Y', 0.0),
                z=results['Acceleration'].get('Z', 0.0)
            )

            msg.magnetic_field = Vector3(
                x=results['Magnetic Field'].get('X', 0.0),
                y=results['Magnetic Field'].get('Y', 0.0),
                z=results['Magnetic Field'].get('Z', 0.0)
            )

            msg.temp = results['Temperature'].get('Temp', 0.0)

            self.publisher_.publish(msg)
            self.get_logger().info('Published IMU data')

    def destroy_node(self):
        self.sensor.close()
        super().destroy_node()

class IAHRS:
    def __init__(self, port, baudrate=115200):
        self.ser = serial.Serial(port, baudrate, timeout=1)
        time.sleep(2)  # 센서 초기화 대기

    def request_data(self, command):
        self.ser.write(f"{command}\r\n".encode())

    def read_data(self):
        return self.ser.readline().decode().strip()

    def parse_data(self, data, prefix):
        if data.startswith(f"{prefix}="):
            values = data[len(prefix)+1:].split(',')
            return [float(value) for value in values]
        return None

    def close(self):
        self.ser.close()

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = IMUPublisher()
    try:
        rclpy.spin(imu_publisher)
    except KeyboardInterrupt:
        imu_publisher.get_logger().info("Shutting down IMU Publisher")
    finally:
        imu_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
