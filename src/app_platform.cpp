#include <mcpelauncher/app_platform.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <hybris/dlfcn.h>

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
bool enablePocketGuis = false;

LauncherAppPlatform::LauncherAppPlatform() : AppPlatform() {
    this->vtable = myVtable;
    dataDir = PathHelper::getPrimaryDataDirectory();
    assetsDir = PathHelper::findDataFile("assets/");
    tmpPath = PathHelper::getCacheDirectory();
    internalStorage = dataDir;
    externalStorage = dataDir;
    currentStorage = dataDir;
    userdata = dataDir;
    userdataPathForLevels = dataDir;
    region = "0xdeadbeef";
}

void LauncherAppPlatform::replaceVtableEntry(void* lib, void** vtable, const char* sym, void* nw) {
    void* sm = hybris_dlsym(lib, sym);
    for (int i = 0; ; i++) {
        if (vtable[i] == nullptr)
            break;
        if (vtable[i] == sm) {
            myVtable[i] = nw;
            return;
        }
    }
}

void LauncherAppPlatform::initVtable(void* lib) {
    void** vt = AppPlatform::myVtable;
    void** vta = &((void**) hybris_dlsym(lib, "_ZTV19AppPlatform_android"))[2];
    // get vtable size
    int size;
    for (size = 2; ; size++) {
        if (vt[size] == nullptr)
            break;
    }
    Log::trace("AppPlatform", "Vtable size = %i", size);

    myVtable = (void**) ::operator new(size * sizeof(void*));
    memcpy(&myVtable[0], &vt[2], (size - 2) * sizeof(void*));

    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android10getDataUrlEv", &LauncherAppPlatform::getDataUrl);
    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android14getUserDataUrlEv", &LauncherAppPlatform::getUserDataUrl);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android14getPackagePathEv", &LauncherAppPlatform::getPackagePath);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform16hideMousePointerEv", &LauncherAppPlatform::hideMousePointer);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform16showMousePointerEv", &LauncherAppPlatform::showMousePointer);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android11swapBuffersEv", &LauncherAppPlatform::swapBuffers);
    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android15getSystemRegionEv", &LauncherAppPlatform::getSystemRegion);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android25getGraphicsTearingSupportEv", &LauncherAppPlatform::getGraphicsTearingSupport);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android9pickImageER20ImagePickingCallback", &LauncherAppPlatform::pickImage);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform8pickFileER18FilePickerSettings", &LauncherAppPlatform::pickFile);
    replaceVtableEntry(lib, vta, "_ZNK11AppPlatform19supportsFilePickingEv", &LauncherAppPlatform::supportsFilePicking);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android22getExternalStoragePathEv", &LauncherAppPlatform::getExternalStoragePath);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android22getInternalStoragePathEv", &LauncherAppPlatform::getInternalStoragePath);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android21getCurrentStoragePathEv", &LauncherAppPlatform::getCurrentStoragePath);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android15getUserdataPathEv", &LauncherAppPlatform::getUserdataPath);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android24getUserdataPathForLevelsEv", &LauncherAppPlatform::getUserdataPathForLevels);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform20getAssetFileFullPathERKSs", &LauncherAppPlatform::getAssetFileFullPath);
    replaceVtableEntry(lib, vta, "_ZNK11AppPlatform14useCenteredGUIEv", &LauncherAppPlatform::useCenteredGUI);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android16getApplicationIdEv", &LauncherAppPlatform::getApplicationId);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android13getFreeMemoryEv", &LauncherAppPlatform::getFreeMemory);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android13getUsedMemoryEv", &LauncherAppPlatform::getUsedMemory);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android22getTotalPhysicalMemoryEv", &LauncherAppPlatform::getTotalPhysicalMemory);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android14getMemoryLimitEv", &LauncherAppPlatform::getMemoryLimit);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android11getDeviceIdEv", &LauncherAppPlatform::getDeviceId);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android18isFirstSnoopLaunchEv", &LauncherAppPlatform::isFirstSnoopLaunch);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android29hasHardwareInformationChangedEv", &LauncherAppPlatform::hasHardwareInformationChanged);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android8isTabletEv", &LauncherAppPlatform::isTablet);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform17setFullscreenModeE14FullscreenMode", &LauncherAppPlatform::setFullscreenMode);
    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android10getEditionEv", &LauncherAppPlatform::getEdition);
    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android16getBuildPlatformEv", &LauncherAppPlatform::getBuildPlatform);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android31calculateAvailableDiskFreeSpaceERKSs", &LauncherAppPlatform::calculateAvailableDiskFreeSpace);
    replaceVtableEntry(lib, vta, "_ZNK19AppPlatform_android25getPlatformUIScalingRulesEv", &LauncherAppPlatform::getPlatformUIScalingRules);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android19getPlatformTempPathEv", &LauncherAppPlatform::getPlatformTempPath);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android14createDeviceIDEv", &LauncherAppPlatform::createDeviceID_old);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android14createDeviceIDERSs", &LauncherAppPlatform::createDeviceID);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android18queueForMainThreadESt8functionIFvvEE", &LauncherAppPlatform::queueForMainThread);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android35getMultiplayerServiceListToRegisterEv", &LauncherAppPlatform::getMultiplayerServiceListToRegister);
    replaceVtableEntry(lib, vta, "_ZN11AppPlatform16allowSplitScreenEv", &LauncherAppPlatform::allowSplitScreen);
    replaceVtableEntry(lib, vta, "_ZN19AppPlatform_android21calculateHardwareTierEv", &LauncherAppPlatform::calculateHardwareTier);
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
