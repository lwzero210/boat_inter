// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkusv_driver_interface:msg/UsvImu.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'euler_angles'
// Member 'acceleration'
// Member 'magnetic_field'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/UsvImu in the package gkusv_driver_interface.
typedef struct gkusv_driver_interface__msg__UsvImu
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Vector3 euler_angles;
  geometry_msgs__msg__Vector3 acceleration;
  geometry_msgs__msg__Vector3 magnetic_field;
  float temp;
} gkusv_driver_interface__msg__UsvImu;

// Struct for a sequence of gkusv_driver_interface__msg__UsvImu.
typedef struct gkusv_driver_interface__msg__UsvImu__Sequence
{
  gkusv_driver_interface__msg__UsvImu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkusv_driver_interface__msg__UsvImu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_IMU__STRUCT_H_
