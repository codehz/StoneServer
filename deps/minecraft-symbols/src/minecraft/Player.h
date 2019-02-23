#pragma once

#include "Actor.h"
#include "std/string.h"
#include <tuple>

class Certificate;

class Packet;

class Player : public Actor {
public:
  explicit Player(Player const &) = delete;

  mcpe::string *getPlatformOnlineId() const;

  Certificate *getCertificate() const;

  /// @symbol _ZNK5Actor10isCreativeEv
  bool isCreative();

  float getLevelProgress() const;

  /// @symbol _ZNK12ServerPlayer17sendNetworkPacketER6Packet
  void sendNetworkPacket(Packet &) const;

  bool canUseAbility(mcpe::string const &);
};