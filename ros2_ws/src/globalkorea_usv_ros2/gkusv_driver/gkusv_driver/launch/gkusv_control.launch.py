from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gkusv_driver',
            executable='gkusv_motor_control_node',
            name='motor_control_node',
            output='screen'
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_control_ui_node',
            name='control_ui_node',
            output='screen'
        )
    ])
