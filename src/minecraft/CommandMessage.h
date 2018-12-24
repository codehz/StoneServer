#pragma once

#include "CommandRegistry.h"
#include "CommandUtils.h"
#include "std/string.h"

class CommandMessage {
  char filler[0x10];

public:
  mcpe::string getMessage(CommandOrigin const &) const;
  /// @symbol _ZN14CommandMessageC2Ev
  static CDT constructor;
  /// @symbol _ZN14CommandMessageD2Ev
  static CDT destructor;
  /// @symbol _ZZ7type_idI15CommandRegistry14CommandMessageE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseI14CommandMessageEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};