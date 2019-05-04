#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct LogEntry {
  std::string tag;
  int level;
  std::string content;
};

inline void to_json(rpc::json &j, const LogEntry &i) {
  j["tag"]     = i.tag;
  j["level"]   = i.level;
  j["content"] = i.content;
}

inline void from_json(const rpc::json &j, LogEntry &i) {
  j.at("tag").get_to(i.tag);
  j.at("level").get_to(i.level);
  j.at("content").get_to(i.content);
}

struct PlayerInfo {
  std::string name, uuid, xuid;
};

inline void to_json(rpc::json &j, const PlayerInfo &i) {
  j["name"] = i.name;
  j["uuid"] = i.uuid;
  j["xuid"] = i.xuid;
}

inline void from_json(const rpc::json &j, PlayerInfo &i) {
  j.at("name").get_to(i.name);
  j.at("uuid").get_to(i.uuid);
  j.at("xuid").get_to(i.xuid);
}

struct CoreService : Service {
  Action<Empty> stop{ "stop" };
  Method<Empty, Empty> ping{ "ping" };
  Method<float, Empty> tps{ "tps" };
  Method<std::string, Empty> config{ "config" };
  Broadcast<LogEntry> log{ "log" };
  Method<std::vector<PlayerInfo>, Empty> online_players{ "online_players" };
  Broadcast<PlayerInfo> player_join{ "player_join" };
  Broadcast<PlayerInfo> player_left{ "player_left" };

  CoreService()
      : Service("core") {
    $(stop);
    $(ping);
    $(tps);
    $(config);
    $(log);
    $(online_players);
    $(player_join);
    $(player_left);
  }
};

} // namespace api
