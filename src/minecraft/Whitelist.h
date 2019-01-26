#pragma once

#include "UUID.h"
#include "json.h"
#include "std/string.h"
#include "std/function.h"
#include <vector>

struct WhitelistEntry {
  char filler[0x20];

  /// @symbol _ZN14WhitelistEntryC2ESsN3mce4UUIDESsb
  WhitelistEntry(mcpe::string name, mce::UUID uuid, mcpe::string xuid, bool ignoresPlayerLimit);
};

struct Whitelist {
  char filler[0x100];

  /// @symbol _ZN9WhitelistC2ESt8functionIFvvEE
  Whitelist(mcpe::function<void()> fn);

  /// @symbol _ZN9Whitelist11deserializeERN4Json5ValueE
  void deserialize(Json::Value &);
  /// @symbol _ZN9Whitelist9serializeERN4Json5ValueE
  void serialize(Json::Value &);
  void removeByName(mcpe::string const&);
};