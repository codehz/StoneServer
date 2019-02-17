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

namespace GlobalAPI {
using namespace v8;

struct Register {
  static std::vector<void (*)(Local<Object> &, Isolate *, Local<Context> &)> registry;
  inline Register(void (*func)(Local<Object> &, Isolate *, Local<Context> &)) { registry.emplace_back(func); }
};

} // namespace GlobalAPI