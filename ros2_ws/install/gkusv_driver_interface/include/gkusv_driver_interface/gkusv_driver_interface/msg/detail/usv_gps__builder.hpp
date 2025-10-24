// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_gps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvGps_cs
{
public:
  explicit Init_UsvGps_cs(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvGps cs(::gkusv_driver_interface::msg::UsvGps::_cs_type arg)
  {
    msg_.cs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_accuracy
{
public:
  explicit Init_UsvGps_accuracy(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  Init_UsvGps_cs accuracy(::gkusv_driver_interface::msg::UsvGps::_accuracy_type arg)
  {
    msg_.accuracy = std::move(arg);
    return Init_UsvGps_cs(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_height
{
public:
  explicit Init_UsvGps_height(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  Init_UsvGps_accuracy height(::gkusv_driver_interface::msg::UsvGps::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_UsvGps_accuracy(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_longitude
{
public:
  explicit Init_UsvGps_longitude(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  Init_UsvGps_height longitude(::gkusv_driver_interface::msg::UsvGps::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_UsvGps_height(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_latitude
{
public:
  explicit Init_UsvGps_latitude(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  Init_UsvGps_longitude latitude(::gkusv_driver_interface::msg::UsvGps::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_UsvGps_longitude(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_status
{
public:
  explicit Init_UsvGps_status(::gkusv_driver_interface::msg::UsvGps & msg)
  : msg_(msg)
  {}
  Init_UsvGps_latitude status(::gkusv_driver_interface::msg::UsvGps::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_UsvGps_latitude(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

class Init_UsvGps_header
{
public:
  Init_UsvGps_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvGps_status header(::gkusv_driver_interface::msg::UsvGps::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvGps_status(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvGps msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvGps>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvGps_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__BUILDER_HPP_
