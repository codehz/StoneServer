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
  Method<oneway> stop;
  Method<in<char>, in<string>, out<map<string, simppl::Variant<string, int, unsigned, double>>>> getPlayerInfo;
  Property<vector<structs::PlayerInfo>, ReadWrite | Notifying | Always> players;
  Signal<structs::PlayerInfo> playerAdded;
  Signal<structs::PlayerInfo> playerRemoved;
  Signal<int, string, string> log;

  CoreService()
      : INIT(stop)
      , INIT(getPlayerInfo)
      , INIT(players)
      , INIT(playerAdded)
      , INIT(playerRemoved)
      , INIT(log) {}
};

} // namespace one::codehz::stone