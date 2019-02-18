#pragma once

#include "std/string.h"
#include <vector>

class CommandOutputMessage {

public:
  int type;
  mcpe::string messageId;
  std::vector<mcpe::string> params;
};

class CommandOutputParameter;

enum class CommandOutputMessageType {
  SUCCESS = 0,
  FAILED  = 1,
};

class CommandOutput {

public:
  std::vector<CommandOutputMessage> const &getMessages() const;

  /// @symbol _ZN13CommandOutput10addMessageERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE24CommandOutputMessageType
  void addMessage(mcpe::string const &, std::vector<CommandOutputParameter> const &, CommandOutputMessageType);

  /// @symbol _ZN13CommandOutput5errorERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE
  void error(mcpe::string const &, std::vector<CommandOutputParameter> const &);

  /// @symbol _ZN13CommandOutput7successERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE
  void success(mcpe::string const &, std::vector<CommandOutputParameter> const &);

  void success();
};

class CommandOutputParameter {

private:
  mcpe::string str;
  int type;

public:
  CommandOutputParameter(mcpe::string const &);
  CommandOutputParameter(int);
};