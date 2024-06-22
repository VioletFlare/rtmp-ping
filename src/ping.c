#include "lib/librtmp/rtmp.h"

#include <assert.h>
#include <node_api.h>

static napi_value Ping(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value roundtriptime;
  status = napi_create_string_utf8(env, "world", 5, &roundtriptime);
  assert(status == napi_ok);
  return world;
}

#define DECLARE_NAPI_METHOD(name, func)                                        \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor addDescriptor = DECLARE_NAPI_METHOD("ping", ping);
  status = napi_define_properties(env, exports, 1, &addDescriptor);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)