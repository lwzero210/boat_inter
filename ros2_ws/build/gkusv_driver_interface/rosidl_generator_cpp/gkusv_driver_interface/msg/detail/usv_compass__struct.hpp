// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:msg/UsvCompass.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gkusv_driver_interface__msg__UsvCompass __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__msg__UsvCompass __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UsvCompass_
{
  using Type = UsvCompass_<ContainerAllocator>;

  explicit UsvCompass_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heading = 0.0f;
    }
  }

  explicit UsvCompass_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heading = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _heading_type =
    float;
  _heading_type heading;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvCompass
    std::shared_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvCompass
    std::shared_ptr<gkusv_driver_interface::msg::UsvCompass_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UsvCompass_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    return true;
  }
  bool operator!=(const UsvCompass_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UsvCompass_

// alias to use template instance with default allocator
using UsvCompass =
  gkusv_driver_interface::msg::UsvCompass_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__STRUCT_HPP_
