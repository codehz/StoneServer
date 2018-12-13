#pragma once

#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Player.h>
#include <minecraft/UUID.h>
#include <stone/operator.h>

#include <tuple>

namespace patched {
using namespace utils;
using namespace std;

inline static const auto PlayerName = StaticFieldAccessor<Player, 0x1138, mcpe::string>{};
inline static const auto PlayerUUID = StaticFieldAccessor<Player, 0x1230, mce::UUID>{};
inline static const auto PlayerXUID = makeOperator(+[](Player const &player) { return ExtendedCertificate::getXuid(*player.getCertificate()); });
inline static const auto PlayerBasicInfo =
    makeOperator(+[](Player const &player) { return make_tuple(PlayerName[player], PlayerUUID[player], PlayerXUID(player)); });
inline static const auto PlayerPos = makeOperator(&Player::getPos);
inline static const auto PlayerRot = makeOperator(&Player::getRotation);
inline static const auto PlayerLvl = makeOperator(&Player::getLevelProgress);
} // namespace patched
