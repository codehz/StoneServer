#include <interface/locator.hpp>
#include <interface/player_list.h>
#include <interface/chat.h>

#include "operators.h"
#include "patched.h"
#include "patched/Player.h"
#include "services.h"

#include <log.h>
#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>
#include <minecraft/MinecraftCommands.h>

#include <simppl/skeleton.h>
#include <simppl/string.h>
#include <simppl/struct.h>
#include <simppl/vector.h>

void initDependencies() {
  using namespace interface;
  using namespace patched;
  using namespace one::codehz::stone;

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
      vector<structs::PlayerInfo> vec;
      for (auto &player : Locator<PlayerList>()->set) {
        auto [name, uuid, xuid] = PlayerBasicInfo(*player);
        vec.emplace_back(structs::PlayerInfo{ name.std(), uuid.asString().std(), xuid.std() });
      }
      Locator<Skeleton<CoreService>>()->players = vec;
    };
    list.onPlayerAdded >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      Locator<Skeleton<CoreService>>()->playerAdded.notify(structs::PlayerInfo{ name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr });
    };
    list.onPlayerRemoved >> [](auto &player) {
      auto [name, uuid, xuid] = player >> PlayerBasicInfo;
      Locator<Skeleton<CoreService>>()->playerRemoved.notify(structs::PlayerInfo{ name >> StdStr, uuid >> UUIDStr >> StdStr, xuid >> StdStr });
    };
    list.onPlayerAdded >> updateDBus;
    list.onPlayerRemoved >> updateDBus;
    Locator<Skeleton<CoreService>>()->getPlayerInfo >> [](auto type, auto query) {
      using namespace uintl;
      constexpr char const *typemap[] = { "name", "uuid", "xuid" };
      bool (*test)(Player &, string const &query);
      switch (type) {
      case 0: test = [](auto &p, auto query) { return p >> PlayerName >> StdStr >> EqualsTo(query); }; break;
      case 1: test = [](auto &p, auto query) { return p >> PlayerUUID >> UUIDStr >> StdStr >> EqualsTo(query); }; break;
      case 2: test = [](auto &p, auto query) { return p >> PlayerXUID >> StdStr >> EqualsTo(query); }; break;
      default:
        Locator<Skeleton<CoreService>>()->respond_with(Error("query_type.unknown", strformat("Unknown query type: %d"_intl, type).c_str()));
        return;
      }
      for (auto pplayer : Locator<PlayerList>()->set) {
        auto &player = *pplayer;
        if (test(player, query)) {
          map<string, simppl::Variant<string, int, unsigned, double>> ret;
          auto [x, y, z]          = player >> PlayerPos;
          auto [pitch, yaw]       = player >> PlayerRot;
          auto [name, uuid, xuid] = player >> PlayerBasicInfo;

          ret["name"]  = name >> StdStr;
          ret["uuid"]  = uuid >> UUIDStr >> StdStr;
          ret["xuid"]  = xuid >> StdStr;
          ret["x"]     = x >> FloatToDouble;
          ret["y"]     = y >> FloatToDouble;
          ret["z"]     = z >> FloatToDouble;
          ret["pitch"] = pitch >> FloatToDouble;
          ret["yaw"]   = yaw >> FloatToDouble;
          ret["xp"]    = player >> PlayerLvl >> FloatToDouble;
          Locator<Skeleton<CoreService>>()->respond_with(Locator<Skeleton<CoreService>>()->getPlayerInfo(ret));
          return;
        }
      }
      Locator<Skeleton<CoreService>>()->respond_with(
          Error(strformat("query.%s.failed", typemap[(int)type]).c_str(), strformat("Player not found: %s"_intl, query.c_str()).c_str()));
      return;
    };
  };
  Locator<Chat>() >> [](Chat &chat) {
    chat.onPlayerChat >> [](auto &player, auto &msg) {
      Log::info("Chat", "[%s] %s", player >> PlayerName >> CStr, msg >> CStr);
    };
    chat.onChat >> [](auto &sender, auto &msg) {
      Log::info("Chat", "[%s] %s", sender >> CStr, msg >> CStr);
    };
  };
}