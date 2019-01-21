#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

namespace structs {
struct PlayerInfo {
  using serializer_type = make_serializer<string, string, string>::type;
  string name, uuid, xuid;
  void jsonToStream(std::ostream &o) const;
  bool operator!=(PlayerInfo const &rhs) const { return name != rhs.name; }
  bool operator==(PlayerInfo const &rhs) const { return name == rhs.name; }
};
} // namespace structs

INTERFACE(CoreService) {
  Method<oneway> Stop;
  Method<in<char>, in<string>, out<map<string, simppl::Variant<string, int, unsigned, double>>>> GetPlayerInfo;
  Property<string, ReadOnly> Config;
  Property<vector<structs::PlayerInfo>, ReadWrite | Notifying | Always> Players;
  Signal<structs::PlayerInfo> PlayerAdded;
  Signal<structs::PlayerInfo> PlayerRemoved;
  Signal<int, string, string> Log;

  CoreService()
      : INIT(Stop)
      , INIT(GetPlayerInfo)
      , INIT(Config)
      , INIT(Players)
      , INIT(PlayerAdded)
      , INIT(PlayerRemoved)
      , INIT(Log) {}
};

} // namespace one::codehz::stone