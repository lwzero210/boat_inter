// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__TRAITS_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkusv_driver_interface/msg/detail/usv_gps__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace gkusv_driver_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const UsvGps & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: accuracy
  {
    out << "accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.accuracy, out);
    out << ", ";
  }

  // member: cs
  {
    out << "cs: ";
    rosidl_generator_traits::value_to_yaml(msg.cs, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UsvGps & msg,
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

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: accuracy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.accuracy, out);
    out << "\n";
  }

  // member: cs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cs: ";
    rosidl_generator_traits::value_to_yaml(msg.cs, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UsvGps & msg, bool use_flow_style = false)
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
  const gkusv_driver_interface::msg::UsvGps & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkusv_driver_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkusv_driver_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkusv_driver_interface::msg::UsvGps & msg)
{
  return gkusv_driver_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkusv_driver_interface::msg::UsvGps>()
{
  return "gkusv_driver_interface::msg::UsvGps";
}

template<>
inline const char * name<gkusv_driver_interface::msg::UsvGps>()
{
  return "gkusv_driver_interface/msg/UsvGps";
}

template<>
struct has_fixed_size<gkusv_driver_interface::msg::UsvGps>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<gkusv_driver_interface::msg::UsvGps>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<gkusv_driver_interface::msg::UsvGps>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__TRAITS_HPP_
