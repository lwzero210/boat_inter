// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__TRAITS_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkusv_driver_interface/msg/detail/usv_water_sensor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace gkusv_driver_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const UsvWaterSensor & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: ph
  {
    out << "ph: ";
    rosidl_generator_traits::value_to_yaml(msg.ph, out);
    out << ", ";
  }

  // member: voltage
  {
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: salinity
  {
    out << "salinity: ";
    rosidl_generator_traits::value_to_yaml(msg.salinity, out);
    out << ", ";
  }

  // member: pressure_mbar
  {
    out << "pressure_mbar: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure_mbar, out);
    out << ", ";
  }

  // member: conductivity
  {
    out << "conductivity: ";
    rosidl_generator_traits::value_to_yaml(msg.conductivity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UsvWaterSensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: ph
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ph: ";
    rosidl_generator_traits::value_to_yaml(msg.ph, out);
    out << "\n";
  }

  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: salinity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "salinity: ";
    rosidl_generator_traits::value_to_yaml(msg.salinity, out);
    out << "\n";
  }

  // member: pressure_mbar
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pressure_mbar: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure_mbar, out);
    out << "\n";
  }

  // member: conductivity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "conductivity: ";
    rosidl_generator_traits::value_to_yaml(msg.conductivity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UsvWaterSensor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gkusv_driver_interface

namespace rosidl_generator_traits
{

[[deprecated("use gkusv_driver_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gkusv_driver_interface::msg::UsvWaterSensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkusv_driver_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkusv_driver_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkusv_driver_interface::msg::UsvWaterSensor & msg)
{
  return gkusv_driver_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkusv_driver_interface::msg::UsvWaterSensor>()
{
  return "gkusv_driver_interface::msg::UsvWaterSensor";
}

template<>
inline const char * name<gkusv_driver_interface::msg::UsvWaterSensor>()
{
  return "gkusv_driver_interface/msg/UsvWaterSensor";
}

template<>
struct has_fixed_size<gkusv_driver_interface::msg::UsvWaterSensor>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<gkusv_driver_interface::msg::UsvWaterSensor>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<gkusv_driver_interface::msg::UsvWaterSensor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__TRAITS_HPP_
