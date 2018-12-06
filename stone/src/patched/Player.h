#pragma once

#include <stone/field_access.h>
#include <minecraft/Player.h>
#include <minecraft/UUID.h>

namespace patched {
inline static const auto PlayerName = utils::FieldAccessor<Player, 0x1108, mcpe::string>{};
inline static const auto PlayerUUID = utils::FieldAccessor<Player, 0x1200, mce::UUID>{};
}
