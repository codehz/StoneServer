#pragma once

#include "std/string.h"
#include "types.h"
#include <array>

class ActorDefinitionIdentifier {
public:
  mcpe::string getCanonicalName() const;
};

struct CompoundTag;
struct BlockSource;
struct ItemInstance;
enum ArmorSlot {};

class Actor {
public:
  void **vtable;

  ActorDefinitionIdentifier &getActorIdentifier() const;
  int64_t &getUniqueID() const;

  bool save(CompoundTag &);
  bool load(CompoundTag const &);

  Vec3 &getPos() const;
  Vec2 getRotation() const;
  BlockSource &getRegion() const;
  mcpe::string const &getNameTag() const;
  std::tuple<int> getDimensionId() const;
  int getVariant() const;
  short getAirSupply() const;
  short getTotalAirSupply() const;
  int getStrength() const;
  int getStrengthMax() const;
  int getAge() const;
  int getHealth() const;
  int getMaxHealth() const;
  Actor *getRide() const;
  Actor *getRideRoot() const;
  Actor *getTarget() const;
  ItemInstance &getArmor(ArmorSlot slot) const;

  /// @vtable ServerPlayer _ZN12ServerPlayer15changeDimensionE11AutomaticIDI9DimensioniEb
  void changeDimension(int id, bool show);
};