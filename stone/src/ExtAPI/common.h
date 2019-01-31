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
  static std::map<std::string, std::set<std::tuple<char const *, void (*)(FunctionCallbackInfo<Value> const &)>>> registry;
  inline Register(char const *injection_point, char const *name, void (*func)(FunctionCallbackInfo<Value> const &)) {
    registry[injection_point].insert({ name, func });
  }
};

} // namespace ExtAPI