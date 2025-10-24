// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkusv_driver_interface:msg/UsvControl.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__TRAITS_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkusv_driver_interface/msg/detail/usv_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace gkusv_driver_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const UsvControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: boatindex
  {
    out << "boatindex: ";
    rosidl_generator_traits::value_to_yaml(msg.boatindex, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UsvControl & msg,
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

  // member: boatindex
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "boatindex: ";
    rosidl_generator_traits::value_to_yaml(msg.boatindex, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UsvControl & msg, bool use_flow_style = false)
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
  const gkusv_driver_interface::msg::UsvControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkusv_driver_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkusv_driver_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkusv_driver_interface::msg::UsvControl & msg)
{
  return gkusv_driver_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkusv_driver_interface::msg::UsvControl>()
{
  return "gkusv_driver_interface::msg::UsvControl";
}

template<>
inline const char * name<gkusv_driver_interface::msg::UsvControl>()
{
  return "gkusv_driver_interface/msg/UsvControl";
}

template<>
struct has_fixed_size<gkusv_driver_interface::msg::UsvControl>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<gkusv_driver_interface::msg::UsvControl>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<gkusv_driver_interface::msg::UsvControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__TRAITS_HPP_
