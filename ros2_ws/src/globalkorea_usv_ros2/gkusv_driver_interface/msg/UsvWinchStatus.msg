# GKUSV 윈치 상태 메시지
# 파일 위치: ~/ros2_ws/src/gkusv_driver_interface/msg/UsvWinchStatus.msg

# 헤더
std_msgs/Header header

# 연결 상태
bool is_connected          # 하드웨어 연결 상태
bool is_moving            # 이동 중 여부

# 현재 상태
float64 current_depth     # 현재 수심 (미터)
float64 target_depth      # 목표 수심 (미터)

# 모터 위치 (도 단위)
float64 nms34_position    # NMS34 모터 위치 (도)
float64 nms23_position    # NMS23 모터 위치 (도)

# 오류 정보
string error_message      # 오류 메시지 (오류가 없으면 빈 문자열)