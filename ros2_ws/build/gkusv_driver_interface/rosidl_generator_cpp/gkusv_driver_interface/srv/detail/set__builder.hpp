// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkusv_driver_interface:srv/Set.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__BUILDER_HPP_
#define GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkusv_driver_interface/srv/detail/set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkusv_driver_interface
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::srv::Set_Request>()
{
  return ::gkusv_driver_interface::srv::Set_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace gkusv_driver_interface


namespace gkusv_driver_interface
{

namespace srv
{

namespace builder
{

class Init_Set_Response_result
{
public:
  Init_Set_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gkusv_driver_interface::srv::Set_Response result(::gkusv_driver_interface::srv::Set_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkusv_driver_interface::srv::Set_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkusv_driver_interface::srv::Set_Response>()
{
  return gkusv_driver_interface::srv::builder::Init_Set_Response_result();
}

}  // namespace gkusv_driver_interface

#endif  // GKUSV_DRIVER_INTERFACE__SRV__DETAIL__SET__BUILDER_HPP_
