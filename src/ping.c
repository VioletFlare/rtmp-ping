#include <assert.h>
#include <node_api.h>
#include "../lib/librtmp/rtmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int64_t get_timestamp_in_us() {
  struct timespec tms;

    /* The C11 way */
    /* if (! timespec_get(&tms, TIME_UTC)) { */

    /* POSIX.1-2008 way */
    if (clock_gettime(CLOCK_REALTIME,&tms)) {
        return -1;
    }
    /* seconds, multiplied with 1 million */
    int64_t micros = tms.tv_sec * 1000000;
    /* Add full microseconds */
    micros += tms.tv_nsec/1000;
    /* round up if necessary */
    if (tms.tv_nsec % 1000 >= 500) {
        ++micros;
    }
    
    return micros;
}

// Returns the ping in microseconds.

int64_t RTMP_Ping(char* url) {
    int64_t ping = -1;
    RTMP* r = RTMP_Alloc();
    RTMP_Init(r);
    RTMP_SetupURL(r, url);
    
    int64_t timestamp_before_connected = get_timestamp_in_us();
    
    RTMP_Connect(r, NULL);

    if (RTMP_IsConnected(r)) {
      int64_t timestamp_after_connected = get_timestamp_in_us();
      ping = timestamp_after_connected - timestamp_before_connected;
      RTMP_Close(r);
    }

    return ping;
}

static napi_value Ping(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  napi_value args[1];
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  if (argc < 1) {
    napi_throw_type_error(env, NULL, "Wrong number of arguments.");
    return NULL;
  }

  if (argc <= 0) {
    napi_throw_type_error(env, NULL, "You must provide the rtmp stream URL.");
    return NULL;
  }

  napi_valuetype valuetype0;
  status = napi_typeof(env, args[0], &valuetype0);
  assert(status == napi_ok);

  if (valuetype0 != napi_string) {
    napi_throw_type_error(env, NULL, "The parameter provided, which should be a rtmp URL must be a string.");
    return NULL;
  }

  size_t str_size;
  size_t str_size_read;
  napi_get_value_string_utf8(env, args[0], NULL, 0, &str_size);
  assert(status == napi_ok);
  char* url;
  url = (char*)calloc(str_size + 1, sizeof(char));
  str_size = str_size + 1;
  napi_get_value_string_utf8(env, args[0], url, str_size, &str_size_read);
  assert(status == napi_ok);

  int64_t rtmp_ping = RTMP_Ping(url);

  napi_value ping;
  status = napi_create_bigint_int64(env, rtmp_ping, &ping);
  assert(status == napi_ok);

  return ping;
}

#define DECLARE_NAPI_METHOD(name, func)                                        \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor addDescriptor = DECLARE_NAPI_METHOD("ping", Ping);
  status = napi_define_properties(env, exports, 1, &addDescriptor);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)