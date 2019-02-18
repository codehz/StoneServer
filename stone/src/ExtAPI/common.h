#pragma once

#include <minecraft/Player.h>
#include <minecraft/V8.h>

#include "../operators.h"
#include "../patched.h"
#include "../v8_utils.hpp"
#include "log.h"

#include <map>
#include <set>
#include <string>

namespace ExtAPI {
using namespace v8;

struct Register {
  static std::map<std::string, std::set<std::tuple<char const *, v8::FunctionCallback>>> registry;
  static std::set<void (*)(Isolate *, Local<Context> &)> injecteds;
  inline Register(char const *injection_point, char const *name, v8::FunctionCallback func) { registry[injection_point].insert({ name, func }); }
  inline Register(char const *injection_point, char const *name, v8::FunctionCallback func,
                  void (*injected)(Isolate *, Local<Context> &)) {
    registry[injection_point].insert({ name, func });
    injecteds.emplace(injected);
  }
};

} // namespace ExtAPI