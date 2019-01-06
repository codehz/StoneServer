#pragma once

#include "UUID.h"
#include <chrono>

class ServerNetworkHandler {
public:
  /// @symbol _ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSs
  void addToBlacklist(mce::UUID const &uuid, mcpe::string const &xuid);
  /// @symbol _ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSsS5_RKN9Blacklist8DurationE
  void addToBlacklist(mce::UUID const &uuid, mcpe::string const &xuid, mcpe::string const &reason, std::chrono::seconds const &duration);
  /// @symbol _ZN20ServerNetworkHandler19removeFromBlacklistERKN3mce4UUIDERKSs
  void removeFromBlacklist(mce::UUID const &uuid, mcpe::string const &xuid);
};