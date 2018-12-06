#include <interface/locator.hpp>
#include <interface/player_list.h>

#include "patched.h"
#include "patched/Player.h"
#include "services.h"

#include <log.h>
#include <minecraft/ExtendedCertificate.h>
#include <minecraft/Level.h>
#include <minecraft/Minecraft.h>

#include <simppl/skeleton.h>
#include <simppl/struct.h>
#include <simppl/string.h>
#include <simppl/vector.h>

void initDependencies() {
  using namespace interface;
  using namespace patched;
  using namespace one::codehz::stone;

  Locator<ServerInstance>() >> FieldRef(&ServerInstance::minecraft);
  Locator<Minecraft>() >> MethodGet(&Minecraft::getCommands);
  Locator<Minecraft>() >> MethodGet(&Minecraft::getLevel);
  Locator<PlayerList>() >> [](PlayerList *list) {
    list->list = Locator<Level>()->getUsers();
    list->onPlayerAdded >> [](Player *player) { Log::info("PlayerList", "Player %s joined", PlayerName[*player].c_str()); };
    list->onPlayerRemoved >> [](Player *player) { Log::info("PlayerList", "Player %s left", PlayerName[*player].c_str()); };
    auto updateDBus = [](Player *) {
      std::vector<structs::PlayerInfo> vec;
      for (auto player : *Locator<PlayerList>()->list) {
        auto name = PlayerName[*player];
        auto uuid = PlayerUUID[*player];
        auto xuid = ExtendedCertificate::getXuid(*player->getCertificate());
        vec.emplace_back(structs::PlayerInfo{ name.std(), uuid.asString().std(), xuid.std() });
      }
      Locator<Skeleton<CoreService>>()->players = vec;
    };
    list->onPlayerAdded >> [](Player *player) {
      auto name = PlayerName[*player];
      auto uuid = PlayerUUID[*player];
      auto xuid = ExtendedCertificate::getXuid(*player->getCertificate());
      Locator<Skeleton<CoreService>>()->playerAdded.notify(structs::PlayerInfo{ name.std(), uuid.asString().std(), xuid.std() });
    };
    list->onPlayerRemoved >> [](Player *player) {
      auto name = PlayerName[*player];
      auto uuid = PlayerUUID[*player];
      auto xuid = ExtendedCertificate::getXuid(*player->getCertificate());
      Locator<Skeleton<CoreService>>()->playerRemoved.notify(structs::PlayerInfo{ name.std(), uuid.asString().std(), xuid.std() });
    };
    list->onPlayerAdded >> updateDBus;
    list->onPlayerRemoved >> updateDBus;
    Locator<Skeleton<CoreService>>()->getPlayerInfo >> [](char const &type, std::string const &query) {
      using namespace uintl;
      constexpr char const *typemap[] = { "name", "uuid", "xuid" };
      bool (*test)(Player *, std::string const &query);
      switch (type) {
      case 0: test = [](Player *p, std::string const &query) { return PlayerName[*p] == query; }; break;
      case 1: test = [](Player *p, std::string const &query) { return PlayerUUID[*p].asString() == query; }; break;
      case 2: test = [](Player *p, std::string const &query) { return ExtendedCertificate::getXuid(*p->getCertificate()) == query; }; break;
      default:
        Locator<Skeleton<CoreService>>()->respond_with(Error("query_type.unknown", strformat("Unknown query type: %d"_intl, type).c_str()));
        return;
      }
      for (auto player : *Locator<PlayerList>()->list) {
        if (test(player, query)) {
          map<string, simppl::Variant<string, int, unsigned, double>> ret;
          auto [x, y, z]    = player->getPos();
          auto [pitch, yaw] = player->getRotation();

          ret["name"]  = PlayerName[*player].std();
          ret["uuid"]  = PlayerUUID[*player].asString().std();
          ret["xuid"]  = ExtendedCertificate::getXuid(*player->getCertificate()).std();
          ret["x"]     = (double)x;
          ret["y"]     = (double)y;
          ret["z"]     = (double)z;
          ret["pitch"] = (double)pitch;
          ret["yaw"]   = (double)yaw;
          ret["xp"]    = (double)player->getLevelProgress();
          Locator<Skeleton<CoreService>>()->respond_with(Locator<Skeleton<CoreService>>()->getPlayerInfo(ret));
          return;
        }
      }
      Locator<Skeleton<CoreService>>()->respond_with(
          Error(strformat("query.%s.failed", typemap[(int)type]).c_str(), strformat("Player not found: %s"_intl, query.c_str()).c_str()));
      return;
    };
  };
}