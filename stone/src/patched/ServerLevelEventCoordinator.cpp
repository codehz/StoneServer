#include "../patched.h"

#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>
#include <minecraft/ServerInstance.h>

#include <stone/server_hook.h>

#include <interface/locator.hpp>
#include <interface/player_list.h>

namespace {

SHook(void, _ZN16EventCoordinatorI18LevelEventListenerE12processEventESt8functionIF11EventResultPS0_EE) {}

SHook(void, _ZN27ServerLevelEventCoordinator17sendLevelSaveDataER5LevelR11CompoundTag, void *self, Level *level, void *tag) {
  Log::info("Minecraft", "Save level data");
}

SHook(void, _ZN27ServerLevelEventCoordinator20sendLevelAddedPlayerER5LevelR6Player, void *self, Level *, Player *player) {
  using namespace interface;
  Locator<PlayerList>()->onPlayerAdded(player);
}

SHook(void, _ZN27ServerLevelEventCoordinator22sendLevelRemovedPlayerER5LevelR6Player, void *self, Level *, Player *player) {
  using namespace interface;
  Locator<PlayerList>()->onPlayerRemoved(player);
}

static patched::details::RegisterPatchInit pinit([] {
  using namespace interface;
  Locator<PlayerList>().generate<>();
  Locator<Level>()->_setServerLevelEventCoordinator(std::make_unique<ServerLevelEventCoordinator>());
});

} // namespace