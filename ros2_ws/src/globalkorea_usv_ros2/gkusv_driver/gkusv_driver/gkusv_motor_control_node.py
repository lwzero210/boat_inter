import rclpy
from rclpy.node import Node
from std_msgs.msg import String 
from datetime import datetime, timezone, timedelta
from gkusv_driver_interface.msg import UsvControl
import json
import math
import time
from datetime import datetime, timedelta, timezone
from std_msgs.msg import Header
import serial
import os
import csv

class PWMControlNode(Node):
    def __init__(self):
        super().__init__('pwm_control_node')

        try:
            self.ser = serial.Serial('/dev/ttyACM0', 9600)
            self.board_connected = True
            self.get_logger().info('Board connected successfully.')
        except Exception as e:
            self.get_logger().error(f"Failed to connect to the board: {e}")
            self.board_connected = False  # 보드가 연결되지 않음

        # 기본값 설정 (초기값)
        self.x_voltage = 2.4
        self.y_voltage = 2.4
        self.x_voltage_save = 0.0
        self.y_voltage_save = 0.0
        self.boat_number = 2

        self.xy_subscriber = self.create_subscription(
            String,
            'xy_value_input',
            self.xy_callback,
            10
        )

        self.xy_publisher = self.create_publisher(UsvControl, 'xy_value_output', 10)
        self.xy_publisher_save = self.create_publisher(UsvControl, 'xy_value_save', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.get_logger().info('PWM Control Node initialized and ready to receive values.')

    def convert_voltage_to_pwm(self, voltage):
        # 0~5V 값을 0~255 PWM 값으로 변환
        if voltage == 2.5:
            pwm_value=125
        pwm_value = int((voltage / 5) * 254)
        pwm_value = max(0, min(254, pwm_value)) 
        # print(pwm_value)
        return pwm_value


    def map_value_range(self, x_value, x_top, x_bottom, y_value, y_left, y_right):
        min_input, max_input = -2.5, 2.5
        x_value = (x_value - min_input) / (max_input - min_input) * (x_top - x_bottom) + x_bottom
        y_value = (y_value - min_input) / (max_input - min_input) * (y_right - y_left) + y_left
        return x_value ,y_value


    def xy_callback(self, msg):
        try:
            data = msg.data.split(',')
            self.boat_number = int(data[0])
            self.x_voltage_save = float(data[1])
            self.y_voltage_save = float(data[2])
            csv_file = '/home/globalkorea/ros2_ws/src/globalkorea_usv_ros2/gkusv_driver/gkusv_driver/data/boat_control_setting.csv'
            if os.path.isfile(csv_file):
                with open(csv_file, mode='r', newline='') as file:
                    reader = csv.DictReader(file)
                    for row in reader:
                        if int(row["boat_index"]) == self.boat_number:
                            x_top = float(row["x_top"])
                            x_bottom = float(row["x_bottom"])
                            y_left = float(row["y_left"])
                            y_right = float(row["y_right"])

                            self.x_voltage, self.y_voltage = self.map_value_range(
                                float(data[1]), x_top, x_bottom,
                                float(data[2]), y_left, y_right
                            )
                            self.get_logger().info(f"Mapped values for Boat {self.boat_number}: X={self.x_voltage}V, Y={self.y_voltage}V")
                            break
            else:
                self.get_logger().error("CSV file not found.")

            if self.x_voltage == 0.5:
                self.x_voltage = 0.6
            if self.y_voltage == 0.5:
                self.y_voltage = 0.6

            if self.x_voltage == 1.0:
                self.x_voltage = 0.8
            if self.y_voltage == 1.0:
                self.y_voltage = 0.8

            if self.x_voltage == 1.5:
                self.x_voltage = 1.25
            if self.y_voltage == 1.5:
                self.y_voltage = 1.25

            if self.x_voltage == 2.0:
                self.x_voltage = 1.8
            if self.y_voltage == 2.0:
                self.y_voltage = 1.8

            if self.x_voltage == 2.5:
                self.x_voltage = 2.4
            if self.y_voltage == 2.5:
                self.y_voltage = 2.4

        except (IndexError, ValueError) as e:
            self.get_logger().error(f"Error parsing message: {e}")
            return
        
        self.get_logger().info(f"[boat:{self.boat_number}]Received contol: X={self.x_voltage}V, Y={self.y_voltage}V")


    def get_kst_time(self):
        kst = timezone(timedelta(hours=9))  # UTC+9 (KST)
        kst_time = datetime.now(kst)
        formatted_time = kst_time.strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]
        return formatted_time

    def timer_callback(self):
        x_pwm_value = self.convert_voltage_to_pwm(self.x_voltage)
        y_pwm_value = self.convert_voltage_to_pwm(self.y_voltage)

        control_msg = UsvControl()
        control_msg_save = UsvControl()

        if self.board_connected:
            # 보드가 연결된 경우에만 PWM 값 설정
            command = f"{x_pwm_value},{y_pwm_value}\n"
            self.ser.write(command.encode())  # 명령 전송
            # print(f"Voltage: X={self.x_voltage}, Y={self.y_voltage}")
            # print(f"Sent PWM: X={x_pwm_value}, Y={y_pwm_value}")

        current_time = self.get_kst_time()
        
        control_msg.header = Header()
        control_msg.header.stamp = self.get_clock().now().to_msg()  # ROS2 시간 형식 사용

        control_msg.boatindex = self.boat_number
        control_msg.x = self.x_voltage
        control_msg.y = self.y_voltage

        control_msg_save.header = Header()
        control_msg_save.header.stamp = self.get_clock().now().to_msg()  # ROS2 시간 형식 사용

        control_msg_save.boatindex = self.boat_number
        control_msg_save.x = self.x_voltage_save
        control_msg_save.y = self.y_voltage_save

        
        self.xy_publisher.publish(control_msg)
        self.xy_publisher_save.publish(control_msg_save)

        # self.get_logger().info(f"[{current_time}] Published Boat {self.boat_number}: X={self.x_voltage}V, Y={self.y_voltage}V")


def main(args=None):
    rclpy.init(args=args)
    
    # 노드 실행
    pwm_control_node = PWMControlNode()

    try:
        rclpy.spin(pwm_control_node)
    except KeyboardInterrupt:
        pwm_control_node.get_logger().info('Shutting down PWM Control Node.')

    # 노드 종료
    pwm_control_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
