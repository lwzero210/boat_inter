from setuptools import setup
import os
from glob import glob

package_name = "gkusv_driver"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", 
            ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("gkusv_driver/launch/*.py"))
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="varofla",
    maintainer_email="bh2107@naver.com",
    description="ROS 2 Driver for globalkorea usv",
    license="Apache 2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": ["driver = gkusv_driver.driver:main",
                            "gkusv_camera_node = gkusv_driver.gkusv_camera_node:main",
                            "gkusv_compass_node = gkusv_driver.gkusv_compass_node:main",
                            "gkusv_gps_gnss_node = gkusv_driver.gkusv_gps_gnss_node:main",
                            "gkusv_imu_node = gkusv_driver.gkusv_imu_node:main",
                            "gkusv_motor_control_node = gkusv_driver.gkusv_motor_control_node:main",
                            "gkusv_control_ui_node = gkusv_driver.gkusv_control_ui_node:main",
                            "gkusv_water_sensor_node = gkusv_driver.gkusv_water_sensor_node:main",
                            "gkusv_data_save_node = gkusv_driver.gkusv_data_save_node:main",
                            "gkusv_winch_controller_node = gkusv_driver.gkusv_winch_controller_node:main",
                            ],
    },
)
