#pragma once

#include "std/string.h"
#include "UUID.h"
#include <memory>

class CommandOrigin {
public:
  void **vtable;
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin7getNameEv
  mcpe::string getName();
  /// @vtable PlayerCommandOrigin _ZNK19PlayerCommandOrigin5cloneEv
  std::unique_ptr<CommandOrigin> clone();

  mce::UUID const &getUUID() const;
};