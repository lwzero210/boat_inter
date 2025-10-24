// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvCamera.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CAMERA__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CAMERA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_camera__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvCamera_data
{
public:
  explicit Init_UsvCamera_data(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvCamera data(::gkusv_driver_interface::msg::UsvCamera::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_step
{
public:
  explicit Init_UsvCamera_step(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  Init_UsvCamera_data step(::gkusv_driver_interface::msg::UsvCamera::_step_type arg)
  {
    msg_.step = std::move(arg);
    return Init_UsvCamera_data(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_is_bigendian
{
public:
  explicit Init_UsvCamera_is_bigendian(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  Init_UsvCamera_step is_bigendian(::gkusv_driver_interface::msg::UsvCamera::_is_bigendian_type arg)
  {
    msg_.is_bigendian = std::move(arg);
    return Init_UsvCamera_step(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_encoding
{
public:
  explicit Init_UsvCamera_encoding(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  Init_UsvCamera_is_bigendian encoding(::gkusv_driver_interface::msg::UsvCamera::_encoding_type arg)
  {
    msg_.encoding = std::move(arg);
    return Init_UsvCamera_is_bigendian(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_width
{
public:
  explicit Init_UsvCamera_width(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  Init_UsvCamera_encoding width(::gkusv_driver_interface::msg::UsvCamera::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_UsvCamera_encoding(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_height
{
public:
  explicit Init_UsvCamera_height(::gkusv_driver_interface::msg::UsvCamera & msg)
  : msg_(msg)
  {}
  Init_UsvCamera_width height(::gkusv_driver_interface::msg::UsvCamera::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_UsvCamera_width(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

class Init_UsvCamera_header
{
public:
  Init_UsvCamera_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvCamera_height header(::gkusv_driver_interface::msg::UsvCamera::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvCamera_height(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCamera msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvCamera>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvCamera_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CAMERA__BUILDER_HPP_
