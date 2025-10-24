// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvImu.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvImu_temp
{
public:
  explicit Init_UsvImu_temp(::gkusv_driver_interface::msg::UsvImu & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvImu temp(::gkusv_driver_interface::msg::UsvImu::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvImu msg_;
};

class Init_UsvImu_magnetic_field
{
public:
  explicit Init_UsvImu_magnetic_field(::gkusv_driver_interface::msg::UsvImu & msg)
  : msg_(msg)
  {}
  Init_UsvImu_temp magnetic_field(::gkusv_driver_interface::msg::UsvImu::_magnetic_field_type arg)
  {
    msg_.magnetic_field = std::move(arg);
    return Init_UsvImu_temp(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvImu msg_;
};

class Init_UsvImu_acceleration
{
public:
  explicit Init_UsvImu_acceleration(::gkusv_driver_interface::msg::UsvImu & msg)
  : msg_(msg)
  {}
  Init_UsvImu_magnetic_field acceleration(::gkusv_driver_interface::msg::UsvImu::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_UsvImu_magnetic_field(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvImu msg_;
};

class Init_UsvImu_euler_angles
{
public:
  explicit Init_UsvImu_euler_angles(::gkusv_driver_interface::msg::UsvImu & msg)
  : msg_(msg)
  {}
  Init_UsvImu_acceleration euler_angles(::gkusv_driver_interface::msg::UsvImu::_euler_angles_type arg)
  {
    msg_.euler_angles = std::move(arg);
    return Init_UsvImu_acceleration(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvImu msg_;
};

class Init_UsvImu_header
{
public:
  Init_UsvImu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvImu_euler_angles header(::gkusv_driver_interface::msg::UsvImu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvImu_euler_angles(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvImu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvImu>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvImu_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__BUILDER_HPP_
