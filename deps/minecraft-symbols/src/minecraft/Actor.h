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
};