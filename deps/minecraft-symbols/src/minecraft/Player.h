#pragma once

#include "Actor.h"
#include "std/string.h"
#include <tuple>

class Certificate;

class Packet;

struct ItemInstance;

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

  unsigned char getCommandPermissionLevel() const;

  BlockPos getSpawnPosition();

  ItemInstance &getSelectedItem() const;

  int getSleepTimer() const;

  float getLuck();

  int getAttackDamage();

  Actor *getAgent() const;
};