// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__FUNCTIONS_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gkusv_driver_interface/msg/rosidl_generator_c__visibility_control.h"

#include "gkusv_driver_interface/msg/detail/usv_gps__struct.h"

/// Initialize msg/UsvGps message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gkusv_driver_interface__msg__UsvGps
 * )) before or use
 * gkusv_driver_interface__msg__UsvGps__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvGps__init(gkusv_driver_interface__msg__UsvGps * msg);

/// Finalize msg/UsvGps message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvGps__fini(gkusv_driver_interface__msg__UsvGps * msg);

/// Create msg/UsvGps message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gkusv_driver_interface__msg__UsvGps__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvGps *
gkusv_driver_interface__msg__UsvGps__create();

/// Destroy msg/UsvGps message.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvGps__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvGps__destroy(gkusv_driver_interface__msg__UsvGps * msg);

/// Check for msg/UsvGps message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvGps__are_equal(const gkusv_driver_interface__msg__UsvGps * lhs, const gkusv_driver_interface__msg__UsvGps * rhs);

/// Copy a msg/UsvGps message.
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
gkusv_driver_interface__msg__UsvGps__copy(
  const gkusv_driver_interface__msg__UsvGps * input,
  gkusv_driver_interface__msg__UsvGps * output);

/// Initialize array of msg/UsvGps messages.
/**
 * It allocates the memory for the number of elements and calls
 * gkusv_driver_interface__msg__UsvGps__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvGps__Sequence__init(gkusv_driver_interface__msg__UsvGps__Sequence * array, size_t size);

/// Finalize array of msg/UsvGps messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvGps__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvGps__Sequence__fini(gkusv_driver_interface__msg__UsvGps__Sequence * array);

/// Create array of msg/UsvGps messages.
/**
 * It allocates the memory for the array and calls
 * gkusv_driver_interface__msg__UsvGps__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvGps__Sequence *
gkusv_driver_interface__msg__UsvGps__Sequence__create(size_t size);

/// Destroy array of msg/UsvGps messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvGps__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvGps__Sequence__destroy(gkusv_driver_interface__msg__UsvGps__Sequence * array);

/// Check for msg/UsvGps message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvGps__Sequence__are_equal(const gkusv_driver_interface__msg__UsvGps__Sequence * lhs, const gkusv_driver_interface__msg__UsvGps__Sequence * rhs);

/// Copy an array of msg/UsvGps messages.
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
gkusv_driver_interface__msg__UsvGps__Sequence__copy(
  const gkusv_driver_interface__msg__UsvGps__Sequence * input,
  gkusv_driver_interface__msg__UsvGps__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_GPS__FUNCTIONS_H_
