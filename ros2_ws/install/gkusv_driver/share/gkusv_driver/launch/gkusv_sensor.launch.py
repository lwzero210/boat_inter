from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gkusv_driver',
            executable='gkusv_camera_node',
            name='camera_node',
            output='screen'
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_compass_node',
            name='compass_node',
            output='screen'
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_gps_gnss_node',
            name='gps_node',
            output='screen'
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_imu_node',
            name='imu_node',
            output='screen'
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_water_sensor_node',
            name='water_sensor_node',
            output='screen',
            parameters=[
                {'device': '/dev/ttyUSB2'},
                {'slave_address': 20},
                {'publish_rate': 2.0}
            ]
        ),
        Node(
            package='gkusv_driver',
            executable='gkusv_winch_controller_node',
            name='winch_controller',
            output='screen',
            parameters=[
                {'port': '/dev/ttyACM3'},
                {'simulation_mode': False}
            ]
        ),
    ])
