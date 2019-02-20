#pragma once

#include <interface/locator.hpp>
#include <minecraft/Tag.h>
#include <minecraft/V8.h>

#include "operators.h"

#include <array>
#include <type_traits>

#define ToJS(s) toJS(iso, s)

namespace v8 {

template <typename T> struct Convertable; // type, fromJS, toJS

template <typename T> auto fromJS(Isolate *iso, Local<typename Convertable<T>::type> src) { return Convertable<T>::fromJS(iso, src); }
template <typename T> auto toJS(Isolate *iso, T src) { return Convertable<T>::toJS(iso, src); }

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
template <> struct Convertable<char const *> {
  using type = String;
  static Local<type> toJS(Isolate *iso, char const *src) { return String::NewFromUtf8(iso, src); }
};
template <> struct Convertable<char *> {
  using type = String;
  static Local<type> toJS(Isolate *iso, char *src) { return String::NewFromUtf8(iso, src); }
};

template <> struct Convertable<Tag const &> {
  using type = Value;
  static Local<type> toJS(Isolate *iso, Tag const &tag);
};

template <> struct Convertable<CompoundTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, CompoundTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "compound"));
    auto xobj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "value"), xobj);
    for (auto &[k, v] : tag.value) xobj->Set(Convertable<std::string>::toJS(iso, k.std()), Convertable<Tag const &>::toJS(iso, *v));
    return obj;
  }
};

template <> struct Convertable<ListTag const &> {
  using type = Array;
  static Local<type> toJS(Isolate *iso, ListTag const &tag) {
    auto arr = Array::New(iso, tag.value.size());
    int i    = 0;
    for (auto &child : tag.value) arr->Set(i++, Convertable<Tag const &>::toJS(iso, *child));
    return arr;
  }
};
template <> struct Convertable<DoubleTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, DoubleTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "double"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<double>::toJS(iso, tag.value));
    return obj;
  }
};
template <> struct Convertable<StringTag const &> {
  using type = String;
  static Local<type> toJS(Isolate *iso, StringTag const &tag) { return Convertable<std::string>::toJS(iso, tag.value.std()); }
};
template <> struct Convertable<ShortTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, ShortTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "short"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<short>::toJS(iso, tag.value));
    return obj;
  }
};
template <> struct Convertable<Int64Tag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, Int64Tag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "int64"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<std::string>::toJS(iso, std::to_string(tag.value)));
    return obj;
  }
};
template <> struct Convertable<FloatTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, FloatTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "float"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<float>::toJS(iso, tag.value));
    return obj;
  }
};
template <> struct Convertable<IntTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, IntTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "int"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<int>::toJS(iso, tag.value));
    return obj;
  }
};
template <> struct Convertable<ByteTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, ByteTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "byte"));
    obj->Set(Convertable<char const *>::toJS(iso, "value"), Convertable<unsigned char>::toJS(iso, tag.value));
    return obj;
  }
};
template <> struct Convertable<IntArrayTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, IntArrayTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "int-array"));
    auto arr = ArrayBuffer::New(iso, tag.value.size());
    memcpy(arr->GetContents().Data(), tag.value.data(), tag.value.size());
    obj->Set(Convertable<char const *>::toJS(iso, "value"), arr);
    return obj;
  }
};
template <> struct Convertable<ByteArrayTag const &> {
  using type = Object;
  static Local<type> toJS(Isolate *iso, ByteArrayTag const &tag) {
    auto obj = Object::New(iso);
    obj->Set(Convertable<char const *>::toJS(iso, "type"), Convertable<char const *>::toJS(iso, "byte-array"));
    auto arr = ArrayBuffer::New(iso, tag.value.size());
    memcpy(arr->GetContents().Data(), tag.value.data(), tag.value.size());
    obj->Set(Convertable<char const *>::toJS(iso, "value"), arr);
    return obj;
  }
};
template <> struct Convertable<EndTag const &> {
  using type = Value;
  static Local<type> toJS(Isolate *iso, EndTag const &tag) {
    return Undefined(iso);
  }
};

#define CASE(T)                                                                                                                                      \
  if (*(void ***)&tag == T::vt + 2) return Convertable<T const &>::toJS(iso, (T const &)tag)

inline Local<Value> Convertable<Tag const &>::toJS(Isolate *iso, const Tag &tag) {
  CASE(CompoundTag);
  CASE(StringTag);
  CASE(ListTag);
  CASE(DoubleTag);
  CASE(ShortTag);
  CASE(Int64Tag);
  CASE(FloatTag);
  CASE(IntTag);
  CASE(ByteTag);
  CASE(IntArrayTag);
  CASE(ByteArrayTag);
  CASE(EndTag);
  printf("Cannot convert back: %p\n", *(void ***)&tag);
  return Undefined(iso);
}
#undef CASE

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
    for (size_t i = 0; i < length; i++) ret->Set(i, Convertable<T>::ToJS(src[i]));
    return ret;
  }
};

template <> struct Convertable<Actor *> {
  using type = Value;
  static Actor *fromJS(Isolate *iso, Local<type> obj) {
    using namespace interface;
    Actor *actor;
    Locator<MinecraftServerScriptEngine>()->helpGetActor(Persistent<Value>(iso, obj), actor);
    return actor;
  }
  static Local<type> toJS(Isolate *iso, Actor *src) {
    using namespace interface;
    if (!src) return Null(iso);
    v8::Persistent<v8::Value> pers;
    Locator<MinecraftServerScriptEngine>()->helpDefineActor(*src, pers);
    return pers.Get(iso);
  }
};

} // namespace v8