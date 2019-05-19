#pragma once

#include <fstream>
#include <mcpelauncher/path_helper.h>
#include <minecraft/Level.h>
#include <properties/property.h>

class ServerProperties {
  using property_list                  = properties::property_list;
  template <typename T> using property = properties::property<T>;

public:
  std::string config;
  property_list properties;
  property<std::string> worldDir;
  property<std::string> worldName;
  property<int> worldGenerator;
  property<std::string> motd;
  property<std::string> worldSeed;
  property<int> gamemode;
  property<bool> cheatsEnabled;
  property<bool> forceGamemode;
  property<bool> eduMode;
  property<bool> experimentMode;
  property<bool> texturepackRequired;
  property<int> difficulty;
  property<std::string> ip;
  property<std::string> ipv6;
  property<int> port;
  property<int> portV6;
  property<int> maxPlayers;
  property<int> viewDistance;
  property<int> tickDistance;
  property<bool> onlineMode;
  property<float> playerIdleTimeout;
  property<bool> activateWhitelist;
  property<bool> overrideSavedSettings;

  inline std::string cfg() {
    const char *value = getenv("STONE_CONFIG");
    return value ? value : "server";
  }

  ServerProperties()
      : worldDir(properties, "level-dir", "world")
      , worldName(properties, "level-name", "world")
      , worldSeed(properties, "level-seed", std::to_string(Level::createRandomSeed()))
      , worldGenerator(properties, "level-generator", 1)
      , motd(properties, "motd", "A Minecraft Server")
      , gamemode(properties, "gamemode", 0)
      , cheatsEnabled(properties, "cheats-enabled", false)
      , forceGamemode(properties, "force-gamemode", false)
      , eduMode(properties, "edu-mode", false)
      , experimentMode(properties, "experiment-mode", false)
      , texturepackRequired(properties, "texturepack-required", false)
      , difficulty(properties, "difficulty", 0)
      , ip(properties, "server-ip", "0.0.0.0")
      , ipv6(properties, "server-ip-v6", "::")
      , port(properties, "server-port", 19132)
      , portV6(properties, "server-port-v6", 19133)
      , maxPlayers(properties, "max-players", 20)
      , viewDistance(properties, "view-distance", 10)
      , tickDistance(properties, "tick-distance", 4)
      , onlineMode(properties, "online-mode", true)
      , playerIdleTimeout(properties, "player-idle-timeout", 0.f)
      , activateWhitelist(properties, "activate-whitelist", false)
      , overrideSavedSettings(properties, "override-saved-settings", true) {
    config = cfg();
  }

  inline void load() {
    std::ifstream propertiesFile(PathHelper::getPrimaryDataDirectory() + config + ".properties");
    if (propertiesFile) {
      properties.load(propertiesFile);
    } else {
      save();
    }
  }

  inline void save() {
    std::ofstream propertiesFile(PathHelper::getPrimaryDataDirectory() + config + ".properties");
    properties.save(propertiesFile);
  }
};
