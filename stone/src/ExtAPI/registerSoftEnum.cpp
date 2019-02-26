#include "../custom_command.h"
#include "common.h"

namespace ExtAPI {
using namespace interface;

static void registerSoftEnumCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2 && info.Length() != 3) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("registerSoftEnum requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsArray()) {
    iso->ThrowException(Exception::TypeError(ToJS("registerSoftEnum requires (string, Array)")));
    return;
  }
  auto name = info[0] >> V8Str;
  auto arr  = Local<Array>(info[1]);
  std::vector<mcpe::string> vec;

  for (unsigned i = 0; i < arr->Length(); i++) {
    auto it = arr->Get(i);
    if (!it->IsString()) {
      iso->ThrowException(Exception::TypeError(ToJS("registerSoftEnum requires (string, string[])")));
      return;
    }
    vec.push_back(it >> V8Str);
  }

  registerCustomEnum(name, vec, info.Length() == 3 && info[2]->IsTrue());
}

static Register reg{ "registerComponent", "registerSoftEnum", &registerSoftEnumCallback };

} // namespace ExtAPI