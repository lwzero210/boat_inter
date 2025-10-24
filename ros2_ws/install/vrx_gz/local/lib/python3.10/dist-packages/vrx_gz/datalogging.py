#!/usr/bin/env python3
# Copyright 2024 Electronics and Telecommunications Research Institute
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
import threading
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, Imu
from std_msgs.msg import Float64
import math
import csv
import os
from time import time, sleep
from datetime import datetime
from tf_transformations import euler_from_quaternion

class DataLogging(Node):
    def __init__(self):
        super().__init__('motor_controller')
        self.gps_subscription = self.create_subscription(NavSatFix, '/wamv/sensors/gps/gps/fix', self.gps_callback, 10)
        self.imu_subscription = self.create_subscription(Imu, '/wamv/sensors/imu/imu/data', self.imu_callback, 10)
        self.left_thrust_subscription = self.create_subscription(Float64, '/wamv/thrusters/left/thrust', self.left_thrust_callback, 10)
        self.right_thrust_subscription = self.create_subscription(Float64, '/wamv/thrusters/right/thrust', self.right_thrust_callback, 10)

        self.gps_data = None
        self.imu_data = None
        self.left_thrust = None
        self.right_thrust = None

        self.last_log_time = None
        self.data_count = 0
        self.start_time = self.get_clock().now().nanoseconds / 1e9

        self.last_gps_real_time = None
        self.last_imu_real_time = None
        self.last_joint_real_time = None

    def get_human_readable_time(self):
        return datetime.fromtimestamp(time()).strftime('%Y-%m-%d %H:%M:%S.%f')
    
    def calculate_dt(self, current_time_str, last_time_str):
        current_time = datetime.strptime(current_time_str, '%Y-%m-%d %H:%M:%S.%f')
        last_time = datetime.strptime(last_time_str, '%Y-%m-%d %H:%M:%S.%f')
        delta = current_time - last_time
        return delta.total_seconds()

    def gps_callback(self, msg):
        header_time = self.get_timestamp(msg.header.stamp)
        real_time = self.get_human_readable_time()
        if self.last_gps_real_time:
            dt = self.calculate_dt(real_time, self.last_gps_real_time)
        else:
            dt = 0.0
        self.gps_data = (header_time, real_time, dt, msg.latitude, msg.longitude)
        self.last_gps_real_time = real_time
        self.sync_data()

    def euler_from_quaternion(self, q):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        """
        x, y, z, w = q.x, q.y, q.z, q.w
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll = math.atan2(t0, t1)
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch = math.asin(t2)
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw = math.atan2(t3, t4)
        return roll, pitch, yaw

    def imu_callback(self, msg):
        header_time = self.get_timestamp(msg.header.stamp)
        real_time = self.get_human_readable_time()
        linear_x_accel = msg.linear_acceleration.x
        linear_y_accel = msg.linear_acceleration.y
        linear_z_accel = msg.linear_acceleration.z
        quaternion = (msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w)
        euler = euler_from_quaternion(quaternion)
        roll = euler[0]
        pitch = euler[1]
        yaw = euler[2]
        yaw_deg = math.degrees(euler[2])
        # if euler2 < 0:
        #     yaw = euler2 + 360
        # else:
        #     yaw = euler2
        roll_velocity = msg.angular_velocity.x
        pitch_velocity = msg.angular_velocity.y
        yaw_velocity = msg.angular_velocity.z

        self.imu_data = (header_time, real_time, roll, pitch, yaw, roll_velocity, pitch_velocity, yaw_velocity, linear_x_accel, linear_y_accel, linear_z_accel)
        self.sync_data()

    def left_thrust_callback(self, msg):
        self.left_thrust = msg.data
        self.sync_data()

    def right_thrust_callback(self, msg):
        self.right_thrust = msg.data
        self.sync_data()

    def sync_data(self):
        if self.gps_data and self.imu_data:
            gps_time, gps_real_time, dt, latitude, longitude = self.gps_data
            imu_time, imu_real_time, roll, pitch, yaw, roll_velocity, pitch_velocity, yaw_velocity, linear_x_accel, linear_y_accel, linear_z_accel = self.imu_data

            if gps_time == imu_time:
                self.log_and_save_gps_joint_data(gps_time, gps_real_time, dt, latitude, longitude, roll, pitch, yaw, roll_velocity, pitch_velocity, yaw_velocity, linear_x_accel, linear_y_accel, linear_z_accel)
                self.gps_data = None
                self.imu_data = None

    def log_and_save_gps_joint_data(self, header_time, real_time, dt, latitude, longitude, roll, pitch, yaw, roll_velocity, pitch_velocity, yaw_velocity, linear_x_accel, linear_y_accel, linear_z_accel):
        self.get_logger().info(f'TIME => sim_time: {header_time}, real_time: {real_time}')
        self.get_logger().info(f'GPS DATA => Latitude: {latitude}, Longitude: {longitude}')
        self.get_logger().info(f'IMU DATA => roll: {roll}, pitch: {pitch}, yaw: {yaw}')
        self.get_logger().info(f'IMU DATA => roll_velocity: {roll_velocity}, pitch_velocity: {pitch_velocity}, yaw_velocity: {yaw_velocity}')
        self.get_logger().info(f'IMU DATA => linear_x_accel: {linear_x_accel}, linear_y_accel: {linear_y_accel}, linear_z_accel: {linear_z_accel}')

    def get_timestamp(self, stamp):
        return stamp.sec + stamp.nanosec / 1e9

    def get_yaw_from_imu(self, orientation):
        q = orientation
        t3 = +2.0 * (q.w * q.z + q.x * q.y)
        t4 = +1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(t3, t4)
        return yaw

def main(args=None):
    rclpy.init(args=args)
    node = DataLogging()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
if __name__ == '__main__':
    main()


