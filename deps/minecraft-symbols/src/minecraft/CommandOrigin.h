#pragma once

#include "std/string.h"
#include "UUID.h"

class CommandOrigin {
public:
  void **vtable;
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin7getNameEv
  mcpe::string getName();

  mce::UUID const &getUUID() const;
};