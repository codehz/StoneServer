#pragma once

#include "CommandRegistry.h"
#include <memory>
#include <vector>

struct Actor;
struct Player;
class CommandOrigin;

struct CommandSelectorBase {
  char filler[0x100];
  CommandSelectorBase(bool);
  ~CommandSelectorBase();

  std::shared_ptr<std::vector<Actor *>> newResults(CommandOrigin const &) const;
};

struct CommandActorSelector : CommandSelectorBase {
  CommandActorSelector()
      : CommandSelectorBase(false) {}
  /// @symbol _ZZ7type_idI15CommandRegistry15CommandSelectorI5ActorEE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseI15CommandSelectorI5ActorEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

struct CommandPlayerSelector : CommandSelectorBase {
  CommandPlayerSelector()
      : CommandSelectorBase(true) {}
  /// @symbol _ZZ7type_idI15CommandRegistry15CommandSelectorI6PlayerEE8typeid_tIT_EvE2id
  static typeid_t<CommandRegistry> *tid;
  /// @symbol _ZNK15CommandRegistry5parseI15CommandSelectorI6PlayerEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE
  static Parser parser;
};

template <typename T> struct CommandSelector;

template <> struct CommandSelector<Actor> : CommandActorSelector {};
template <> struct CommandSelector<Player> : CommandPlayerSelector {};