// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkusv_driver_interface:msg/UsvImu.idl
// generated code does not contain a copyright notice
#include "gkusv_driver_interface/msg/detail/usv_imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `euler_angles`
// Member `acceleration`
// Member `magnetic_field`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
gkusv_driver_interface__msg__UsvImu__init(gkusv_driver_interface__msg__UsvImu * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gkusv_driver_interface__msg__UsvImu__fini(msg);
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__init(&msg->euler_angles)) {
    gkusv_driver_interface__msg__UsvImu__fini(msg);
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    gkusv_driver_interface__msg__UsvImu__fini(msg);
    return false;
  }
  // magnetic_field
  if (!geometry_msgs__msg__Vector3__init(&msg->magnetic_field)) {
    gkusv_driver_interface__msg__UsvImu__fini(msg);
    return false;
  }
  // temp
  return true;
}

void
gkusv_driver_interface__msg__UsvImu__fini(gkusv_driver_interface__msg__UsvImu * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // euler_angles
  geometry_msgs__msg__Vector3__fini(&msg->euler_angles);
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // magnetic_field
  geometry_msgs__msg__Vector3__fini(&msg->magnetic_field);
  // temp
}

bool
gkusv_driver_interface__msg__UsvImu__are_equal(const gkusv_driver_interface__msg__UsvImu * lhs, const gkusv_driver_interface__msg__UsvImu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->euler_angles), &(rhs->euler_angles)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // magnetic_field
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->magnetic_field), &(rhs->magnetic_field)))
  {
    return false;
  }
  // temp
  if (lhs->temp != rhs->temp) {
    return false;
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvImu__copy(
  const gkusv_driver_interface__msg__UsvImu * input,
  gkusv_driver_interface__msg__UsvImu * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->euler_angles), &(output->euler_angles)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // magnetic_field
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->magnetic_field), &(output->magnetic_field)))
  {
    return false;
  }
  // temp
  output->temp = input->temp;
  return true;
}

gkusv_driver_interface__msg__UsvImu *
gkusv_driver_interface__msg__UsvImu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvImu * msg = (gkusv_driver_interface__msg__UsvImu *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvImu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkusv_driver_interface__msg__UsvImu));
  bool success = gkusv_driver_interface__msg__UsvImu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkusv_driver_interface__msg__UsvImu__destroy(gkusv_driver_interface__msg__UsvImu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkusv_driver_interface__msg__UsvImu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkusv_driver_interface__msg__UsvImu__Sequence__init(gkusv_driver_interface__msg__UsvImu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvImu * data = NULL;

  if (size) {
    data = (gkusv_driver_interface__msg__UsvImu *)allocator.zero_allocate(size, sizeof(gkusv_driver_interface__msg__UsvImu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkusv_driver_interface__msg__UsvImu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkusv_driver_interface__msg__UsvImu__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gkusv_driver_interface__msg__UsvImu__Sequence__fini(gkusv_driver_interface__msg__UsvImu__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gkusv_driver_interface__msg__UsvImu__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gkusv_driver_interface__msg__UsvImu__Sequence *
gkusv_driver_interface__msg__UsvImu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvImu__Sequence * array = (gkusv_driver_interface__msg__UsvImu__Sequence *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvImu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkusv_driver_interface__msg__UsvImu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkusv_driver_interface__msg__UsvImu__Sequence__destroy(gkusv_driver_interface__msg__UsvImu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkusv_driver_interface__msg__UsvImu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkusv_driver_interface__msg__UsvImu__Sequence__are_equal(const gkusv_driver_interface__msg__UsvImu__Sequence * lhs, const gkusv_driver_interface__msg__UsvImu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvImu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvImu__Sequence__copy(
  const gkusv_driver_interface__msg__UsvImu__Sequence * input,
  gkusv_driver_interface__msg__UsvImu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkusv_driver_interface__msg__UsvImu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkusv_driver_interface__msg__UsvImu * data =
      (gkusv_driver_interface__msg__UsvImu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkusv_driver_interface__msg__UsvImu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkusv_driver_interface__msg__UsvImu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvImu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
