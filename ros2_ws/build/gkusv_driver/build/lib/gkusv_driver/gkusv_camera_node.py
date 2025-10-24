import rclpy
from rclpy.node import Node
# from sensor_msgs.msg import Image
from gkusv_driver_interface.msg import UsvCamera
from std_msgs.msg import Header
from cv_bridge import CvBridge
import cv2

class CameraNode(Node):
    def __init__(self, device_id=0):
        super().__init__('camera_node')
        self.publisher_ = self.create_publisher(UsvCamera, 'camera/image_raw', 10)
        self.bridge = CvBridge()
        self.device_id = device_id
        self.cap = cv2.VideoCapture(self.device_id)
        
        if not self.cap.isOpened():
            self.get_logger().error(f"카메라 {self.device_id}를 열 수 없습니다.")
            return
        
        self.timer = self.create_timer(0.1, self.capture_and_publish)
        self.get_logger().info(f"Camera node started with device {self.device_id}")

    def capture_and_publish(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn("프레임을 읽을 수 없습니다.")
            return
        
        # ros_image = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        # self.publisher_.publish(ros_image)

        # 커스텀 메시지 UsvCamera 생성
        msg = UsvCamera()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.height = frame.shape[0]
        msg.width = frame.shape[1]
        msg.encoding = "bgr8"
        msg.is_bigendian = 0
        msg.step = frame.shape[1] * 3  # BGR 채널이므로 width * 3
        msg.data = frame.flatten().tolist()  # numpy 배열을 리스트로 변환

        self.publisher_.publish(msg)
        
        
        cv2.imshow(f'Camera {self.device_id}', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()

    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = CameraNode(device_id=0)  # 특정 장치 선택
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("노드 종료 중...")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
