
#include <cstdlib>
#include <cstring>
#include <RTIMULib.h>

#include <pthread.h>
#include <errno.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "jerryscript.h"
#include "src_js_binding.h"

RTIMUSettings* settings_ = new RTIMUSettings();

void RTHumidity_js_destructor(void* ptr) { }

static const jerry_object_native_info_t RTHumidity_type_info = {
    .free_cb = RTHumidity_js_destructor
};

static const jerry_object_native_info_t RTHumidity_type_info_static = {
  .free_cb = NULL
};


bool jerry_value_is_RTHumidity (jerry_value_t jval)
{
  if (!jerry_value_is_object (jval))
  {
    return false;
  }

  void* ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(jval, &ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &RTHumidity_type_info && type_ptr != &RTHumidity_type_info_static))
  {
    return false;
  }

  return true;
}


jerry_value_t RTHumidity_js_creator (RTHumidity* native_ptr)
{
  jerry_value_t js_obj = jerry_create_object();

  return js_obj;
}


// external function for record constructor
jerry_value_t RTHumidity_js_constructor (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  RTHumidity* native_ptr;
  switch (args_cnt) {

    case 0: {
      native_ptr = RTHumidity::createHumidity(settings_);
      native_ptr->humidityInit();
      break;
    }

     default: {
       char const *msg = "Wrong argument count for RTHumidity constructor.";
       return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
     }
  }

  jerry_value_t ret_val = RTHumidity_js_creator(native_ptr);
  jerry_set_object_native_pointer(ret_val, native_ptr, &RTHumidity_type_info);
  return ret_val;
}


void RTPressure_js_destructor(void* ptr) { }

static const jerry_object_native_info_t RTPressure_type_info = {
    .free_cb = RTPressure_js_destructor
};

static const jerry_object_native_info_t RTPressure_type_info_static = {
  .free_cb = NULL
};


bool jerry_value_is_RTPressure (jerry_value_t jval)
{
  if (!jerry_value_is_object (jval))
  {
    return false;
  }

  void* ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(jval, &ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &RTPressure_type_info && type_ptr != &RTPressure_type_info_static))
  {
    return false;
  }

  return true;
}


jerry_value_t RTPressure_js_creator (RTPressure* native_ptr)
{
  jerry_value_t js_obj = jerry_create_object();

  return js_obj;
}


// external function for record constructor
jerry_value_t RTPressure_js_constructor (const jerry_value_t function_obj,
                                         const jerry_value_t this_val,
                                         const jerry_value_t args_p[],
                                         const jerry_length_t args_cnt)
{
  RTPressure* native_ptr;
  switch (args_cnt) {

    case 0: {
      native_ptr = RTPressure::createPressure(settings_);
      native_ptr->pressureInit();
      break;
    }

     default: {
       char const *msg = "Wrong argument count for RTPressure constructor.";
       return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
     }
  }

  jerry_value_t ret_val = RTPressure_js_creator(native_ptr);
  jerry_set_object_native_pointer(ret_val, native_ptr, &RTPressure_type_info);
  return ret_val;
}


void SenseHAT_js_destructor(void* ptr) { }

static const jerry_object_native_info_t SenseHAT_type_info = {
    .free_cb = SenseHAT_js_destructor
};

static const jerry_object_native_info_t SenseHAT_type_info_static = {
  .free_cb = NULL
};


bool jerry_value_is_SenseHAT (jerry_value_t jval)
{
  if (!jerry_value_is_object (jval))
  {
    return false;
  }

  void* ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(jval, &ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static))
  {
    return false;
  }

  return true;
}


// external function for record method
jerry_value_t SenseHAT_set_pixel_handler (const jerry_value_t function_obj,
                                          const jerry_value_t this_val,
                                          const jerry_value_t args_p[],
                                          const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  int result;
  switch (args_cnt) {

    case 5: {

      if (jerry_value_is_number (args_p[0]) && jerry_value_is_number (args_p[1]) && jerry_value_is_number (args_p[2]) && jerry_value_is_number (args_p[3]) && jerry_value_is_number (args_p[4]))
      {

  // create an integer / floating point number from a jerry_value_t
  int arg_0 = (int)jerry_get_number_value (args_p[0]);

  // create an integer / floating point number from a jerry_value_t
  int arg_1 = (int)jerry_get_number_value (args_p[1]);

  // create an integer / floating point number from a jerry_value_t
  uint8_t arg_2 = (uint8_t)jerry_get_number_value (args_p[2]);

  // create an integer / floating point number from a jerry_value_t
  uint8_t arg_3 = (uint8_t)jerry_get_number_value (args_p[3]);

  // create an integer / floating point number from a jerry_value_t
  uint8_t arg_4 = (uint8_t)jerry_get_number_value (args_p[4]);

        result = native_ptr->set_pixel(arg_0, arg_1, arg_2, arg_3, arg_4);

        break;
      }

    char const *msg = "Wrong argument type for SenseHAT.set_pixel().";
    return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.set_pixel().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_get_temperature_from_humidity_handler (const jerry_value_t function_obj,
                                                              const jerry_value_t this_val,
                                                              const jerry_value_t args_p[],
                                                              const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, &SenseHAT_type_info);

  if (!has_ptr) { // || (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  double result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->get_temperature_from_humidity();
      fprintf(stderr, "Humidty native: %f\n", result);
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.get_temperature_from_humidity().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_get_humidity_handler (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  // bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, &SenseHAT_type_info);


  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  double result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->get_humidity();
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.get_humidity().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_get_pressure_handler (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  double result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->get_pressure();
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.get_pressure().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_blank_handler (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  int result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->blank();
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.blank().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_get_temperature_handler (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  double result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->get_temperature();
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.get_temperature().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


// external function for record method
jerry_value_t SenseHAT_get_temperature_from_pressure_handler (const jerry_value_t function_obj,
                                             const jerry_value_t this_val,
                                             const jerry_value_t args_p[],
                                             const jerry_length_t args_cnt)
{
  void* void_ptr;
  const jerry_object_native_info_t* type_ptr;
  bool has_ptr = jerry_get_object_native_pointer(this_val, &void_ptr, type_ptr);

  if (!has_ptr ||
      (type_ptr != &SenseHAT_type_info && type_ptr != &SenseHAT_type_info_static)) {
    char const *msg = "Failed to get native SenseHAT pointer";
    return jerry_create_error(JERRY_ERROR_TYPE, (const jerry_char_t *)msg);
  }

  SenseHAT* native_ptr = (SenseHAT*)(void_ptr);

  double result;
  switch (args_cnt) {

    case 0: {
      result = native_ptr->get_temperature_from_pressure();
      break;
    }

    default: {
      char const *msg = "Wrong argument count for SenseHAT.get_temperature_from_pressure().";
      return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
    }
  }


  jerry_value_t ret_val = jerry_create_number (result);

  return ret_val;
}


jerry_value_t SenseHAT_js_creator (SenseHAT* native_ptr)
{
  jerry_value_t js_obj = jerry_create_object();

  // set record method as a property to the object
  jerry_value_t set_pixel_name = jerry_create_string ((const jerry_char_t*)"set_pixel");
  jerry_value_t set_pixel_func = jerry_create_external_function (SenseHAT_set_pixel_handler);
  jerry_value_t set_pixel_ret = jerry_set_property (js_obj, set_pixel_name, set_pixel_func);
  jerry_release_value (set_pixel_name);
  jerry_release_value (set_pixel_func);
  jerry_release_value (set_pixel_ret);


  // set record method as a property to the object
  jerry_value_t get_temperature_from_humidity_name = jerry_create_string ((const jerry_char_t*)"get_temperature_from_humidity");
  jerry_value_t get_temperature_from_humidity_func = jerry_create_external_function (SenseHAT_get_temperature_from_humidity_handler);
  jerry_value_t get_temperature_from_humidity_ret = jerry_set_property (js_obj, get_temperature_from_humidity_name, get_temperature_from_humidity_func);
  jerry_release_value (get_temperature_from_humidity_name);
  jerry_release_value (get_temperature_from_humidity_func);
  jerry_release_value (get_temperature_from_humidity_ret);


  // set record method as a property to the object
  jerry_value_t get_humidity_name = jerry_create_string ((const jerry_char_t*)"get_humidity");
  jerry_value_t get_humidity_func = jerry_create_external_function (SenseHAT_get_humidity_handler);
  jerry_value_t get_humidity_ret = jerry_set_property (js_obj, get_humidity_name, get_humidity_func);
  jerry_release_value (get_humidity_name);
  jerry_release_value (get_humidity_func);
  jerry_release_value (get_humidity_ret);


  // set record method as a property to the object
  jerry_value_t get_pressure_name = jerry_create_string ((const jerry_char_t*)"get_pressure");
  jerry_value_t get_pressure_func = jerry_create_external_function (SenseHAT_get_pressure_handler);
  jerry_value_t get_pressure_ret = jerry_set_property (js_obj, get_pressure_name, get_pressure_func);
  jerry_release_value (get_pressure_name);
  jerry_release_value (get_pressure_func);
  jerry_release_value (get_pressure_ret);


  // set record method as a property to the object
  jerry_value_t blank_name = jerry_create_string ((const jerry_char_t*)"blank");
  jerry_value_t blank_func = jerry_create_external_function (SenseHAT_blank_handler);
  jerry_value_t blank_ret = jerry_set_property (js_obj, blank_name, blank_func);
  jerry_release_value (blank_name);
  jerry_release_value (blank_func);
  jerry_release_value (blank_ret);


  // set record method as a property to the object
  jerry_value_t get_temperature_name = jerry_create_string ((const jerry_char_t*)"get_temperature");
  jerry_value_t get_temperature_func = jerry_create_external_function (SenseHAT_get_temperature_handler);
  jerry_value_t get_temperature_ret = jerry_set_property (js_obj, get_temperature_name, get_temperature_func);
  jerry_release_value (get_temperature_name);
  jerry_release_value (get_temperature_func);
  jerry_release_value (get_temperature_ret);


  // set record method as a property to the object
  jerry_value_t get_temperature_from_pressure_name = jerry_create_string ((const jerry_char_t*)"get_temperature_from_pressure");
  jerry_value_t get_temperature_from_pressure_func = jerry_create_external_function (SenseHAT_get_temperature_from_pressure_handler);
  jerry_value_t get_temperature_from_pressure_ret = jerry_set_property (js_obj, get_temperature_from_pressure_name, get_temperature_from_pressure_func);
  jerry_release_value (get_temperature_from_pressure_name);
  jerry_release_value (get_temperature_from_pressure_func);
  jerry_release_value (get_temperature_from_pressure_ret);

  return js_obj;
}


// external function for record constructor
jerry_value_t SenseHAT_js_constructor (const jerry_value_t function_obj,
                                       const jerry_value_t this_val,
                                       const jerry_value_t args_p[],
                                       const jerry_length_t args_cnt)
{
  SenseHAT* native_ptr;
  switch (args_cnt) {

    case 0: {
      native_ptr = new SenseHAT();
      break;
    }

     default: {
       char const *msg = "Wrong argument count for SenseHAT constructor.";
       return jerry_create_error (JERRY_ERROR_TYPE, (const jerry_char_t*)msg);
     }
  }

  jerry_value_t ret_val = SenseHAT_js_creator(native_ptr);
  jerry_set_object_native_pointer(ret_val, native_ptr, &SenseHAT_type_info);
  return ret_val;
}


// init function for the module
extern "C" jerry_value_t Init_src()
{
  jerry_value_t object = jerry_create_object();


  // set a constructor as a property to the module object
  jerry_value_t RTHumidity_name = jerry_create_string ((const jerry_char_t*)"RTHumidity");
  jerry_value_t RTHumidity_func = jerry_create_external_function (RTHumidity_js_constructor);
  jerry_value_t RTHumidity_ret = jerry_set_property (object, RTHumidity_name, RTHumidity_func);
  jerry_release_value (RTHumidity_name);
  jerry_release_value (RTHumidity_func);
  jerry_release_value (RTHumidity_ret);


  // set a constructor as a property to the module object
  jerry_value_t RTPressure_name = jerry_create_string ((const jerry_char_t*)"RTPressure");
  jerry_value_t RTPressure_func = jerry_create_external_function (RTPressure_js_constructor);
  jerry_value_t RTPressure_ret = jerry_set_property (object, RTPressure_name, RTPressure_func);
  jerry_release_value (RTPressure_name);
  jerry_release_value (RTPressure_func);
  jerry_release_value (RTPressure_ret);


  // set a constructor as a property to the module object
  jerry_value_t SenseHAT_name = jerry_create_string ((const jerry_char_t*)"SenseHAT");
  jerry_value_t SenseHAT_func = jerry_create_external_function (SenseHAT_js_constructor);
  jerry_value_t SenseHAT_ret = jerry_set_property (object, SenseHAT_name, SenseHAT_func);
  jerry_release_value (SenseHAT_name);
  jerry_release_value (SenseHAT_func);
  jerry_release_value (SenseHAT_ret);

  return object;
}
