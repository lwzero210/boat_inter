// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_H_

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

/// Struct defined in msg/UsvGps in the package gkusv_driver_interface.
typedef struct gkusv_driver_interface__msg__UsvGps
{
  std_msgs__msg__Header header;
  int32_t status;
  double latitude;
  double longitude;
  double height;
  double accuracy;
  double cs;
} gkusv_driver_interface__msg__UsvGps;

// Struct for a sequence of gkusv_driver_interface__msg__UsvGps.
typedef struct gkusv_driver_interface__msg__UsvGps__Sequence
{
  gkusv_driver_interface__msg__UsvGps * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkusv_driver_interface__msg__UsvGps__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__STRUCT_H_
