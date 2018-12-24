#pragma once

#include <vector>
#include "std/string.h"

class CommandOutputMessage {

public:

    int type;
    mcpe::string messageId;
    std::vector<mcpe::string> params;

};

class CommandOutputParameter;

using CommandOutputMessageType = int;

class CommandOutput {

public:

    std::vector<CommandOutputMessage> const& getMessages() const;

    /// @symbol _ZN13CommandOutput10addMessageERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE24CommandOutputMessageType
    void addMessage(mcpe::string const&, std::vector<CommandOutputParameter> const&, CommandOutputMessageType);

    void success();

};


class CommandOutputParameter {

private:
    mcpe::string str;
    int type;

public:
    CommandOutputParameter(mcpe::string const&);
    CommandOutputParameter(int);

};