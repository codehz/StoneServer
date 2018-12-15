#pragma once

#include <memory>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include "std/string.h"
#include "std/function.h"
#include "LevelSettings.h"
#include "EventResult.h"

class IMinecraftApp;
class Minecraft;
class Whitelist;
class PermissionsFile;
namespace mce { class UUID; }
class IMinecraftEventing;
class ResourcePackRepository;
class ResourcePackManager;
class ContentTierManager;
class FilePathManager;
class IContentKeyProvider;
class LevelStorage;
class Scheduler;
class LevelData;

class TextFilteringProcessor;

class EducationOptions {
public:
    char filler[0xC];

    EducationOptions(ResourcePackManager*);

};

class ServerInstanceEventListener {
};

class ServerInstanceEventCoordinator {
    std::vector<ServerInstanceEventListener *> listeners;
    std::vector<mcpe::function<EventResult (ServerInstanceEventListener *)>> handlers;
    char filler[36-28];
};

class ServerInstance {

public:

    char filler[0xC];
    Minecraft* minecraft;
    char filler2[0x200];

    /// @symbol _ZN14ServerInstanceC2ER13IMinecraftAppR30ServerInstanceEventCoordinator
    ServerInstance(IMinecraftApp&, ServerInstanceEventCoordinator&);

    /// @symbol _ZN14ServerInstance16initializeServerER13IMinecraftAppR9WhitelistP15PermissionsFileP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISY_EER9SchedulerEERKSsP9LevelDataSsSsSX_I16EducationOptionsSZ_IS1A_EEPSU_SW_IFvS17_EES1F_
    void initializeServer(IMinecraftApp&, Whitelist&, PermissionsFile*, FilePathManager*, std::chrono::seconds, mcpe::string, mcpe::string, mcpe::string, LevelSettings, int, bool, int, int, int, bool, std::vector<mcpe::string> const&, mcpe::string, mce::UUID const&, IMinecraftEventing&, ResourcePackRepository&, ContentTierManager const&, ResourcePackManager&, std::function<std::unique_ptr<LevelStorage> (Scheduler&)>, mcpe::string const&, LevelData*, mcpe::string, mcpe::string, std::unique_ptr<EducationOptions>, ResourcePackManager*, std::function<void (mcpe::string const&)>, std::function<void (mcpe::string const&)>);

    ~ServerInstance();

    void startServerThread();

    void leaveGameSync();

    /// @symbol _ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE
    void queueForServerThread(std::function<void ()>);

};