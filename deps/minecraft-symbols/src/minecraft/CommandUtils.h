#pragma once

#include "CommandRegistry.h"
#include "CommandSelector.h"
#include "json.h"

using CDT = void (*)(void *);

template <typename T> struct CommonType : T {};

template <> struct CommonType<mcpe::string> {
  /// @symbol _ZZ7type_idI15CommandRegistrySsE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseISsEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<int> {
  /// @symbol _ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseIiEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<float> {
  /// @symbol _ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseIfEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<bool> {
  /// @symbol _ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseIbEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

struct CommandRawText {
  mcpe::string value;
};

template <> struct CommonType<CommandRawText> {
  /// @symbol _ZZ7type_idI15CommandRegistry14CommandRawTextE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseI14CommandRawTextEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

struct CommandPosition {
  char filler[16];
  std::tuple<float, float, float> getPosition(CommandOrigin const &) const;
};

template <> struct CommonType<CommandPosition> {
  /// @symbol _ZZ7type_idI15CommandRegistry15CommandPositionE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseI15CommandPositionEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

struct Block;

template <> struct CommonType<Block *> {
  /// @symbol _ZZ7type_idI15CommandRegistryPK5BlockE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseIPK5BlockEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <> struct CommonType<Json::Value> {
  /// @symbol _ZZ7type_idI15CommandRegistryN4Json5ValueEE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseIN4Json5ValueEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};