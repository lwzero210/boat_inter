// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_HPP_

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
# define DEPRECATED__gkusv_driver_interface__msg__UsvWaterSensor __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__msg__UsvWaterSensor __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UsvWaterSensor_
{
  using Type = UsvWaterSensor_<ContainerAllocator>;

  explicit UsvWaterSensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ph = 0.0f;
      this->voltage = 0.0f;
      this->temperature = 0.0f;
      this->salinity = 0.0f;
      this->pressure_mbar = 0.0f;
      this->conductivity = 0.0f;
    }
  }

  explicit UsvWaterSensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ph = 0.0f;
      this->voltage = 0.0f;
      this->temperature = 0.0f;
      this->salinity = 0.0f;
      this->pressure_mbar = 0.0f;
      this->conductivity = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ph_type =
    float;
  _ph_type ph;
  using _voltage_type =
    float;
  _voltage_type voltage;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _salinity_type =
    float;
  _salinity_type salinity;
  using _pressure_mbar_type =
    float;
  _pressure_mbar_type pressure_mbar;
  using _conductivity_type =
    float;
  _conductivity_type conductivity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ph(
    const float & _arg)
  {
    this->ph = _arg;
    return *this;
  }
  Type & set__voltage(
    const float & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__salinity(
    const float & _arg)
  {
    this->salinity = _arg;
    return *this;
  }
  Type & set__pressure_mbar(
    const float & _arg)
  {
    this->pressure_mbar = _arg;
    return *this;
  }
  Type & set__conductivity(
    const float & _arg)
  {
    this->conductivity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvWaterSensor
    std::shared_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__msg__UsvWaterSensor
    std::shared_ptr<gkusv_driver_interface::msg::UsvWaterSensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UsvWaterSensor_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ph != other.ph) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->salinity != other.salinity) {
      return false;
    }
    if (this->pressure_mbar != other.pressure_mbar) {
      return false;
    }
    if (this->conductivity != other.conductivity) {
      return false;
    }
    return true;
  }
  bool operator!=(const UsvWaterSensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UsvWaterSensor_

// alias to use template instance with default allocator
using UsvWaterSensor =
  gkusv_driver_interface::msg::UsvWaterSensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_HPP_
