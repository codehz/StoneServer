#include <interface/blacklist.h>
#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

#include "operators.h"
#include "patched.h"
#include "patched/Player.h"
#include "services.h"
#include "whitelist_mgr.hpp"

#include <log.h>
#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>

void initDependencies() {
  using namespace interface;
  using namespace patched;

  Locator<ServerInstance>() >> FieldRef(&ServerInstance::minecraft);
  Locator<Minecraft>() >> MethodGet(&Minecraft::getCommands);
  Locator<MinecraftCommands>() >> MethodGet(&MinecraftCommands::getRegistry);
  Locator<Minecraft>() >> MethodGet(&Minecraft::getLevel);
  Locator<PlayerList>() >> [](auto &list) {
    Log::info("PlayerList", "Initialized");
    list.onPlayerAdded >> [](auto &player) {
      Locator<PlayerList>()->set.insert(&player);
      Log::info("PlayerList", "Player %s joined", (player >> PlayerName).c_str());
    };
    list.onPlayerRemoved >> [](auto &player) {
      Locator<PlayerList>()->set.erase(&player);
      Log::info("PlayerList", "Player %s left", (player >> PlayerName).c_str());
    };
    auto updateDBus = [](auto &) {
    };
    list.onPlayerAdded >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
    };
    list.onPlayerRemoved >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
    };
    list.onPlayerAdded >> updateDBus;
    list.onPlayerRemoved >> updateDBus;
  };
  Locator<Chat>() >> [](Chat &chat) {
    using namespace std::placeholders;
    chat.onPlayerChat >> [&](auto &player, auto &msg) {
      Log::info("Chat", "<%s> %s", player >> PlayerName >> CStr, msg >> CStr);
    };
    chat.onChat >> [&](auto &sender, auto &msg) {
      Log::info("Chat", "[%s] %s", sender >> CStr, msg >> CStr);
    };
  };
}
