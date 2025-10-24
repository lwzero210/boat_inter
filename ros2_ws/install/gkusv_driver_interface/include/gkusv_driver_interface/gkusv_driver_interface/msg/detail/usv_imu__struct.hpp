// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:msg/UsvImu.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_HPP_

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
// Member 'euler_angles'
// Member 'acceleration'
// Member 'magnetic_field'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gkusv_driver_interface__msg__UsvImu __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__msg__UsvImu __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UsvImu_
{
  using Type = UsvImu_<ContainerAllocator>;

  explicit UsvImu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    euler_angles(_init),
    acceleration(_init),
    magnetic_field(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0.0f;
    }
  }

  explicit UsvImu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    euler_angles(_alloc, _init),
    acceleration(_alloc, _init),
    magnetic_field(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _euler_angles_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _euler_angles_type euler_angles;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _magnetic_field_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _magnetic_field_type magnetic_field;
  using _temp_type =
    float;
  _temp_type temp;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__euler_angles(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->euler_angles = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__magnetic_field(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->magnetic_field = _arg;
    return *this;
  }
  Type & set__temp(
    const float & _arg)
  {
    this->temp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvImu
    std::shared_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvImu
    std::shared_ptr<gkusv_driver_interface::msg::UsvImu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UsvImu_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->euler_angles != other.euler_angles) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->magnetic_field != other.magnetic_field) {
      return false;
    }
    if (this->temp != other.temp) {
      return false;
    }
    return true;
  }
  bool operator!=(const UsvImu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UsvImu_

// alias to use template instance with default allocator
using UsvImu =
  gkusv_driver_interface::msg::UsvImu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_HPP_
