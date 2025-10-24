// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:msg/UsvControl.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__STRUCT_HPP_

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
# define DEPRECATED__gkusv_driver_interface__msg__UsvControl __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__msg__UsvControl __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UsvControl_
{
  using Type = UsvControl_<ContainerAllocator>;

  explicit UsvControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->boatindex = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit UsvControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->boatindex = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _boatindex_type =
    int32_t;
  _boatindex_type boatindex;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__boatindex(
    const int32_t & _arg)
  {
    this->boatindex = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvControl
    std::shared_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvControl
    std::shared_ptr<gkusv_driver_interface::msg::UsvControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UsvControl_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->boatindex != other.boatindex) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const UsvControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UsvControl_

// alias to use template instance with default allocator
using UsvControl =
  gkusv_driver_interface::msg::UsvControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_CONTROL__STRUCT_HPP_
