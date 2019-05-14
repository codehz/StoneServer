#include <interface/blacklist.h>
#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

#include <stone-api/Blacklist.h>
#include <stone-api/Chat.h>
#include <stone-api/Core.h>

#include "blacklist_mgr.hpp"
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

template <class T> struct always_false : std::false_type {};

void initDependencies() {
  using namespace interface;
  using namespace patched;
  using namespace api;
  using Blacklist = interface::Blacklist;

  Locator<ServerInstance>() >> [](ServerInstance &instance) { Locator<Minecraft>() = MinecraftFromServerInstance(instance); };
  Locator<Minecraft>() >> MethodGet(&Minecraft::getCommands);
  Locator<MinecraftCommands>() >> MethodGet(&MinecraftCommands::getRegistry);
  Locator<PlayerList>() >> [](auto &list) {
    Log::info("PlayerList", "Initialized");
    list.onPlayerAdded >> [](auto &player) {
      Locator<PlayerList>()->set.insert(&player);
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      Log::info("PlayerList", "Player %s joined(uuid: %s, xuid: %s)", name.c_str(), uuid.c_str(), xuid.c_str());
      Locator<CoreService>()->player_join << PlayerInfo{ name, uuid, xuid };
    };
    list.onPlayerRemoved >> [](auto &player) {
      Locator<PlayerList>()->set.erase(&player);
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      Log::info("PlayerList", "Player %s left  (uuid: %s, xuid: %s)", name.c_str(), uuid.c_str(), xuid.c_str());
      Locator<CoreService>()->player_left << PlayerInfo{ name, uuid, xuid };
    };

    Locator<CoreService>()->online_players >> [](auto) {
      std::vector<PlayerInfo> ret;
      for (auto pplayer : Locator<PlayerList>()->set) {
        auto [name, uuid, xuid] = PlayerBasicInfo(*pplayer);
        ret.emplace_back(PlayerInfo{ name, uuid, xuid });
      }
      return ret;
    };
  };
  Locator<Chat>() >> [](Chat &chat) {
    using namespace std::placeholders;
    auto &service = Locator<ChatService>();
    chat.onPlayerChat >> [](auto &player, auto &msg) {
      auto name = player >> PlayerName;
      Log::info("Chat", "<%s> %s", name >> CStr, msg >> CStr);
      Locator<ChatService>()->recv << NormalMessage{ name >> StdStr, msg >> StdStr };
    };
    chat.onChat >> [](auto &sender, auto &msg) {
      Log::info("Chat", "[%s] %s", sender >> CStr, msg >> CStr);
      Locator<ChatService>()->recv << NormalMessage{ sender >> StdStr, msg >> StdStr };
    };
    service->send >> [&](auto msg) {
      auto [sender, content] = msg;
      chat.sendChat(sender, content);
    };
    service->raw >> std::bind(&Chat::sendAnnouncement, &chat, _1);
  };
  Locator<Blacklist>() >> [](Blacklist &list) {
    auto &service = Locator<BlacklistService>();
    service->add >> [&](auto arg) {
      auto [type, content, reason] = arg;
      if (type == "name") {
        for (auto player : Locator<PlayerList>()->set) {
          auto [name, uuid, xuid] = PlayerBasicInfo(*player);
          if (name == content) {
            list.add(mce::UUID::fromString(uuid), reason);
            Log::debug("Blacklist", "Created blacklist entry [%s]", content.c_str());
            break;
          }
        }
      } else if (type == "uuid") {
        list.add(mce::UUID::fromString(content), reason);
        Log::debug("Blacklist", "Created blacklist entry [%s]", content.c_str());
      } else if (type == "xuid") {
        list.add(content, reason);
        Log::debug("Blacklist", "Created blacklist entry [%s]", content.c_str());
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
        for (auto player : Locator<PlayerList>()->set) {
          auto [name, uuid, xuid] = PlayerBasicInfo(*player);
          if (name == content) {
            list.remove(mce::UUID::fromString(uuid));
            Log::debug("Blacklist", "Removed blacklist entry [%s]", content.c_str());
            break;
          }
        }
      } else if (type == "uuid") {
        list.remove(mce::UUID::fromString(content));
        Log::debug("Blacklist", "Removed blacklist entry [%s]", content.c_str());
      } else if (type == "xuid") {
        list.remove(content);
        Log::debug("Blacklist", "Removed blacklist entry [%s]", content.c_str());
      }
    };
    service->fetch >> [&](auto) {
      std::vector<BlacklistOP<true>> ret;
      list.forEach([&](auto vart, auto reason) {
        std::visit(
            [&](auto &&arg) {
              using T = std::decay_t<decltype(arg)>;
              if constexpr (std::is_same_v<T, std::string>) {
                ret.emplace_back(BlacklistOP<true>{ "xuid", arg, reason });
              } else if constexpr (std::is_same_v<T, mce::UUID>) {
                ret.emplace_back(BlacklistOP<true>{ "uuid", arg.asString().std(), reason });
              } else
                static_assert(always_false<T>::value, "non-exhaustive visitor!");
            },
            vart);
      });
      return ret;
    };
    service->save >> [&](auto) { Locator<BlacklistManager>()->save(); };
    service->reload >> [&](auto) { Locator<BlacklistManager>()->reload(); };
  };
}
