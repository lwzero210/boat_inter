// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gkusv_driver_interface:msg/UsvCamera.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gkusv_driver_interface/msg/detail/usv_camera__rosidl_typesupport_introspection_c.h"
#include "gkusv_driver_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gkusv_driver_interface/msg/detail/usv_camera__functions.h"
#include "gkusv_driver_interface/msg/detail/usv_camera__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gkusv_driver_interface__msg__UsvCamera__init(message_memory);
}

void gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_fini_function(void * message_memory)
{
  gkusv_driver_interface__msg__UsvCamera__fini(message_memory);
}

size_t gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__size_function__UsvCamera__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_const_function__UsvCamera__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_function__UsvCamera__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__fetch_function__UsvCamera__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_const_function__UsvCamera__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__assign_function__UsvCamera__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_function__UsvCamera__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__resize_function__UsvCamera__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "encoding",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, encoding),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_bigendian",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, is_bigendian),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkusv_driver_interface__msg__UsvCamera, data),  // bytes offset in struct
    NULL,  // default value
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__size_function__UsvCamera__data,  // size() function pointer
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_const_function__UsvCamera__data,  // get_const(index) function pointer
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__get_function__UsvCamera__data,  // get(index) function pointer
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__fetch_function__UsvCamera__data,  // fetch(index, &value) function pointer
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__assign_function__UsvCamera__data,  // assign(index, value) function pointer
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__resize_function__UsvCamera__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_members = {
  "gkusv_driver_interface__msg",  // message namespace
  "UsvCamera",  // message name
  7,  // number of fields
  sizeof(gkusv_driver_interface__msg__UsvCamera),
  gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_member_array,  // message members
  gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_init_function,  // function to initialize message memory (memory has to be allocated)
  gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_type_support_handle = {
  0,
  &gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gkusv_driver_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gkusv_driver_interface, msg, UsvCamera)() {
  gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_type_support_handle.typesupport_identifier) {
    gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gkusv_driver_interface__msg__UsvCamera__rosidl_typesupport_introspection_c__UsvCamera_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
