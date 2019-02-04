#pragma once

#include "apid.hpp"
#include <sstream>

namespace api {

struct LogEntry {
  std::string tag;
  int level;
  std::string content;

  std::string build(std::string name) const { return name + "." + tag + "#" + std::to_string(level); }

  static inline char const *write(LogEntry const &input) { return input.content.c_str(); }
  static inline LogEntry rebuild(char const *identify, char const *data) {
    auto tag_start = strrchr(identify, '.');
    auto lvl_start = strrchr(identify, '#');
    return { std::string(tag_start + 1, lvl_start - tag_start - 1), atoi(lvl_start + 1), data };
  }
  static inline std::string build_pattern(std::string const &name, std::string tag) { return name + "." + tag + "#[0-9]"; }
  static inline std::string build_pattern(std::string const &name, int level) { return name + ".*#" + std::to_string(level); }
  static inline std::string build_pattern(std::string const &name, std::tuple<std::string, int> filter) {
    auto [tag, level] = filter;
    return name + "." + tag + "#" + std::to_string(level);
  }
  static inline std::string build_pattern(std::string const &name) { return name + ".*"; }
};

struct PlayerInfo {
  std::string name, uuid, xuid;

  static inline Buffer write(PlayerInfo const &input) {
    char *buffer;
    asprintf(&buffer, "%s\n%s\n%s", input.name.data(), input.uuid.data(), input.xuid.data());
    return { buffer };
  }
  static inline PlayerInfo read(char const *input) {
    std::istringstream iss{ input };
    PlayerInfo info;
    std::getline(iss, info.name);
    std::getline(iss, info.uuid);
    std::getline(iss, info.xuid);
    return info;
  }
};

template <typename Side> struct CoreService : ProxiedService<Side, CoreService> {
  ProxiedAction<Side, Empty> stop{ "stop" };
  ProxiedMethod<Side, Empty, Empty> ping{ "ping" };
  ProxiedProperty<Side, std::string> config{ "config" };
  ProxiedPatternBoardcast<Side, LogEntry> log{ "log" };
  ProxiedHash<Side, std::string, PlayerInfo> players{ "players" };
  ProxiedSet<Side, PlayerInfo> online_players{ "online_players" };

  CoreService()
      : ProxiedService<Side, CoreService>("core") {
    this->$(stop);
    this->$(ping);
    this->$(config);
    this->$(log);
    this->$(players);
    this->$(online_players);
  }
};

} // namespace api
