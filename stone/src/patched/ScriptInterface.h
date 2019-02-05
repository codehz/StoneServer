#pragma once

#include <stone/operator.h>

#include <minecraft/ScriptApi.h>
#include <minecraft/V8.h>

namespace patched {
using namespace utils;

inline static const auto V8Isolate [[maybe_unused]] = StaticFieldAccessor<ScriptApi::V8CoreInterface, 0x48, v8::Isolate *>{};
inline static const auto V8Context [[maybe_unused]] = StaticFieldAccessor<ScriptApi::V8CoreInterface, 0x4C, v8::Persistent<v8::Context>>{};

}