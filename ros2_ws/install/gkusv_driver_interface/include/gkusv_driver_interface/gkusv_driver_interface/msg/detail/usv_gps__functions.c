// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkusv_driver_interface:msg/UsvGps.idl
// generated code does not contain a copyright notice
#include "gkusv_driver_interface/msg/detail/usv_gps__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gkusv_driver_interface__msg__UsvGps__init(gkusv_driver_interface__msg__UsvGps * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gkusv_driver_interface__msg__UsvGps__fini(msg);
    return false;
  }
  // status
  // latitude
  // longitude
  // height
  // accuracy
  // cs
  return true;
}

void
gkusv_driver_interface__msg__UsvGps__fini(gkusv_driver_interface__msg__UsvGps * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // status
  // latitude
  // longitude
  // height
  // accuracy
  // cs
}

bool
gkusv_driver_interface__msg__UsvGps__are_equal(const gkusv_driver_interface__msg__UsvGps * lhs, const gkusv_driver_interface__msg__UsvGps * rhs)
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
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // accuracy
  if (lhs->accuracy != rhs->accuracy) {
    return false;
  }
  // cs
  if (lhs->cs != rhs->cs) {
    return false;
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvGps__copy(
  const gkusv_driver_interface__msg__UsvGps * input,
  gkusv_driver_interface__msg__UsvGps * output)
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
  // status
  output->status = input->status;
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // height
  output->height = input->height;
  // accuracy
  output->accuracy = input->accuracy;
  // cs
  output->cs = input->cs;
  return true;
}

gkusv_driver_interface__msg__UsvGps *
gkusv_driver_interface__msg__UsvGps__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvGps * msg = (gkusv_driver_interface__msg__UsvGps *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvGps), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkusv_driver_interface__msg__UsvGps));
  bool success = gkusv_driver_interface__msg__UsvGps__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkusv_driver_interface__msg__UsvGps__destroy(gkusv_driver_interface__msg__UsvGps * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkusv_driver_interface__msg__UsvGps__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkusv_driver_interface__msg__UsvGps__Sequence__init(gkusv_driver_interface__msg__UsvGps__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvGps * data = NULL;

  if (size) {
    data = (gkusv_driver_interface__msg__UsvGps *)allocator.zero_allocate(size, sizeof(gkusv_driver_interface__msg__UsvGps), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkusv_driver_interface__msg__UsvGps__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkusv_driver_interface__msg__UsvGps__fini(&data[i - 1]);
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
gkusv_driver_interface__msg__UsvGps__Sequence__fini(gkusv_driver_interface__msg__UsvGps__Sequence * array)
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
      gkusv_driver_interface__msg__UsvGps__fini(&array->data[i]);
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

gkusv_driver_interface__msg__UsvGps__Sequence *
gkusv_driver_interface__msg__UsvGps__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvGps__Sequence * array = (gkusv_driver_interface__msg__UsvGps__Sequence *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvGps__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkusv_driver_interface__msg__UsvGps__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkusv_driver_interface__msg__UsvGps__Sequence__destroy(gkusv_driver_interface__msg__UsvGps__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkusv_driver_interface__msg__UsvGps__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkusv_driver_interface__msg__UsvGps__Sequence__are_equal(const gkusv_driver_interface__msg__UsvGps__Sequence * lhs, const gkusv_driver_interface__msg__UsvGps__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvGps__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvGps__Sequence__copy(
  const gkusv_driver_interface__msg__UsvGps__Sequence * input,
  gkusv_driver_interface__msg__UsvGps__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkusv_driver_interface__msg__UsvGps);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkusv_driver_interface__msg__UsvGps * data =
      (gkusv_driver_interface__msg__UsvGps *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkusv_driver_interface__msg__UsvGps__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkusv_driver_interface__msg__UsvGps__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvGps__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
