// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_H_

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

/// Struct defined in msg/UsvWaterSensor in the package gkusv_driver_interface.
/**
  * UsvWaterSensor.msg
  * 수질 센서 데이터 메시지
 */
typedef struct gkusv_driver_interface__msg__UsvWaterSensor
{
  std_msgs__msg__Header header;
  /// 센서 값들 (읽기 실패 시 -1.0)
  /// pH 값
  float ph;
  /// 전압 (mV)
  float voltage;
  /// 수온 (°C)
  float temperature;
  /// 염분도 (PSU)
  float salinity;
  /// 압력 (mbar)
  float pressure_mbar;
  /// 전도도 (μS/c)
  float conductivity;
} gkusv_driver_interface__msg__UsvWaterSensor;

// Struct for a sequence of gkusv_driver_interface__msg__UsvWaterSensor.
typedef struct gkusv_driver_interface__msg__UsvWaterSensor__Sequence
{
  gkusv_driver_interface__msg__UsvWaterSensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkusv_driver_interface__msg__UsvWaterSensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__STRUCT_H_
