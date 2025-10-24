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

import sys
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64
from std_srvs.srv import Trigger
from std_msgs.msg import Empty
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy


class TwistToThrust(Node):
    def __init__(self, linear_scaling, angular_scaling, keyboard=False):
        super().__init__('twist2drive')
        qos_profile_pub = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        ) 
        self.linear_scaling = linear_scaling
        self.angular_scaling = angular_scaling
        # self.keyboard = keyboard

        self.left_pub = self.create_publisher(Float64, "/wamv/thrusters/left/thrust", 5)
        self.right_pub = self.create_publisher(Float64, "/wamv/thrusters/right/thrust", 5)
        self.left_msg = Float64()
        self.right_msg = Float64()
        self.shooter_pub = self.create_publisher(Empty, "/wamv/shooters/ball_shooter/fire", 1)

        self.create_subscription(Twist, "cmd_vel", self.callback, 5)
        self.shooter_service = self.create_service(Trigger, 'ball_shooter', self.handle_ball_shooter)

    def callback(self, data):
        self.get_logger().debug("RX: Twist " + self.get_name())
        linfac = self.linear_scaling
        angfac = self.angular_scaling

        self.left_msg.data = data.linear.x * linfac - data.angular.z * angfac
        self.right_msg.data = data.linear.x * linfac + data.angular.z * angfac
        # else:
        #     self.left_msg.data = data.linear.x * linfac
        #     self.right_msg.data = data.angular.z * angfac

        self.left_pub.publish(self.left_msg)
        self.right_pub.publish(self.right_msg)

    def handle_ball_shooter(self, request, response):
        self.shooter_pub.publish(Empty())
        return response

def main(args=None):
    rclpy.init(args=args)

    linear_scaling = 0.2  # Example value, adjust as needed
    angular_scaling = 0.05  # Example value, adjust as needed

    twist_to_thrust = TwistToThrust(linear_scaling, angular_scaling, '--keyboard' in sys.argv)

    try:
        rclpy.spin(twist_to_thrust)
    except KeyboardInterrupt:
        pass
    finally:
        twist_to_thrust.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
