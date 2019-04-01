#include "../patched.h"

#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/ServerInstance.h>

#include <stone/server_hook.h>

#include <interface/locator.hpp>
#include <interface/player_list.h>

namespace {
using namespace interface;

SInstanceHook(void, _ZN27ServerLevelEventCoordinator20sendLevelAddedPlayerER5LevelR6Player, ServerLevelEventCoordinator, Level *level,
              Player *player) {
  using namespace interface;
  Locator<PlayerList>()->onPlayerAdded(*player);
  original(this, level, player);
}

SHook(void, _ZN12ServerPlayerD2Ev, Player *player) {
  Locator<PlayerList>()->onPlayerRemoved(*player);
  original(player);
}

static patched::details::RegisterPatchInit pinit([] { Locator<PlayerList>().generate<>(); });

} // namespace