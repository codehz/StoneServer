#pragma once

#include <memory>
#include "std/string.h"

class CommandOrigin;
class CommandOutputSender;

enum class MCCATEGORY : unsigned char {
    //
};

struct MCRESULT {
    bool success;
    MCCATEGORY category;
    unsigned short code;
};

class MinecraftCommands {

public:

    void setOutputSender(std::unique_ptr<CommandOutputSender> sender);

    MCRESULT requestCommandExecution(std::unique_ptr<CommandOrigin> o, mcpe::string const& s, int i, bool b) const;

};