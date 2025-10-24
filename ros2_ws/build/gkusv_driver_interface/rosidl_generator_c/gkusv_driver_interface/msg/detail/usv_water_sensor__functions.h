// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__FUNCTIONS_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gkusv_driver_interface/msg/rosidl_generator_c__visibility_control.h"

#include "gkusv_driver_interface/msg/detail/usv_water_sensor__struct.h"

/// Initialize msg/UsvWaterSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gkusv_driver_interface__msg__UsvWaterSensor
 * )) before or use
 * gkusv_driver_interface__msg__UsvWaterSensor__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__init(gkusv_driver_interface__msg__UsvWaterSensor * msg);

/// Finalize msg/UsvWaterSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvWaterSensor__fini(gkusv_driver_interface__msg__UsvWaterSensor * msg);

/// Create msg/UsvWaterSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gkusv_driver_interface__msg__UsvWaterSensor__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvWaterSensor *
gkusv_driver_interface__msg__UsvWaterSensor__create();

/// Destroy msg/UsvWaterSensor message.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvWaterSensor__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvWaterSensor__destroy(gkusv_driver_interface__msg__UsvWaterSensor * msg);

/// Check for msg/UsvWaterSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__are_equal(const gkusv_driver_interface__msg__UsvWaterSensor * lhs, const gkusv_driver_interface__msg__UsvWaterSensor * rhs);

/// Copy a msg/UsvWaterSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__copy(
  const gkusv_driver_interface__msg__UsvWaterSensor * input,
  gkusv_driver_interface__msg__UsvWaterSensor * output);

/// Initialize array of msg/UsvWaterSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * gkusv_driver_interface__msg__UsvWaterSensor__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__init(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array, size_t size);

/// Finalize array of msg/UsvWaterSensor messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvWaterSensor__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__fini(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array);

/// Create array of msg/UsvWaterSensor messages.
/**
 * It allocates the memory for the array and calls
 * gkusv_driver_interface__msg__UsvWaterSensor__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvWaterSensor__Sequence *
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__create(size_t size);

/// Destroy array of msg/UsvWaterSensor messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvWaterSensor__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__destroy(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array);

/// Check for msg/UsvWaterSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__are_equal(const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * lhs, const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * rhs);

/// Copy an array of msg/UsvWaterSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__copy(
  const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * input,
  gkusv_driver_interface__msg__UsvWaterSensor__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_WATER_SENSOR__FUNCTIONS_H_
