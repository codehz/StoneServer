#pragma once

#include "std/string.h"
#include <tuple>

class Certificate;

class Player {
public:
    explicit Player(Player const &) = delete;

    void** vtable;

    mcpe::string *getPlatformOnlineId() const;

    Certificate *getCertificate() const;
    
    /// @symbol _ZNK5Actor6getPosEv
    std::tuple<float, float, float> &getPos() const;

    /// @symbol _ZNK5Actor11getRotationEv
    std::pair<float, float> getRotation() const;

    /// @symbol _ZNK5Actor10isCreativeEv
    bool isCreative();

    float getLevelProgress() const;
};