#pragma once

#include "std/string.h"

class ActorDefinitionIdentifier {
public:
  mcpe::string getCanonicalName() const;
};

struct CompoundTag;

class Actor {
public:
  ActorDefinitionIdentifier &getActorIdentifier() const;
  int64_t &getUniqueID() const;

  bool save(CompoundTag &);
  bool load(CompoundTag const &);
};