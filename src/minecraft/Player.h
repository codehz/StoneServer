#pragma once

#include "std/string.h"
#include <tuple>

class Certificate;

class Player {
public:
    void** vtable;

    mcpe::string *getPlatformOnlineId() const;

    Certificate *getCertificate() const;
    
    /// @symbol _ZNK5Actor6getPosEv
    std::tuple<float, float, float> getPos();

    /// @symbol _ZNK5Actor10isCreativeEv
    bool isCreative();
};