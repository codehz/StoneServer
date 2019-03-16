#include "common.h"

constexpr auto API_LEVEL = 1;

namespace GlobalAPI {

static void check_api_level(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 1 or !info[0]->IsNumber()) iso->ThrowException(Exception::TypeError(ToJS("usage: checkApiLevel(level: number)")));
  if (fromJS<int>(iso, info[0]) != API_LEVEL) iso->ThrowException(Exception::TypeError(ToJS("API version mismatch")));
  return;
}

static Register reg([](Local<ObjectTemplate> &obj, Isolate *iso) {
  auto tmp_check = FunctionTemplate::New(iso, check_api_level, 1);
  tmp_check->SetClassName(ToJS("SQLite3"));
  obj->Set(ToJS("checkApiLevel"), tmp_check);
});
} // namespace GlobalAPI