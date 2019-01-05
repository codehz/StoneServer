#pragma once

#include <interface/locator.hpp>
#include <minecraft/V8.h>

namespace v8 {

Local<String> operator""_v8(char const *str, size_t len) { return String::NewFromUtf8(interface::Locator<Isolate>(), str, kInternalized); }

} // namespace v8