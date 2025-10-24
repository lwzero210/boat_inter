// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvCompass.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_compass__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvCompass_heading
{
public:
  explicit Init_UsvCompass_heading(::gkusv_driver_interface::msg::UsvCompass & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvCompass heading(::gkusv_driver_interface::msg::UsvCompass::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCompass msg_;
};

class Init_UsvCompass_header
{
public:
  Init_UsvCompass_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvCompass_heading header(::gkusv_driver_interface::msg::UsvCompass::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvCompass_heading(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvCompass msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvCompass>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvCompass_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__BUILDER_HPP_
