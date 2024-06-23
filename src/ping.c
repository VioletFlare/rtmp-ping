#include <assert.h>
#include "../node_modules/node-api-headers/include/node_api.h"
#include "../lib/librtmp/rtmp.h"
#include <stdlib.h>

double RTMP_Ping(char* url) {
    RTMP* r = RTMP_Alloc();
    RTMP_SetupURL(r, url);
    RTMP_Init(r);
    RTMP_SendCtrl(r, 6, 0, 0);
    return 20;
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

  double dping = RTMP_Ping(url);

  napi_value ping;
  status = napi_create_double(env, dping, &ping);
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