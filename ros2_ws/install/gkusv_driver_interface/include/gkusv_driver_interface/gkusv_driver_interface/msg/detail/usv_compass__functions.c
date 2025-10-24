// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkusv_driver_interface:msg/UsvCompass.idl
// generated code does not contain a copyright notice
#include "gkusv_driver_interface/msg/detail/usv_compass__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gkusv_driver_interface__msg__UsvCompass__init(gkusv_driver_interface__msg__UsvCompass * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gkusv_driver_interface__msg__UsvCompass__fini(msg);
    return false;
  }
  // heading
  return true;
}

void
gkusv_driver_interface__msg__UsvCompass__fini(gkusv_driver_interface__msg__UsvCompass * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // heading
}

bool
gkusv_driver_interface__msg__UsvCompass__are_equal(const gkusv_driver_interface__msg__UsvCompass * lhs, const gkusv_driver_interface__msg__UsvCompass * rhs)
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
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvCompass__copy(
  const gkusv_driver_interface__msg__UsvCompass * input,
  gkusv_driver_interface__msg__UsvCompass * output)
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
  // heading
  output->heading = input->heading;
  return true;
}

gkusv_driver_interface__msg__UsvCompass *
gkusv_driver_interface__msg__UsvCompass__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvCompass * msg = (gkusv_driver_interface__msg__UsvCompass *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvCompass), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkusv_driver_interface__msg__UsvCompass));
  bool success = gkusv_driver_interface__msg__UsvCompass__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkusv_driver_interface__msg__UsvCompass__destroy(gkusv_driver_interface__msg__UsvCompass * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkusv_driver_interface__msg__UsvCompass__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkusv_driver_interface__msg__UsvCompass__Sequence__init(gkusv_driver_interface__msg__UsvCompass__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvCompass * data = NULL;

  if (size) {
    data = (gkusv_driver_interface__msg__UsvCompass *)allocator.zero_allocate(size, sizeof(gkusv_driver_interface__msg__UsvCompass), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkusv_driver_interface__msg__UsvCompass__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkusv_driver_interface__msg__UsvCompass__fini(&data[i - 1]);
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
gkusv_driver_interface__msg__UsvCompass__Sequence__fini(gkusv_driver_interface__msg__UsvCompass__Sequence * array)
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
      gkusv_driver_interface__msg__UsvCompass__fini(&array->data[i]);
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

gkusv_driver_interface__msg__UsvCompass__Sequence *
gkusv_driver_interface__msg__UsvCompass__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvCompass__Sequence * array = (gkusv_driver_interface__msg__UsvCompass__Sequence *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvCompass__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkusv_driver_interface__msg__UsvCompass__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkusv_driver_interface__msg__UsvCompass__Sequence__destroy(gkusv_driver_interface__msg__UsvCompass__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkusv_driver_interface__msg__UsvCompass__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkusv_driver_interface__msg__UsvCompass__Sequence__are_equal(const gkusv_driver_interface__msg__UsvCompass__Sequence * lhs, const gkusv_driver_interface__msg__UsvCompass__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvCompass__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvCompass__Sequence__copy(
  const gkusv_driver_interface__msg__UsvCompass__Sequence * input,
  gkusv_driver_interface__msg__UsvCompass__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkusv_driver_interface__msg__UsvCompass);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkusv_driver_interface__msg__UsvCompass * data =
      (gkusv_driver_interface__msg__UsvCompass *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkusv_driver_interface__msg__UsvCompass__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkusv_driver_interface__msg__UsvCompass__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvCompass__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
