#pragma once

#include <minecraft/SharedConstants.h>

class MinecraftVersion {

public:
    static bool isAtLeast(int major, int minor, int patch = -1, int revision = -1) {
        return *SharedConstants::MajorVersion > major || (*SharedConstants::MajorVersion == major &&
            (*SharedConstants::MinorVersion > minor || (*SharedConstants::MinorVersion == minor &&
            (*SharedConstants::PatchVersion > patch || (*SharedConstants::PatchVersion == patch &&
            *SharedConstants::RevisionVersion >= revision)))));
    }

};