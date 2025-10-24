import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from gkusv_driver_interface.msg import UsvCompass  # 커스텀 메시지 사용 (패키지 이름 확인 필요)
import serial
import time

class HeadingPublisher(Node):
    def __init__(self):
        super().__init__('heading_publisher')
        self.publisher_ = self.create_publisher(UsvCompass, 'compass_data', 10)
        self.timer = self.create_timer(0.1, self.read_and_publish_heading)
        self.serial_port = "/dev/ttyUSB1"
        self.baudrate = 115200
        self.running = True
        
        try:
            self.ser = serial.Serial(self.serial_port, self.baudrate, timeout=2)
            self.get_logger().info(f"Serial port {self.serial_port} opened successfully.")
            self.set_output_mode()
        except serial.SerialException as e:
            self.get_logger().error(f"Error opening serial port: {e}")
            self.running = False

    def set_output_mode(self):
        cmd_set_outmode = bytes.fromhex('77 05 00 0C 00 11')
        self.ser.write(cmd_set_outmode)
        time.sleep(0.1)
        response = self.ser.read(6)
        self.get_logger().info(f"Output mode response: {response}")

    def read_and_publish_heading(self):
        if not self.running:
            return
        
        cmd_read = bytes.fromhex('77 04 00 03 07')
        self.ser.write(cmd_read)
        time.sleep(0.1)
        res = self.ser.read(8)
        heading_value = self.parse_heading(res)

        if heading_value is not None:
            msg = UsvCompass()
            msg.header = Header()
            msg.header.stamp = self.get_clock().now().to_msg()  # 현재 시간 추가
            msg.heading = float(heading_value)
            self.publisher_.publish(msg)
            self.get_logger().info(f"Published Heading: {msg.heading}°")

    def parse_heading(self, response):
        if len(response) == 8 and response[0] == 0x77 and response[3] == 0x83:
            if not self.verify_data_checksum(response):
                self.get_logger().warn("Checksum mismatch")
                return None
            
            sign = 1 if response[4] & 0x80 == 0 else -1  # 부호 확인
            angle_int = (response[4] & 0x7F) * 100 + ((response[5] >> 4) * 10) + (response[5] & 0x0F)
            angle_frac = ((response[6] >> 4) * 10) + (response[6] & 0x0F)
            return sign * (angle_int + angle_frac / 100.0)
        else:
            self.get_logger().warn("Invalid response format")
            return None

    def verify_data_checksum(self, data):
        if len(data) != 8:
            return False
        checksum = sum(data[1:7]) & 0xFF
        return checksum == data[7]

    def destroy_node(self):
        if self.ser.is_open:
            self.ser.close()
        self.get_logger().info("Serial port closed.")
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = HeadingPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down heading publisher...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
