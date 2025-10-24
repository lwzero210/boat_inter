# UsvWaterSensor.msg
# 수질 센서 데이터 메시지
std_msgs/Header header
# 센서 값들 (읽기 실패 시 -1.0)
float32 ph              # pH 값
float32 voltage         # 전압 (mV)
float32 temperature     # 수온 (°C)
float32 salinity        # 염분도 (PSU)
float32 pressure_mbar   # 압력 (mbar)
float32 conductivity    # 전도도 (μS/c)
