#pragma once

#include "std/string.h"
#include <array>

class ActorDefinitionIdentifier {
public:
  mcpe::string getCanonicalName() const;
};

struct CompoundTag;

class Actor {
public:
  void **vtable;

  ActorDefinitionIdentifier &getActorIdentifier() const;
  int64_t &getUniqueID() const;

  bool save(CompoundTag &);
  bool load(CompoundTag const &);

  std::array<float, 3> &getPos() const;
  std::array<float, 2> getRotation() const;
  mcpe::string const &getNameTag() const;
  std::tuple<int> getDimensionId() const;
};