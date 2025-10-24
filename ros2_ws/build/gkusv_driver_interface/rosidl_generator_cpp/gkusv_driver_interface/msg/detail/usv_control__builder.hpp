// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvControl.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvControl_y
{
public:
  explicit Init_UsvControl_y(::gkusv_driver_interface::msg::UsvControl & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvControl y(::gkusv_driver_interface::msg::UsvControl::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvControl msg_;
};

class Init_UsvControl_x
{
public:
  explicit Init_UsvControl_x(::gkusv_driver_interface::msg::UsvControl & msg)
  : msg_(msg)
  {}
  Init_UsvControl_y x(::gkusv_driver_interface::msg::UsvControl::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_UsvControl_y(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvControl msg_;
};

class Init_UsvControl_boatindex
{
public:
  explicit Init_UsvControl_boatindex(::gkusv_driver_interface::msg::UsvControl & msg)
  : msg_(msg)
  {}
  Init_UsvControl_x boatindex(::gkusv_driver_interface::msg::UsvControl::_boatindex_type arg)
  {
    msg_.boatindex = std::move(arg);
    return Init_UsvControl_x(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvControl msg_;
};

class Init_UsvControl_header
{
public:
  Init_UsvControl_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvControl_boatindex header(::gkusv_driver_interface::msg::UsvControl::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvControl_boatindex(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvControl>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvControl_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__BUILDER_HPP_
