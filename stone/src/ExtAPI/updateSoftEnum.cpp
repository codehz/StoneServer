#include "../custom_command.h"
#include "common.h"

namespace ExtAPI {
using namespace interface;

static void updateSoftEnumCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("updateSoftEnum requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsArray()) {
    iso->ThrowException(Exception::TypeError(ToJS("updateSoftEnum requires (string, Array)")));
    return;
  }
  auto name = info[0] >> V8Str;
  auto arr  = Local<Array>(info[1]);
  std::vector<mcpe::string> vec;

  for (unsigned i = 0; i < arr->Length(); i++) {
    auto it = arr->Get(i);
    if (!it->IsString()) {
      iso->ThrowException(Exception::TypeError(ToJS("updateSoftEnum requires (string, string[])")));
      return;
    }
    vec.push_back(it >> V8Str);
  }

  updateCustomEnum(name, vec);
}

static Register reg{ "registerComponent", "updateSoftEnum", &updateSoftEnumCallback };

} // namespace ExtAPI