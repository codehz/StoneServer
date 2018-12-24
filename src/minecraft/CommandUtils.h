#pragma once

#include "CommandRegistry.h"

using CDT = void (*)(void *);

template<typename> class CommonType;

template<>
struct CommonType<mcpe::string> {
  /// @symbol _ZZ7type_idI15CommandRegistrySsE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> tid;
  /// @symbol _ZNK15CommandRegistry5parseISsEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};