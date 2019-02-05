#include <mcpelauncher/app_platform.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <hybris/dlfcn.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <minecraft/Crypto.h>

#ifdef __APPLE__
#include <stdint.h>
#include <sys/sysctl.h>
#include <mach/host_info.h>
#include <mach/mach_host.h>
#else
#include <sys/sysinfo.h>
#endif

const char* LauncherAppPlatform::TAG = "AppPlatform";

void** LauncherAppPlatform::myVtable = nullptr;
size_t LauncherAppPlatform::myVtableSize;
bool enablePocketGuis = false;

LauncherAppPlatform::LauncherAppPlatform() : AppPlatform() {
    this->vtable = myVtable;
    dataDir = PathHelper::getPrimaryDataDirectory();
    assetsDir = PathHelper::findGameFile("assets/");
    tmpPath = PathHelper::getCacheDirectory();
    internalStorage = dataDir;
    externalStorage = dataDir;
    currentStorage = dataDir;
    userdata = dataDir;
    userdataPathForLevels = dataDir;
    region = "en_US";
}

void LauncherAppPlatform::initVtable(void* lib) {
    void** vt = AppPlatform::myVtable;
    void** vta = &((void**) hybris_dlsym(lib, "_ZTV19AppPlatform_android"))[2];
    myVtableSize = PatchUtils::getVtableSize(vta);
    Log::trace("AppPlatform", "Vtable size = %u", myVtableSize);

    myVtable = (void**) ::operator new((myVtableSize + 1) * sizeof(void*));
    myVtable[myVtableSize] = nullptr;
    memcpy(&myVtable[0], &vt[2], (myVtableSize - 2) * sizeof(void*));

    PatchUtils::VtableReplaceHelper vtr (lib, myVtable, vta);
    vtr.replace("_ZNK19AppPlatform_android10getDataUrlEv", &LauncherAppPlatform::getDataUrl);
    vtr.replace("_ZNK19AppPlatform_android14getUserDataUrlEv", &LauncherAppPlatform::getUserDataUrl);
    vtr.replace("_ZN19AppPlatform_android14getPackagePathEv", &LauncherAppPlatform::getPackagePath);
    vtr.replace("_ZN11AppPlatform16hideMousePointerEv", &LauncherAppPlatform::hideMousePointer);
    vtr.replace("_ZN11AppPlatform16showMousePointerEv", &LauncherAppPlatform::showMousePointer);
    vtr.replace("_ZN19AppPlatform_android11swapBuffersEv", &LauncherAppPlatform::swapBuffers);
    vtr.replace("_ZNK19AppPlatform_android15getSystemRegionEv", &LauncherAppPlatform::getSystemRegion);
    vtr.replace("_ZN19AppPlatform_android25getGraphicsTearingSupportEv", &LauncherAppPlatform::getGraphicsTearingSupport);
    vtr.replace("_ZN19AppPlatform_android9pickImageESt10shared_ptrI20ImagePickingCallbackE", &LauncherAppPlatform::pickImage);
    vtr.replace("_ZN19AppPlatform_android9pickImageER20ImagePickingCallback", &LauncherAppPlatform::pickImageOld);
    vtr.replace("_ZN11AppPlatform8pickFileER18FilePickerSettings", &LauncherAppPlatform::pickFile);
    vtr.replace("_ZNK11AppPlatform19supportsFilePickingEv", &LauncherAppPlatform::supportsFilePicking);
    vtr.replace("_ZN19AppPlatform_android22getExternalStoragePathEv", &LauncherAppPlatform::getExternalStoragePath);
    vtr.replace("_ZN19AppPlatform_android22getInternalStoragePathEv", &LauncherAppPlatform::getInternalStoragePath);
    vtr.replace("_ZN19AppPlatform_android21getCurrentStoragePathEv", &LauncherAppPlatform::getCurrentStoragePath);
    vtr.replace("_ZN19AppPlatform_android15getUserdataPathEv", &LauncherAppPlatform::getUserdataPath);
    vtr.replace("_ZN19AppPlatform_android24getUserdataPathForLevelsEv", &LauncherAppPlatform::getUserdataPathForLevels);
    vtr.replace("_ZN11AppPlatform20getAssetFileFullPathERKSs", &LauncherAppPlatform::getAssetFileFullPath);
    vtr.replace("_ZNK11AppPlatform14useCenteredGUIEv", &LauncherAppPlatform::useCenteredGUI);
    vtr.replace("_ZN19AppPlatform_android16getApplicationIdEv", &LauncherAppPlatform::getApplicationId);
    vtr.replace("_ZN19AppPlatform_android13getFreeMemoryEv", &LauncherAppPlatform::getFreeMemory); // legacy
    vtr.replace("_ZNK19AppPlatform_android13getFreeMemoryEv", &LauncherAppPlatform::getFreeMemory);
    vtr.replace("_ZN19AppPlatform_android13getUsedMemoryEv", &LauncherAppPlatform::getUsedMemory);
    vtr.replace("_ZN19AppPlatform_android22getTotalPhysicalMemoryEv", &LauncherAppPlatform::getTotalPhysicalMemory); // legacy
    vtr.replace("_ZNK19AppPlatform_android22getTotalPhysicalMemoryEv", &LauncherAppPlatform::getTotalPhysicalMemory);
    vtr.replace("_ZN19AppPlatform_android14getMemoryLimitEv", &LauncherAppPlatform::getMemoryLimit); // legacy
    vtr.replace("_ZNK19AppPlatform_android14getMemoryLimitEv", &LauncherAppPlatform::getMemoryLimit);
    vtr.replace("_ZN19AppPlatform_android11getDeviceIdEv", &LauncherAppPlatform::getDeviceId);
    vtr.replace("_ZN19AppPlatform_android18isFirstSnoopLaunchEv", &LauncherAppPlatform::isFirstSnoopLaunch);
    vtr.replace("_ZN19AppPlatform_android29hasHardwareInformationChangedEv", &LauncherAppPlatform::hasHardwareInformationChanged);
    vtr.replace("_ZN19AppPlatform_android8isTabletEv", &LauncherAppPlatform::isTablet);
    vtr.replace("_ZN11AppPlatform17setFullscreenModeE14FullscreenMode", &LauncherAppPlatform::setFullscreenMode);
    vtr.replace("_ZNK19AppPlatform_android10getEditionEv", &LauncherAppPlatform::getEdition);
    vtr.replace("_ZNK19AppPlatform_android16getBuildPlatformEv", &LauncherAppPlatform::getBuildPlatform);
    vtr.replace("_ZNK19AppPlatform_android17getPlatformStringEv", &LauncherAppPlatform::getPlatformString);
    vtr.replace("_ZNK19AppPlatform_android20getSubPlatformStringEv", &LauncherAppPlatform::getSubPlatformString);
    vtr.replace("_ZN19AppPlatform_android31calculateAvailableDiskFreeSpaceERKSs", &LauncherAppPlatform::calculateAvailableDiskFreeSpace);
    vtr.replace("_ZNK19AppPlatform_android25getPlatformUIScalingRulesEv", &LauncherAppPlatform::getPlatformUIScalingRules);
    vtr.replace("_ZN19AppPlatform_android19getPlatformTempPathEv", &LauncherAppPlatform::getPlatformTempPath);
    vtr.replace("_ZN19AppPlatform_android14createDeviceIDEv", &LauncherAppPlatform::createDeviceID_old);
    vtr.replace("_ZN19AppPlatform_android14createDeviceIDERSs", &LauncherAppPlatform::createDeviceID);
    vtr.replace("_ZN19AppPlatform_android18queueForMainThreadESt8functionIFvvEE", &LauncherAppPlatform::queueForMainThread);
    vtr.replace("_ZN11AppPlatform16allowSplitScreenEv", &LauncherAppPlatform::allowSplitScreen);
    vtr.replace("_ZN19AppPlatform_android21calculateHardwareTierEv", &LauncherAppPlatform::calculateHardwareTier);
    vtr.replace("_ZNK11AppPlatform17supportsScriptingEv", &LauncherAppPlatform::supportsScripting);
    vtr.replace("_ZNK19AppPlatform_android17supportsScriptingEv", &LauncherAppPlatform::supportsScripting);
    vtr.replace("_ZN19AppPlatform_android21getBroadcastAddressesEv", &LauncherAppPlatform::getBroadcastAddresses);

    vtr.replace("_ZN19AppPlatform_android35getMultiplayerServiceListToRegisterEv", hybris_dlsym(lib, "_ZN19AppPlatform_android35getMultiplayerServiceListToRegisterEv"));
    vtr.replace("_ZN19AppPlatform_android36getBroadcastingMultiplayerServiceIdsEbb", hybris_dlsym(lib, "_ZN19AppPlatform_android36getBroadcastingMultiplayerServiceIdsEbb"));
}

long long LauncherAppPlatform::calculateAvailableDiskFreeSpace() {
    struct statvfs buf;
    statvfs(dataDir.c_str(), &buf);
    return (long long int) buf.f_bsize * buf.f_bfree;
}

long long LauncherAppPlatform::getUsedMemory() {
#ifdef __APPLE__
    uint64_t page_size;
    size_t len = sizeof(page_size);
    sysctlbyname("hw.pagesize", &page_size, &len, NULL, 0);

    struct vm_statistics64 stat;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t) &stat, &count);

    double page_K = page_size / (double) 1024;
    return (stat.active_count + stat.wire_count) * page_K * 1000;
#else
    FILE* file = fopen("/proc/self/statm", "r");
    if (file == nullptr)
        return 0L;
    int pageSize = getpagesize();
    long long pageCount = 0L;
    fscanf(file, "%lld", &pageCount);
    fclose(file);
    return pageCount * pageSize;
#endif
}

long long LauncherAppPlatform::getFreeMemory() {
#ifdef __APPLE__
    uint64_t page_size;
    size_t len = sizeof(page_size);
    sysctlbyname("hw.pagesize", &page_size, &len, NULL, 0);

    struct vm_statistics64 stat;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t) &stat, &count);

    double page_K = page_size / (double) 1024;
    return stat.free_count * page_K * 1000;
#else
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    long long total = memInfo.freeram;
    total *= memInfo.mem_unit;
    return total;
#endif
}

long long LauncherAppPlatform::getTotalPhysicalMemory() {
#ifdef __APPLE__
    uint64_t memsize;
    size_t len = sizeof(memsize);
    sysctlbyname("hw.memsize", &memsize, &len, NULL, 0);
    return memsize;
#else
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    long long total = memInfo.totalram;
    total *= memInfo.mem_unit;
    return total;
#endif
}

long long LauncherAppPlatform::getMemoryLimit() {
    return getTotalPhysicalMemory();
}

void LauncherAppPlatform::calculateHardwareTier() {
    hardwareTier = 3;
}

std::vector<mcpe::string> LauncherAppPlatform::getBroadcastAddresses() {
    struct ifaddrs *ifaddrs = nullptr;
    if (getifaddrs(&ifaddrs) != 0)
        return std::vector<mcpe::string>();
    std::vector<mcpe::string> retval;
    for (struct ifaddrs *ifaddr = ifaddrs; ifaddr; ifaddr = ifaddr->ifa_next) {
        if (!(ifaddr->ifa_flags & IFF_BROADCAST))
            continue;
#ifdef __APPLE__
        auto addr = ifaddr->ifa_dstaddr;
#else
        auto addr = ifaddr->ifa_ifu.ifu_broadaddr;
#endif
        if (addr == nullptr)
            continue;
        if (addr->sa_family == AF_INET) {
            char buf[INET_ADDRSTRLEN] = {0};
            if (!inet_ntop(addr->sa_family, &((sockaddr_in*) addr)->sin_addr, buf, sizeof(buf)))
                continue;
            retval.emplace_back(buf);
        }
        if (addr->sa_family == AF_INET6) {
            char buf[INET6_ADDRSTRLEN] = {0};
            if (!inet_ntop(addr->sa_family, &((sockaddr_in6*) addr)->sin6_addr, buf, sizeof(buf)))
                continue;
            retval.emplace_back(buf);
        }
    }
    freeifaddrs(ifaddrs);
    return retval;
}

mcpe::string LauncherAppPlatform::createDeviceID(mcpe::string &error) {
    auto deviceIdFile = PathHelper::getPrimaryDataDirectory() + "deviceid.txt";
    {
        std::ifstream in (deviceIdFile);
        if (in) {
            std::string deviceId;
            if (std::getline(in, deviceId) && !in.eof() && !deviceId.empty()) {
                Log::trace(TAG, "createDeviceID (from file): %s", deviceId.c_str());
                return deviceId;
            }
        }
    }
    auto deviceId = Crypto::Random::generateUUID().asString();
    {
        std::ofstream out (deviceIdFile);
        out << deviceId << std::endl;
    }
    Log::trace(TAG, "createDeviceID (created new): %s", deviceId.c_str());
    return deviceId;
}