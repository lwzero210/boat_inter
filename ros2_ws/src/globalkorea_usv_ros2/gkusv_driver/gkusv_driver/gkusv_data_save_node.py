import rclpy
from rclpy.node import Node
from gkusv_driver_interface.msg import UsvCompass, UsvGps, UsvImu, UsvControl
import csv
from rclpy.qos import QoSProfile, ReliabilityPolicy
from datetime import datetime, timezone

class GPSIMUDataSaver(Node):
    def __init__(self):
        super().__init__('gpsimu_data_saver')

        # imu_qos = QoSProfile(depth=100, reliability=ReliabilityPolicy.BEST_EFFORT)
        # compass_qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.BEST_EFFORT)

        # 데이터 초기화
        self.gps_data = None
        self.imu_data = None
        self.compass_data = None
        self.control_data = None

        # 각 토픽 구독 설정
        self.create_subscription(UsvGps, 'gps_data', self.gps_callback, 10)
        self.create_subscription(UsvImu, 'imu_data', self.imu_callback, 10)
        self.create_subscription(UsvCompass, 'compass_data', self.compass_callback,10)
        self.create_subscription(UsvControl, 'xy_value_save', self.control_callback, 10)

        self.get_logger().info('Datasave node has started.')

        self.current_time_save = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.file_path = f'/home/jeyoon/ros2_ws/src/globalkorea_usv_ros2/gkusv_driver/gkusv_driver/data/concat_data_{self.current_time_save}.csv'
        # CSV 파일 열기
        self.csv_file = open(self.file_path, mode='a', newline='')
        self.csv_writer = csv.writer(self.csv_file)

        # CSV 헤더 작성
        if self.csv_file.tell() == 0:
            self.csv_writer.writerow(['Time', 'Latitude', 'Longitude', 'Gps_Height', 'Gps_Accuracy', 'Compass_heading',
                                      'Roll', 'Pitch', 'Yaw', 'Acc_X', 'Acc_Y', 'Acc_Z', 'Mag_X', 'Mag_Y', 'Mag_Z', 'Imu_Temp',
                                      'BoatIndex', 'X_Command', 'Y_Command'])

    def gps_callback(self, msg):
        self.gps_data = (msg.header.stamp, msg.latitude, msg.longitude, msg.height, msg.accuracy)
        self.check_and_save_data()

    def imu_callback(self, msg):
        self.imu_data = (msg.header.stamp,
                         msg.euler_angles.x, msg.euler_angles.y, msg.euler_angles.z,
                         msg.acceleration.x, msg.acceleration.y, msg.acceleration.z,
                         msg.magnetic_field.x, msg.magnetic_field.y, msg.magnetic_field.z,
                         msg.temp)

    def compass_callback(self, msg):
        self.compass_data = (msg.header.stamp, msg.heading)

    def control_callback(self, msg):
        self.control_data = (msg.header.stamp, msg.boatindex, msg.x, msg.y)

    def check_and_save_data(self):
        # 모든 데이터가 수신되었는지 확인
        if not self.gps_data or not self.imu_data or not self.compass_data or not self.control_data:
            self.get_logger().warning('Not all data received. Skipping save.')
            return

        # 시간을 문자열로 변환하여 소수점 첫째 자리까지 비교
        gps_time = self.convert_ros_time_to_datetime(self.gps_data[0])
        imu_time = self.convert_ros_time_to_datetime(self.imu_data[0])
        compass_time = self.convert_ros_time_to_datetime(self.compass_data[0])
        control_time = self.convert_ros_time_to_datetime(self.control_data[0])

        print(f"GPS Time: {gps_time}, IMU Time: {imu_time}, Compass Time: {compass_time}, Control Time: {control_time}")

        # 시간 비교 (소수점 첫째 자리까지)
        if gps_time[:19] == imu_time[:19] == compass_time[:19] == control_time[:19]:
            try:
                row = [gps_time, self.gps_data[1], self.gps_data[2], self.gps_data[3], self.gps_data[4],
                       self.compass_data[1], *self.imu_data[1:],
                       self.control_data[1], self.control_data[2], self.control_data[3]]

                self.csv_writer.writerow(row)
                self.get_logger().info(f'Saved Data - Time: {gps_time}')
            except IndexError as e:
                self.get_logger().error(f'IndexError during saving: {e}')
            except Exception as e:
                self.get_logger().error(f'Unexpected error during saving: {e}')
        else:
            self.get_logger().warning('Timestamps do not match. Skipping data save.')

    @staticmethod
    def convert_ros_time_to_datetime(ros_time):
        """ROS 시간을 datetime 객체로 변환."""
        timestamp = ros_time.sec + ros_time.nanosec * 1e-9
        dt = datetime.fromtimestamp(timestamp, timezone.utc).astimezone()
        return dt.strftime('%Y-%m-%d %H:%M:%S.%f')[:-5]  # 소수점 첫째 자리까지만 표시

    def destroy_node(self):
        self.csv_file.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    gpsimu_data_saver = GPSIMUDataSaver()

    try:
        rclpy.spin(gpsimu_data_saver)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        gpsimu_data_saver.get_logger().error(f'Unexpected error: {e}')
    finally:
        gpsimu_data_saver.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
