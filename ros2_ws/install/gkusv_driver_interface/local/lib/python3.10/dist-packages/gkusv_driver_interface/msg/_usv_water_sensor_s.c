// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gkusv_driver_interface:msg/UsvWaterSensor.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "gkusv_driver_interface/msg/detail/usv_water_sensor__struct.h"
#include "gkusv_driver_interface/msg/detail/usv_water_sensor__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool gkusv_driver_interface__msg__usv_water_sensor__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("gkusv_driver_interface.msg._usv_water_sensor.UsvWaterSensor", full_classname_dest, 59) == 0);
  }
  gkusv_driver_interface__msg__UsvWaterSensor * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // ph
    PyObject * field = PyObject_GetAttrString(_pymsg, "ph");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ph = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // salinity
    PyObject * field = PyObject_GetAttrString(_pymsg, "salinity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->salinity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pressure_mbar
    PyObject * field = PyObject_GetAttrString(_pymsg, "pressure_mbar");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pressure_mbar = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // conductivity
    PyObject * field = PyObject_GetAttrString(_pymsg, "conductivity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->conductivity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gkusv_driver_interface__msg__usv_water_sensor__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UsvWaterSensor */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gkusv_driver_interface.msg._usv_water_sensor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UsvWaterSensor");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gkusv_driver_interface__msg__UsvWaterSensor * ros_message = (gkusv_driver_interface__msg__UsvWaterSensor *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ph
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ph);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ph", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // salinity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->salinity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "salinity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pressure_mbar
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pressure_mbar);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pressure_mbar", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // conductivity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->conductivity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "conductivity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
