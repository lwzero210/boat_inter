// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/msg/detail/usv_water_sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace msg
{

namespace builder
{

class Init_UsvWaterSensor_conductivity
{
public:
  explicit Init_UsvWaterSensor_conductivity(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  ::gkusv_driver_interface::msg::UsvWaterSensor conductivity(::gkusv_driver_interface::msg::UsvWaterSensor::_conductivity_type arg)
  {
    msg_.conductivity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_pressure_mbar
{
public:
  explicit Init_UsvWaterSensor_pressure_mbar(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  Init_UsvWaterSensor_conductivity pressure_mbar(::gkusv_driver_interface::msg::UsvWaterSensor::_pressure_mbar_type arg)
  {
    msg_.pressure_mbar = std::move(arg);
    return Init_UsvWaterSensor_conductivity(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_salinity
{
public:
  explicit Init_UsvWaterSensor_salinity(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  Init_UsvWaterSensor_pressure_mbar salinity(::gkusv_driver_interface::msg::UsvWaterSensor::_salinity_type arg)
  {
    msg_.salinity = std::move(arg);
    return Init_UsvWaterSensor_pressure_mbar(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_temperature
{
public:
  explicit Init_UsvWaterSensor_temperature(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  Init_UsvWaterSensor_salinity temperature(::gkusv_driver_interface::msg::UsvWaterSensor::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_UsvWaterSensor_salinity(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_voltage
{
public:
  explicit Init_UsvWaterSensor_voltage(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  Init_UsvWaterSensor_temperature voltage(::gkusv_driver_interface::msg::UsvWaterSensor::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_UsvWaterSensor_temperature(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_ph
{
public:
  explicit Init_UsvWaterSensor_ph(::gkusv_driver_interface::msg::UsvWaterSensor & msg)
  : msg_(msg)
  {}
  Init_UsvWaterSensor_voltage ph(::gkusv_driver_interface::msg::UsvWaterSensor::_ph_type arg)
  {
    msg_.ph = std::move(arg);
    return Init_UsvWaterSensor_voltage(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

class Init_UsvWaterSensor_header
{
public:
  Init_UsvWaterSensor_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UsvWaterSensor_ph header(::gkusv_driver_interface::msg::UsvWaterSensor::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UsvWaterSensor_ph(msg_);
  }

private:
  ::gkusv_driver_interface::msg::UsvWaterSensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::msg::UsvWaterSensor>()
{
  return gkusv_driver_interface::msg::builder::Init_UsvWaterSensor_header();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__BUILDER_HPP_
