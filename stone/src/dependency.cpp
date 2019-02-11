#include <interface/blacklist.h>
#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

#include <stone-api/Blacklist.h>
#include <stone-api/Chat.h>
#include <stone-api/Core.h>

#include "operators.h"
#include "patched.h"
#include "patched/HardcodedOffsets.h"
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

  Locator<ServerInstance>() >> [](ServerInstance &instance) { Locator<Minecraft>() = MinecraftFromServerInstance(instance); };
  Locator<Minecraft>() >> MethodGet(&Minecraft::getCommands);
  Locator<MinecraftCommands>() >> MethodGet(&MinecraftCommands::getRegistry);
  Locator<PlayerList>() >> [](auto &list) {
    Log::info("PlayerList", "Initialized");
    list.onPlayerAdded >> [](auto &player) {
      Locator<PlayerList>()->set.insert(&player);
      QueueForServerThread([tuple = player >> PlayerBasicInfo] {
        auto [name, uuid, xuid] = tuple;
        Log::info("PlayerList", "Player %s joined(uuid: %s, xuid: %s)", name.c_str(), uuid.asString().c_str(), xuid.c_str());
        PlayerInfo temp = { name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr };
        Locator<CoreService<ServerSide>>()->players.set(name >> StdStr, temp);
        Locator<CoreService<ServerSide>>()->online_players += temp;
      });
    };
    list.onPlayerRemoved >> [](auto &player) {
      Locator<PlayerList>()->set.erase(&player);
      QueueForServerThread([tuple = player >> PlayerBasicInfo] {
        auto [name, uuid, xuid] = tuple;
        Log::info("PlayerList", "Player %s left  (uuid: %s, xuid: %s)", name.c_str(), uuid.asString().c_str(), xuid.c_str());
        Locator<CoreService<ServerSide>>()->online_players -= { name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr };
      });
    };
    Locator<CoreService<ServerSide>>()->online_players.clear();
  };
  Locator<Chat>() >> [](Chat &chat) {
    using namespace std::placeholders;
    auto &service = Locator<ChatService<ServerSide>>();
    chat.onPlayerChat >> [](auto &player, auto &msg) {
      QueueForServerThread([name = player >> PlayerName, msg] {
        Log::info("Chat", "<%s> %s", name >> CStr, msg >> CStr);
        Locator<ChatService<ServerSide>>()->recv << NormalMessage{ name >> StdStr, msg >> StdStr };
      });
    };
    chat.onChat >> [](auto &sender, auto &msg) {
      QueueForServerThread([sender, msg] {
        Log::info("Chat", "[%s] %s", sender >> CStr, msg >> CStr);
        Locator<ChatService<ServerSide>>()->recv << NormalMessage{ sender >> StdStr, msg >> StdStr };
      });
    };
    service->send >> [&](auto msg) {
      auto [sender, content] = msg;
      chat.sendChat(sender, content);
    };
    service->raw >> std::bind(&Chat::sendAnnouncement, &chat, _1);
  };
  Locator<Blacklist>() >> [](Blacklist &list) {
    auto &service = Locator<BlacklistService<ServerSide>>();
    service->add >> [&](auto arg) {
      auto [type, content, reason] = arg;
      if (type == "name") {
        auto callback = [=, &list](bool flag, auto entity) {
          if (flag) list.add(mce::UUID::fromString(entity.uuid), arg.reason);
        };
        Locator<CoreService<ServerSide>>()->players.get(content, callback);
      } else if (type == "uuid") {
        list.add(mce::UUID::fromString(content), reason);
      } else if (type == "xuid") {
        list.add(content, reason);
      }
    };
    service->kick >> [&](auto arg) {
      auto [type, content, reason] = arg;
      auto continuation            = [&](auto filter) {
        for (auto &player : Locator<PlayerList>()->set) {
          if (filter(player)) {
            list.kick(*player >> PlayerNetworkID, arg.reason);
            break;
          }
        }
      };
      if (type == "name") {
        continuation([&](auto player) { return PlayerName[*player] == arg.content; });
      } else if (type == "uuid") {
        continuation([&](auto player) { return PlayerUUID[*player].asString() == arg.content; });
      } else if (type == "xuid") {
        continuation([&](auto player) { return PlayerXUID(*player) == arg.content; });
      }
    };
    service->remove >> [&](auto arg) {
      auto [type, content] = arg;
      if (type == "name") {
        auto callback = [=, &list](bool flag, auto entity) {
          if (flag) list.remove(mce::UUID::fromString(entity.uuid));
        };
        Locator<CoreService<ServerSide>>()->players.get(content, callback);
      } else if (type == "uuid") {
        list.remove(mce::UUID::fromString(content));
      } else if (type == "xuid") {
        list.remove(content);
      }
    };
  };
}
