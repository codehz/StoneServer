#pragma once

#include <interface/locator.hpp>
#include <minecraft/V8.h>

#include "operators.h"

#include <array>
#include <type_traits>

namespace v8 {

template <typename T> struct Convertable; // type, fromJS, toJS

template <typename T> T fromJS(Isolate *iso, Local<typename Convertable<T>::type> src) { return Convertable<T>::fromJS(iso, src); }
template <typename T> Local<typename Convertable<T>::type> toJS(Isolate *iso, T src) { return Convertable<T>::toJS(iso, src); }

template <typename T> struct IntegralConvertable {
  using type = Integer;
  static T fromJS(Isolate *iso, Local<type> src) { return src->Value(); }
  static Local<type> toJS(Isolate *iso, T src) {
    if constexpr (std::is_signed_v<T>)
      return Integer::New(iso, src);
    else
      return Integer::NewFromUnsigned(iso, src);
  }
};

template <> struct Convertable<char> : IntegralConvertable<char> {};
template <> struct Convertable<unsigned char> : IntegralConvertable<unsigned char> {};
template <> struct Convertable<short> : IntegralConvertable<short> {};
template <> struct Convertable<unsigned short> : IntegralConvertable<unsigned short> {};
template <> struct Convertable<int> : IntegralConvertable<int> {};
template <> struct Convertable<unsigned int> : IntegralConvertable<unsigned int> {};

template <typename T> struct NumberConvertable {
  using type = Number;
  static T fromJS(Isolate *iso, Local<type> src) { return src->Value(); }
  static Local<type> toJS(Isolate *iso, T src) { return Number::New(iso, src); }
};

template <> struct Convertable<float> : NumberConvertable<float> {};
template <> struct Convertable<double> : NumberConvertable<double> {};

template <> struct Convertable<std::string> {
  using type = String;
  static std::string fromJS(Isolate *iso, Local<type> src) { return src >> V8Str; }
  static Local<type> toJS(Isolate *iso, std::string src) { return String::NewFromUtf8(iso, src.c_str()); }
};

template <typename T, std::size_t length> struct Convertable<std::array<T, length>> {
  using type = Array;
  static std::array<T, length> fromJS(Isolate *iso, Local<type> src) {
    if (src->Length() != length) return {};
    std::array<T, length> ret;
    for (size_t i = 0; i < length; i++) ret[i] = Convertable<T>::fromJS(iso, Convertable<T>::type::Cast(src->Get(i)));
    return ret;
  }
  static Local<type> toJS(Isolate *iso, std::array<T, length> src) {
    auto ret = Array::New(iso, length);
    for (size_t i = 0; i < length; i++) ret->Set(i, Convertable<T>::toJS(iso, src[i]));
    return ret;
  }
};

template <> struct Convertable<Actor *> {
  using type = Object;
  static Actor *fromJS(Isolate *iso, Local<type> obj) {
    using namespace interface;
    Actor *actor;
    Locator<MinecraftServerScriptEngine>()->helpGetActor(Persistent<Object>(iso, obj), actor);
    return actor;
  }
  static Local<type> toJS(Isolate *iso, Actor *src) {
    using namespace interface;
    if (!src) return Undefined(iso);
    v8::Persistent<v8::Object> pers;
    Locator<MinecraftServerScriptEngine>()->helpDefineEntity(*src, pers);
    return pers.Get(iso);
  }
};

} // namespace v8