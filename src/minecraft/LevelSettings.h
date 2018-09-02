#pragma once

#include <string.h>
class LevelSettings {

public:

    int seed; // 4
    int gametype; // 8
    int difficulty; // c
    bool forceGameType; // 10
    int generator; // 14
    bool hasAchievementsDisabled; // 18
    int dimension; // 1c
    int time; // 20
    bool edu, immutableWorld; // 21, 22
    float rainLevel, lightningLevel; // 28, 2c
    bool xblBroadcastIntent, mpGame, lanBroadcast, xblBroadcast; // 2d, 2e, 2f, 2e
    int xblLanBroadcastMode; // 34
    bool commandsEnabled; // 35
    bool texturepacksRequired, lockedBehaviourPack, lockedResourcePack, fromLockedTemplate; // 36, 37, 38, 39
    bool overrideSavedSettings; // 3A
    bool bonusChestEnabled, startWithMap; // 3B, 3C
    char filler[0x90 - 0x3C];
    int defaultSpawnX, defaultSpawnY, defaultSpawnZ;
    char filler2[0x300];

    LevelSettings();
    LevelSettings(LevelSettings const& org);

    static int parseSeedString(mcpe::string const&, unsigned int);

};