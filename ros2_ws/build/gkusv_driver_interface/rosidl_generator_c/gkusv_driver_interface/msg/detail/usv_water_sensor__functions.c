// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice
#include "gkusv_driver_interface/msg/detail/usv_water_sensor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gkusv_driver_interface__msg__UsvWaterSensor__init(gkusv_driver_interface__msg__UsvWaterSensor * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gkusv_driver_interface__msg__UsvWaterSensor__fini(msg);
    return false;
  }
  // ph
  // voltage
  // temperature
  // salinity
  // pressure_mbar
  // conductivity
  return true;
}

void
gkusv_driver_interface__msg__UsvWaterSensor__fini(gkusv_driver_interface__msg__UsvWaterSensor * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ph
  // voltage
  // temperature
  // salinity
  // pressure_mbar
  // conductivity
}

bool
gkusv_driver_interface__msg__UsvWaterSensor__are_equal(const gkusv_driver_interface__msg__UsvWaterSensor * lhs, const gkusv_driver_interface__msg__UsvWaterSensor * rhs)
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
  // ph
  if (lhs->ph != rhs->ph) {
    return false;
  }
  // voltage
  if (lhs->voltage != rhs->voltage) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // salinity
  if (lhs->salinity != rhs->salinity) {
    return false;
  }
  // pressure_mbar
  if (lhs->pressure_mbar != rhs->pressure_mbar) {
    return false;
  }
  // conductivity
  if (lhs->conductivity != rhs->conductivity) {
    return false;
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvWaterSensor__copy(
  const gkusv_driver_interface__msg__UsvWaterSensor * input,
  gkusv_driver_interface__msg__UsvWaterSensor * output)
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
  // ph
  output->ph = input->ph;
  // voltage
  output->voltage = input->voltage;
  // temperature
  output->temperature = input->temperature;
  // salinity
  output->salinity = input->salinity;
  // pressure_mbar
  output->pressure_mbar = input->pressure_mbar;
  // conductivity
  output->conductivity = input->conductivity;
  return true;
}

gkusv_driver_interface__msg__UsvWaterSensor *
gkusv_driver_interface__msg__UsvWaterSensor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvWaterSensor * msg = (gkusv_driver_interface__msg__UsvWaterSensor *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvWaterSensor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkusv_driver_interface__msg__UsvWaterSensor));
  bool success = gkusv_driver_interface__msg__UsvWaterSensor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkusv_driver_interface__msg__UsvWaterSensor__destroy(gkusv_driver_interface__msg__UsvWaterSensor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkusv_driver_interface__msg__UsvWaterSensor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__init(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvWaterSensor * data = NULL;

  if (size) {
    data = (gkusv_driver_interface__msg__UsvWaterSensor *)allocator.zero_allocate(size, sizeof(gkusv_driver_interface__msg__UsvWaterSensor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkusv_driver_interface__msg__UsvWaterSensor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkusv_driver_interface__msg__UsvWaterSensor__fini(&data[i - 1]);
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
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__fini(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array)
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
      gkusv_driver_interface__msg__UsvWaterSensor__fini(&array->data[i]);
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

gkusv_driver_interface__msg__UsvWaterSensor__Sequence *
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array = (gkusv_driver_interface__msg__UsvWaterSensor__Sequence *)allocator.allocate(sizeof(gkusv_driver_interface__msg__UsvWaterSensor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkusv_driver_interface__msg__UsvWaterSensor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__destroy(gkusv_driver_interface__msg__UsvWaterSensor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkusv_driver_interface__msg__UsvWaterSensor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__are_equal(const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * lhs, const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvWaterSensor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkusv_driver_interface__msg__UsvWaterSensor__Sequence__copy(
  const gkusv_driver_interface__msg__UsvWaterSensor__Sequence * input,
  gkusv_driver_interface__msg__UsvWaterSensor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkusv_driver_interface__msg__UsvWaterSensor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkusv_driver_interface__msg__UsvWaterSensor * data =
      (gkusv_driver_interface__msg__UsvWaterSensor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkusv_driver_interface__msg__UsvWaterSensor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkusv_driver_interface__msg__UsvWaterSensor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkusv_driver_interface__msg__UsvWaterSensor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
