#pragma once

#include <interface/locator.hpp>
#include <interface/player_list.h>
#include <minecraft/NetworkIdentifier.h>
#include <minecraft/Player.h>
#include <minecraft/ScriptApi.h>
#include <minecraft/UUID.h>
#include <minecraft/V8.h>
#include <stone/operator.h>

#include <codecvt>
#include <locale>
#include <tuple>

#include "patched/Player.h"

template <class Facet> struct deletable_facet : Facet {
  template <class... Args>
  deletable_facet(Args &&... args)
      : Facet(std::forward<Args>(args)...) {}
  ~deletable_facet() {}
};

inline static const auto UUIDStr       = utils::makeOperator(&mce::UUID::asString);
inline static const auto StdStr        = utils::makeOperator(&mcpe::string::std);
inline static const auto V8Str         = utils::makeOperator(+[](v8::Local<v8::String> const &str) {
  unsigned short buffer[str->Length() + 1];
  str->Write(buffer);
  std::wstring_convert<deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> cvt;
  return cvt.to_bytes((char16_t *)buffer);
});
inline static const auto CStr          = utils::makeOperator(&mcpe::string::c_str);
inline static const auto StdCStr       = utils::makeOperator(&std::string::c_str);
inline static const auto FloatToDouble = utils::makeOperator(+[](float const &x) -> double { return x; });
template <typename T> inline static constexpr auto EqualsTo(T target) {
  return utils::makeOperator<std::function<bool(T const &source)>>([&](auto source) { return source == target; });
}
inline static const auto FindPlayerByNetworkID = utils::makeOperator(+[](NetworkIdentifier const &id) -> Player & {
  using namespace interface;
  for (auto pplayer : Locator<PlayerList>()->set) {
    auto &player = *pplayer;
    if (patched::PlayerNetworkID[player] == id) { return player; }
  }
  throw "not found";
});