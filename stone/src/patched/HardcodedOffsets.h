#pragma once

#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Minecraft.h>
#include <minecraft/NetworkIdentifier.h>
#include <minecraft/Player.h>
#include <minecraft/ServerInstance.h>
#include <minecraft/ServerNetworkHandler.h>
#include <minecraft/UUID.h>
#include <stone/operator.h>

#include <tuple>

#include <interface/locator.hpp>

namespace patched {
using namespace utils;
using namespace interface;
using namespace std;

inline static const auto PlayerName [[maybe_unused]]      = StaticFieldAccessor<Player, 0x1138, mcpe::string>{};
inline static const auto PlayerUUID [[maybe_unused]]      = StaticFieldAccessor<Player, 0x1230, mce::UUID>{};
inline static const auto PlayerNetworkID [[maybe_unused]] = StaticFieldAccessor<Player, 0x1188, NetworkIdentifier>{};
inline static const auto PlayerXUID [[maybe_unused]] =
    makeOperator(+[](Player const &player) { return ExtendedCertificate::getXuid(*player.getCertificate()); });
inline static const auto PlayerBasicInfo [[maybe_unused]] = makeOperator(
    +[](Player const &player) { return make_tuple(PlayerName[player].std(), PlayerUUID[player].asString().std(), PlayerXUID(player).std()); });
inline static const auto PlayerPos [[maybe_unused]] = makeOperator(&Player::getPos);
inline static const auto PlayerRot [[maybe_unused]] = makeOperator(&Player::getRotation);
inline static const auto PlayerLvl [[maybe_unused]] = makeOperator(&Player::getLevelProgress);
inline static const auto PlayerStats [[maybe_unused]] =
    makeOperator(+[](Player const &player) { return Locator<ServerNetworkHandler>()->getPeerForUser(PlayerNetworkID[player])->getNetworkStatus(); });

inline static const auto MinecraftFromServerInstance [[maybe_unused]] = StaticFieldAccessor<ServerInstance, 0x10, Minecraft *>{};

} // namespace patched
