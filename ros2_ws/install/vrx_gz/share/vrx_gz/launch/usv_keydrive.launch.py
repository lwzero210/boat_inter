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

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression

def generate_launch_description():
    max_angle = LaunchConfiguration('max_angle', default='1.5708')  # pi/2
    thrust_config = LaunchConfiguration('thrust_config', default='H')
    namespace = LaunchConfiguration('namespace', default='wamv')

    return LaunchDescription([

        Node(
            condition=IfCondition(PythonExpression(["'", thrust_config, "' == 'H' or '", thrust_config, "' == 'T'"])),
            package='vrx_gz',
            executable='twist2thrust.py',
            name='twist2thrust',
            output='screen',
            arguments=['--keyboard'],
            remappings=[
                # ('left_cmd', [namespace, '/thrusters/left_thrust_cmd']),
                # ('right_cmd', [namespace, '/thrusters/right_thrust_cmd']),
                ('left_cmd', [namespace, '/thrusters/left/thrust']),
                ('right_cmd', [namespace, '/thrusters/right/thrust']),
            ],
        ),

        Node(
            package='vrx_gz',
            executable='camera_pub.py',  
            name='camera_pub',  
            output='screen',  
        ),

        Node(
            package='vrx_gz',
            executable='gps_pub.py',  
            name='gps_pub',  
            output='screen', 
        ),

        Node(
            package='vrx_gz',
            executable='imu_pub.py',  
            name='imu_pub',  
            output='screen', 
        ),


        Node(
            package='vrx_gz',
            executable='Lidar_pub.py',  
            name='Lidar_pub',  
            output='screen',  
        ),

        Node(
            package='vrx_gz',
            executable='datalogging.py',  
            name='datalogging',  
            output='screen',  
        )

        # Additional conditions can be added similarly for other configurations
    ])