#pragma once

#include <string>
#include <functional>
#include <unistd.h>
#include <sys/param.h>
#include <vector>
#include <mutex>
#include <memory>
#include <log.h>
#include <mcpelauncher/path_helper.h>
#include "patch_utils.h"
#include <minecraft/gl.h>
#include <minecraft/AppPlatform.h>
#include <minecraft/std/function.h>

class ImageData;
class ImagePickingCallback;
class FilePickerSettings;
class GameWindow;

extern bool enablePocketGuis;

class LauncherAppPlatform : public AppPlatform {

private:
    static const char* TAG;

public:
    static void** myVtable;
    static size_t myVtableSize;
    static void initVtable(void* lib);

    mcpe::string region;
    mcpe::string internalStorage, externalStorage, currentStorage, userdata, userdataPathForLevels, tmpPath;

    std::string assetsDir, dataDir;

    std::vector<mcpe::function<void ()>> runOnMainThreadQueue;

    std::mutex runOnMainThreadMutex;

    LauncherAppPlatform();

    mcpe::string getDataUrl() { // this is used only for sounds
        Log::trace(TAG, "getDataUrl: %s", assetsDir.c_str());
        return assetsDir;
    }
    mcpe::string getUserDataUrl() {
        Log::trace(TAG, "getUserDataUrl: %s", dataDir.c_str());
        return dataDir;
    }

    mcpe::string getPackagePath() {
        return assetsDir;
    }

    void hideMousePointer() {}
    void showMousePointer() {}

    void swapBuffers() {
        //printf("swap buffers\n");
    }
    mcpe::string const& getSystemRegion() {
        Log::trace(TAG, "getSystemRegion: %s", region.c_str());
        return region;
    }

    bool getGraphicsTearingSupport() {
        return false;
    }

    void pickImage(ImagePickingCallback& callback) {}
    void pickFile(FilePickerSettings& callback) {}
    bool supportsFilePicking() { return false; }
    mcpe::string& getExternalStoragePath() {
        Log::trace(TAG, "getExternalStoragePath: %s", externalStorage.c_str());
        return externalStorage;
    }
    mcpe::string& getInternalStoragePath() {
        Log::trace(TAG, "getInternalStoragePath: %s", internalStorage.c_str());
        return internalStorage;
    }
    mcpe::string& getCurrentStoragePath() {
        Log::trace(TAG, "getCurrentStoragePath: %s", currentStorage.c_str());
        return currentStorage;
    }
    mcpe::string& getUserdataPath() {
        // Log::trace(TAG, "getUserdataPath: %s", userdata.c_str());
        return userdata;
    }
    mcpe::string& getUserdataPathForLevels() {
        Log::trace(TAG, "getUserdataPathForLevels: %s", userdataPathForLevels.c_str());
        return userdataPathForLevels;
    }
    mcpe::string getAssetFileFullPath(mcpe::string const& s) {
        Log::trace(TAG, "getAssetFileFullPath: %s", s.c_str());
        return mcpe::string(assetsDir + s.std());
    }
    int getScreenType() {
        if (enablePocketGuis)
            return 1;
        return 0; // Win 10 Ed. GUIs
    }
    bool useCenteredGUI() {
        return (enablePocketGuis ? false : true);
    }
    mcpe::string getApplicationId() {
        Log::trace(TAG, "getApplicationId: com.mojang.minecraftpe");
        return "com.mojang.minecraftpe";
    }
    mcpe::string getDeviceId() {
        Log::trace(TAG, "getDeviceId: linux");
        return "linux";
    }
    bool isFirstSnoopLaunch() {
        Log::trace(TAG, "isFirstSnoopLaunch: true");
        return true;
    }
    bool hasHardwareInformationChanged() {
        Log::trace(TAG, "hasHardwareInformationChanged: false");
        return false;
    }
    bool isTablet() {
        Log::trace(TAG, "isTablet: true");
        return true;
    }
    void setFullscreenMode(int mode) {}
    mcpe::string getEdition() {
        if (enablePocketGuis)
            return "pocket";
        return "win10";
    }
    int getBuildPlatform() const {
        return 1;
    }
    int getPlatformUIScalingRules() {
        return enablePocketGuis ? 2 : 0;
    }
    long long getUsedMemory();
    long long getFreeMemory();
    long long getTotalPhysicalMemory();
    long long getMemoryLimit();

    long long calculateAvailableDiskFreeSpace();

    mcpe::string &getPlatformTempPath() {
        return tmpPath;
    }

    mcpe::string createDeviceID_old() {
        return "3f9ac4bea0012efa";
    }

    mcpe::string createDeviceID(std::string const& c) {
        Log::trace(TAG, "createDeviceID: %s", c.c_str());
        return "3f9ac4bea0012efa";
    }

    bool allowSplitScreen() {
        return true;
    }

    void queueForMainThread(mcpe::function<void ()> f) {
        runOnMainThreadMutex.lock();
        runOnMainThreadQueue.push_back(f);
        runOnMainThreadMutex.unlock();
    }
    void runMainThreadTasks() {
        runOnMainThreadMutex.lock();
        auto queue = std::move(runOnMainThreadQueue);
        runOnMainThreadMutex.unlock();
        for (auto const& func : queue)
            func();
    }

    void calculateHardwareTier();

};
