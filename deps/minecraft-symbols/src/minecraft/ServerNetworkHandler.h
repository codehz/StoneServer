#pragma once

#include "NetworkIdentifier.h"
#include "UUID.h"

#include <chrono>

struct NetworkStats {
  int32_t filler, ping, avgping, maxbps;
  float packetloss, avgpacketloss;
};

struct NetworkPeer {
  void **vtable;

  /// @vtable LocalNetworkPeer _ZN16LocalNetworkPeer16getNetworkStatusEv
  NetworkStats getNetworkStatus();
};

struct ClientToServerHandshakePacket;

class ServerNetworkHandler {
public:
  /// @symbol _ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSs
  void addToBlacklist(mce::UUID const &uuid, mcpe::string const &xuid);
  /// @symbol _ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSsS5_RKN9Blacklist8DurationE
  void addToBlacklist(mce::UUID const &uuid, mcpe::string const &xuid, mcpe::string const &reason, int const &duration);
  /// @symbol _ZN20ServerNetworkHandler19removeFromBlacklistERKN3mce4UUIDERKSs
  void removeFromBlacklist(mce::UUID const &uuid, mcpe::string const &xuid);

  void disconnectClient(NetworkIdentifier const &id, std::string const &reason, bool flag);

  /// @symbol _ZN14NetworkHandler14getPeerForUserERK17NetworkIdentifier
  NetworkPeer *getPeerForUser(NetworkIdentifier const &);

  void handle(NetworkIdentifier const &, ClientToServerHandshakePacket const &);
};