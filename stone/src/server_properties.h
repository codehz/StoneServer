#pragma once

#include <fstream>
#include <mcpelauncher/path_helper.h>
#include <minecraft/Level.h>
#include <properties/property.h>

namespace {

using namespace properties;

class ServerProperties {

public:
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
  property<int> port;
  property<int> portV6;
  property<int> maxPlayers;
  property<int> viewDistance;
  property<int> tickDistance;
  property<bool> onlineMode;
  property<float> playerIdleTimeout;

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
      , port(properties, "server-port", 19132)
      , portV6(properties, "server-port-v6", 19133)
      , maxPlayers(properties, "max-players", 20)
      , viewDistance(properties, "view-distance", 10)
      , tickDistance(properties, "tick-distance", 4)
      , onlineMode(properties, "online-mode", true)
      , playerIdleTimeout(properties, "player-idle-timeout", 0.f) {}

  void load() {
    std::ifstream propertiesFile(PathHelper::getPrimaryDataDirectory() + "server.properties");
    if (propertiesFile) {
      properties.load(propertiesFile);
    } else {
      save();
    }
  }

  void save() {
    std::ofstream propertiesFile(PathHelper::getPrimaryDataDirectory() + "server.properties");
    properties.save(propertiesFile);
  }
};

} // namespace