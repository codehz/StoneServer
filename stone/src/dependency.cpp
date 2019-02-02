#include <interface/blacklist.h>
#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

#include <stone-api/Blacklist.h>
#include <stone-api/Chat.h>
#include <stone-api/Core.h>

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
  using namespace api;

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
    auto updateDBus = [](auto &) {};
    list.onPlayerAdded >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      PlayerInfo temp         = { name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr };
      Locator<CoreService<ServerSide>>()->players.set(name >> StdStr, temp);
      Locator<CoreService<ServerSide>>()->online_players += temp;
    };
    list.onPlayerRemoved >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      Locator<CoreService<ServerSide>>()->online_players -= { name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr };
    };
    Locator<CoreService<ServerSide>>()->online_players.clear();
    list.onPlayerAdded >> updateDBus;
    list.onPlayerRemoved >> updateDBus;
  };
  Locator<Chat>() >> [](Chat &chat) {
    using namespace std::placeholders;
    auto &service = Locator<ChatService<ServerSide>>();
    chat.onPlayerChat >> [&](auto &player, auto &msg) {
      Log::info("Chat", "<%s> %s", player >> PlayerName >> CStr, msg >> CStr);
      service->recv << NormalMessage{ player >> PlayerName >> StdStr, msg >> StdStr };
    };
    chat.onChat >> [&](auto &sender, auto &msg) {
      Log::info("Chat", "[%s] %s", sender >> CStr, msg >> CStr);
      service->recv << NormalMessage{ sender >> StdStr, msg >> StdStr };
    };
    service->send >> [&](auto msg) {
      auto [sender, content] = msg;
      chat.sendChat(sender, content);
    };
    service->raw >> std::bind(&Chat::sendAnnouncement, &chat, _1);
  };
  Locator<Blacklist>() >> [](Blacklist &list) {
    // auto &service = Locator<BlacklistService<ServerSide>>();
    // service->add >> [&](auto arg) {
    //   auto [type, content] = arg;
    //   // if (type == "uuid")
    // }
  };
}
