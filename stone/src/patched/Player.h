#pragma once

#include <minecraft/Player.h>
#include <minecraft/UUID.h>
#include <stone/field_access.h>

namespace patched {
inline static const auto PlayerName = utils::FieldAccessor<Player, 0x1138, mcpe::string>{};
inline static const auto PlayerUUID = utils::FieldAccessor<Player, 0x1230, mce::UUID>{};
} // namespace patched
