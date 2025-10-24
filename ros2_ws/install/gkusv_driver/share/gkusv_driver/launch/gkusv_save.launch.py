from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gkusv_driver',
            executable='gkusv_data_save_node',
            name='data_save_node',
            output='screen'
        )
    ])
