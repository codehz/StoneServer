#pragma once

#include "CommandRegistry.h"

using CDT = void (*)(void *);

template <typename> class CommonType;

template <> struct CommonType<mcpe::string> {
  /// @symbol _ZZ7type_idI15CommandRegistrySsE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> tid;
  /// @symbol _ZNK15CommandRegistry5parseISsEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<int> {
  /// @symbol _ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> tid;
  /// @symbol _ZNK15CommandRegistry5parseIiEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<float> {
  /// @symbol _ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> tid;
  /// @symbol _ZNK15CommandRegistry5parseIfEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};