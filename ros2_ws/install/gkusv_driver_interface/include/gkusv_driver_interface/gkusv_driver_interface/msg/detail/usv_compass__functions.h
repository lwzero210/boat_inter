// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gkusv_driver_interface:msg/UsvCompass.idl
// generated code does not contain a copyright notice

#ifndef GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__FUNCTIONS_H_
#define GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gkusv_driver_interface/msg/rosidl_generator_c__visibility_control.h"

#include "gkusv_driver_interface/msg/detail/usv_compass__struct.h"

/// Initialize msg/UsvCompass message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gkusv_driver_interface__msg__UsvCompass
 * )) before or use
 * gkusv_driver_interface__msg__UsvCompass__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvCompass__init(gkusv_driver_interface__msg__UsvCompass * msg);

/// Finalize msg/UsvCompass message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvCompass__fini(gkusv_driver_interface__msg__UsvCompass * msg);

/// Create msg/UsvCompass message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gkusv_driver_interface__msg__UsvCompass__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvCompass *
gkusv_driver_interface__msg__UsvCompass__create();

/// Destroy msg/UsvCompass message.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvCompass__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvCompass__destroy(gkusv_driver_interface__msg__UsvCompass * msg);

/// Check for msg/UsvCompass message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvCompass__are_equal(const gkusv_driver_interface__msg__UsvCompass * lhs, const gkusv_driver_interface__msg__UsvCompass * rhs);

/// Copy a msg/UsvCompass message.
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
gkusv_driver_interface__msg__UsvCompass__copy(
  const gkusv_driver_interface__msg__UsvCompass * input,
  gkusv_driver_interface__msg__UsvCompass * output);

/// Initialize array of msg/UsvCompass messages.
/**
 * It allocates the memory for the number of elements and calls
 * gkusv_driver_interface__msg__UsvCompass__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvCompass__Sequence__init(gkusv_driver_interface__msg__UsvCompass__Sequence * array, size_t size);

/// Finalize array of msg/UsvCompass messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvCompass__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvCompass__Sequence__fini(gkusv_driver_interface__msg__UsvCompass__Sequence * array);

/// Create array of msg/UsvCompass messages.
/**
 * It allocates the memory for the array and calls
 * gkusv_driver_interface__msg__UsvCompass__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
gkusv_driver_interface__msg__UsvCompass__Sequence *
gkusv_driver_interface__msg__UsvCompass__Sequence__create(size_t size);

/// Destroy array of msg/UsvCompass messages.
/**
 * It calls
 * gkusv_driver_interface__msg__UsvCompass__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
void
gkusv_driver_interface__msg__UsvCompass__Sequence__destroy(gkusv_driver_interface__msg__UsvCompass__Sequence * array);

/// Check for msg/UsvCompass message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkusv_driver_interface
bool
gkusv_driver_interface__msg__UsvCompass__Sequence__are_equal(const gkusv_driver_interface__msg__UsvCompass__Sequence * lhs, const gkusv_driver_interface__msg__UsvCompass__Sequence * rhs);

/// Copy an array of msg/UsvCompass messages.
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
gkusv_driver_interface__msg__UsvCompass__Sequence__copy(
  const gkusv_driver_interface__msg__UsvCompass__Sequence * input,
  gkusv_driver_interface__msg__UsvCompass__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GKUSV_DRIVER_INTERFACE__MSG__DETAIL__USV_COMPASS__FUNCTIONS_H_
