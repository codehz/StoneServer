#pragma once

#include <minecraft/Blacklist.h>
#include <minecraft/ExtendedCertificate.h>
#include <minecraft/ItemInstance.h>
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

#define OFF(name) inline static const auto name [[maybe_unused]]

OFF(PlayerName)        = StaticFieldAccessor<Player, 0x115c, mcpe::string>{};
OFF(PlayerUUID)        = StaticFieldAccessor<Player, 0x1254, mce::UUID>{};
OFF(PlayerNetworkID)   = StaticFieldAccessor<Player, 0x11ac, NetworkIdentifier>{};
OFF(PlayerXUID)        = makeOperator(+[](Player const &player) { return ExtendedCertificate::getXuid(*player.getCertificate()); });
OFF(PlayerBasicInfo)   = makeOperator(+[](Player const &player) {
  return make_tuple(PlayerName[player].std(), PlayerUUID[player].asString().std(), PlayerXUID(player).std());
});
OFF(PlayerPos)         = makeOperator(&Player::getPos);
OFF(PlayerRot)         = makeOperator(&Player::getRotation);
OFF(PlayerLvl)         = makeOperator(&Player::getLevelProgress);
OFF(PlayerStats)       = makeOperator(+[](Player const &player) {
  return Locator<ServerNetworkHandler>()->getPeerForUser(PlayerNetworkID[player])->getNetworkStatus();
});
OFF(ItemInstanceCount) = StaticFieldAccessor<ItemInstance, 0xe, char>{};
OFF(ItemStackCount)    = StaticFieldAccessor<ItemStack, 0xe, char>{};

OFF(MinecraftFromServerInstance) = StaticFieldAccessor<ServerInstance, 0x10, Minecraft *>{};

OFF(BlacklistFromNetworkHandler) = StaticFieldAccessor<ServerNetworkHandler, 0x40, ::Blacklist>{};

} // namespace patched
