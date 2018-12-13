#pragma once

#include <interface/locator.hpp>
#include <interface/player_list.h>
#include <minecraft/NetworkIdentifier.h>
#include <minecraft/Player.h>
#include <minecraft/UUID.h>
#include <stone/operator.h>

#include <tuple>

#include "patched/Player.h"

inline static const auto UUIDStr       = utils::makeOperator(&mce::UUID::asString);
inline static const auto StdStr        = utils::makeOperator(&mcpe::string::std);
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