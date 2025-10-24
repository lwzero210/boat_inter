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

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy
from sensor_msgs.msg import LaserScan
from cv_bridge import CvBridge
import cv2

class GPSPublisherNode(Node):
    def __init__(self):
        super().__init__('gps_publisher')
        qos_profile_sub = QoSProfile(depth=5) 
        qos_profile_pub = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        ) 

        self.subscription = self.create_subscription(
            LaserScan,
            '/wamv/sensors/lidars/lidar_wamv_sensor/scan',
            self.listener_callback,
            qos_profile_sub)

        self.publisher = self.create_publisher(
            LaserScan,
            '/lidar/scan/data', 
            qos_profile_pub)

    def listener_callback(self, msg):
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = GPSPublisherNode()
    rclpy.spin(node)
    # Clean up
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

# class ImagePublisherNode(Node):
#     def __init__(self):
#         super().__init__('image_publisher')
#         self.cv_bridge = CvBridge()

#         qos_profile_sub = QoSProfile(depth=1)
#         qos_profile_pub = QoSProfile(
#             reliability=ReliabilityPolicy.BEST_EFFORT,
#             durability=DurabilityPolicy.VOLATILE,
#             history=HistoryPolicy.KEEP_LAST,
#             depth=1
#         )

#         self.subscription = self.create_subscription(
#             Image,
#             '/wamv/sensors/cameras/front_left_camera_sensor/image_raw',
#             self.listener_callback,
#             qos_profile_sub)

#         self.publisher = self.create_publisher(
#             Image,
#             '/camera/image',  # 변경된 이미지를 발행할 토픽
#             qos_profile_pub)

#     def listener_callback(self, msg):
#         # ROS 메시지를 OpenCV 이미지로 변환
#         cv_image = self.cv_bridge.imgmsg_to_cv2(msg, "bgr8")

#         # 이미지 크기 변경 - 여기서는 원본의 절반 크기로 조정
#         reduced_image = cv2.resize(cv_image, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_LINEAR)

#         # 변경된 OpenCV 이미지를 ROS 메시지로 다시 변환
#         new_msg = self.cv_bridge.cv2_to_imgmsg(reduced_image, "bgr8")

#         # 변경된 메시지 발행
#         self.publisher.publish(new_msg)

# def main(args=None):
#     rclpy.init(args=args)
#     node = ImagePublisherNode()
#     rclpy.spin(node)
#     # Clean up
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()

