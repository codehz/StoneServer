#pragma once

#include "std/string.h"

class LevelSettings {

public:
  int seed;                                                    // 4
  int gametype;                                                // 8
  int difficulty;                                              // c
  bool forceGameType;                                          // 10
  int generator;                                               // 14
  bool achievementsDisabled;                                   // 18
  int dimension;                                               // 1c
  int time;                                                    // 20
  bool edu, eduFeatures, immutableWorld;                       // 21, 22, 23
  float rainLevel, lightningLevel;                             // 28, 2c
  bool xblBroadcastIntent, mpGame, lanBroadcast, xblBroadcast; // 2d, 2e, 2f, 2e
  int xblLanBroadcastMode;                                     // 34
  int platformBroadcastIntent;                                 // 38
  bool commandsEnabled;                                        // 39
  bool texturepacksRequired;                                   // 3A
  bool hasLockedBehaviorPack;                                  // 3B
  bool hasLockedResourcePack;                                  // 3C
  bool fromLockedTemplate;                                     // 3D
  bool msaGamertagsOnly;                                       // 3E
  bool overrideSavedSettings;                                  // 3F
  bool bonusChestEnabled, startWithMap;                        // 40, 41
  unsigned serverChunkTickRange;                               // 48
  bool experimentalGameplay;                                   // 4C
  char filler[0x94 - 0x4C];
  int defaultSpawnX, defaultSpawnY, defaultSpawnZ;
  char filler2[0x300];

  LevelSettings();
  LevelSettings(LevelSettings const &org);

  ~LevelSettings();

  static int parseSeedString(mcpe::string const &, unsigned int);
};