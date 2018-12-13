#pragma once

#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Player.h>
#include <minecraft/UUID.h>
#include <stone/field_access.h>

#include <tuple>

namespace patched {
inline static const auto PlayerName = utils::FieldAccessor<Player, 0x1138, mcpe::string>{};
inline static const auto PlayerUUID = utils::FieldAccessor<Player, 0x1230, mce::UUID>{};
inline static const auto PlayerXUID =
    utils::makeFieldIndirectAccessor(+[](Player const &player) { return ExtendedCertificate::getXuid(*player.getCertificate()); });
inline static const auto PlayerBasicInfo =
    utils::makeFieldIndirectAccessor(+[](Player const &player) { return std::make_tuple(PlayerName[player], PlayerUUID[player], PlayerXUID(player)); });
} // namespace patched
