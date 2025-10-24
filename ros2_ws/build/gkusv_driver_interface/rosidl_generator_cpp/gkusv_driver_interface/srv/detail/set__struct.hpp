// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkusv_driver_interface:srv/Set.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__STRUCT_HPP_
#define GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gkusv_driver_interface__srv__Set_Request __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__srv__Set_Request __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Set_Request_
{
  using Type = Set_Request_<ContainerAllocator>;

  explicit Set_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Set_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__srv__Set_Request
    std::shared_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__srv__Set_Request
    std::shared_ptr<gkusv_driver_interface::srv::Set_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Set_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Set_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Set_Request_

// alias to use template instance with default allocator
using Set_Request =
  gkusv_driver_interface::srv::Set_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gkusv_driver_interface


#ifndef _WIN32
# define DEPRECATED__gkusv_driver_interface__srv__Set_Response __attribute__((deprecated))
#else
# define DEPRECATED__gkusv_driver_interface__srv__Set_Response __declspec(deprecated)
#endif

namespace gkusv_driver_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Set_Response_
{
  using Type = Set_Response_<ContainerAllocator>;

  explicit Set_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit Set_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkusv_driver_interface__srv__Set_Response
    std::shared_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkusv_driver_interface__srv__Set_Response
    std::shared_ptr<gkusv_driver_interface::srv::Set_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Set_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Set_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Set_Response_

// alias to use template instance with default allocator
using Set_Response =
  gkusv_driver_interface::srv::Set_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gkusv_driver_interface

namespace gkusv_driver_interface
{

namespace srv
{

struct Set
{
  using Request = gkusv_driver_interface::srv::Set_Request;
  using Response = gkusv_driver_interface::srv::Set_Response;
};

}  // namespace srv

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__STRUCT_HPP_
