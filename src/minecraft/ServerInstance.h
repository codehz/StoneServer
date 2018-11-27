#pragma once

#include <memory>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include "std/string.h"
#include "LevelSettings.h"

class IMinecraftApp;
class Minecraft;
class Whitelist;
class PermissionsMap;
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

class ServerInstance {

public:

    char filler[0xC];
    Minecraft* minecraft;
    char filler2[0x200];

    /// @symbol _ZN14ServerInstanceC2ER13IMinecraftAppR9WhitelistRK14PermissionsMapP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISZ_EER9SchedulerEERKSsP9LevelDataP22TextFilteringProcessorPSV_SX_IFvS18_EES1F_
    ServerInstance(IMinecraftApp&, Whitelist&, PermissionsMap const&, FilePathManager*, std::chrono::seconds, mcpe::string, mcpe::string, mcpe::string, LevelSettings, int, bool, int, int, int, bool, std::vector<mcpe::string> const&, mcpe::string, mce::UUID const&, IMinecraftEventing&, ResourcePackRepository&, ContentTierManager const&, ResourcePackManager&, std::function<std::unique_ptr<LevelStorage> (Scheduler&)>, mcpe::string const&, LevelData*, TextFilteringProcessor* filter, ResourcePackManager*, std::function<void (mcpe::string const&)>, std::function<void (mcpe::string const&)>);

    ~ServerInstance();

    void startServerThread();

    void leaveGameSync();

    /// @symbol _ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE
    void queueForServerThread(std::function<void ()>);

};