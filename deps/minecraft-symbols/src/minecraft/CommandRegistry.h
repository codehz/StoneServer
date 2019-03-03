#pragma once

#include "AutoComplete.h"
#include "CommandOrigin.h"
#include "std/string.h"
#include <memory>

using CommandVersion           = std::pair<int, int>;
using CommandPermissionLevel   = int;
using CommandFlag              = int;
using CommandParameterDataType = int;
class Command;
struct CommandRegistry;
class CommandParameterData;

template <typename T> struct typeid_t {
  short id;

  inline typeid_t()
      : id(-1) {}
  inline typeid_t(short id)
      : id(id) {}
  inline typeid_t(typeid_t const &t) { id = t.id; }
  bool operator==(std::nullptr_t nt) { return id == -1; }
};

template <typename T, typename T2> typeid_t<T> type_id() {
  static typeid_t<T> id;
  return id;
};

struct CommandRegistry {
  // @symbol _ZNK15CommandRegistry22getAutoCompleteOptionsERK13CommandOriginRKSsj
  std::unique_ptr<AutoCompleteInformation> getAutoCompleteOptions(CommandOrigin const &, mcpe::string const &, unsigned int) const;
  struct Overload {
    CommandVersion version;
    std::unique_ptr<Command> (*allocator)();
    std::vector<CommandParameterData> params;
    int filler; // I don't think this is an actual member, looks like padding to me

    Overload(CommandVersion version, std::unique_ptr<Command> (*allocator)())
        : version(version)
        , allocator(allocator) {}
  };
  struct Signature {
    char filler[8];
    std::vector<CommandRegistry::Overload> overloads;
  };

  CommandRegistry::Signature *findCommand(mcpe::string const &);
  /// @symbol _ZN15CommandRegistry24registerOverloadInternalERNS_9SignatureERNS_8OverloadE
  void registerOverloadInternal(CommandRegistry::Signature &, CommandRegistry::Overload &);
  /// @symbol _ZN15CommandRegistry15registerCommandERKSsPKc22CommandPermissionLevel11CommandFlagS5_
  void registerCommand(mcpe::string const &, char const *, CommandPermissionLevel, CommandFlag, CommandFlag);
  /// @symbol _ZN15CommandRegistry13buildOverloadERNS_8OverloadE
  void buildOverload(CommandRegistry::Overload &);
  template <typename F> void registerCustomOverload(mcpe::string name, CommandVersion version, std::unique_ptr<Command> (*allocator)(), F f) {
    Signature *signature = findCommand(name);
    signature->overloads.emplace_back(version, allocator);
    Overload &overload = *signature->overloads.rbegin();
    buildOverload(overload);
    f(overload);
    registerOverloadInternal(*signature, overload);
  }
  void addSoftEnum(mcpe::string const &name, std::vector<mcpe::string> values, bool case_sensitive);
  void setSoftEnumValues(mcpe::string const &name, std::vector<mcpe::string> values);

  struct ParseToken;
};

using Parser = bool (CommandRegistry::*)(void *, CommandRegistry::ParseToken const &, CommandOrigin const &, int, mcpe::string &, std::vector<mcpe::string> &) const;

class CommandParameterData {

private:
  char filler[40];

public:
  /// @symbol _ZN20CommandParameterDataC2E8typeid_tI15CommandRegistryEMS1_KFbPvRKNS1_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEEEPKc24CommandParameterDataTypeSI_ibi
  CommandParameterData(typeid_t<CommandRegistry>, Parser, char const *, CommandParameterDataType, char const *, int, bool, int);
  /// @symbol _ZN20CommandParameterDataC2ERKS_
  CommandParameterData(CommandParameterData const &);
};