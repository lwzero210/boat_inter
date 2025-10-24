// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_HPP_

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
# define DEPRECATED__gkusv_driver_interface__msg__UsvGps __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__msg__UsvGps __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UsvGps_
{
  using Type = UsvGps_<ContainerAllocator>;

  explicit UsvGps_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->height = 0.0;
      this->accuracy = 0.0;
      this->cs = 0.0;
    }
  }

  explicit UsvGps_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->height = 0.0;
      this->accuracy = 0.0;
      this->cs = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _status_type =
    int32_t;
  _status_type status;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _height_type =
    double;
  _height_type height;
  using _accuracy_type =
    double;
  _accuracy_type accuracy;
  using _cs_type =
    double;
  _cs_type cs;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__accuracy(
    const double & _arg)
  {
    this->accuracy = _arg;
    return *this;
  }
  Type & set__cs(
    const double & _arg)
  {
    this->cs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvGps
    std::shared_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvGps
    std::shared_ptr<gkusv_driver_interface::msg::UsvGps_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UsvGps_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->accuracy != other.accuracy) {
      return false;
    }
    if (this->cs != other.cs) {
      return false;
    }
    return true;
  }
  bool operator!=(const UsvGps_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UsvGps_

// alias to use template instance with default allocator
using UsvGps =
  gkusv_driver_interface::msg::UsvGps_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_HPP_
