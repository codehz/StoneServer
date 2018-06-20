#pragma once

#include <string>
#include <vector>

class PathHelper {

private:
    static std::string const appDirName;

    struct PathInfo {
        std::string appDir;
        std::string homeDir;
        std::string dataHome;
        std::vector<std::string> dataDirs;
        std::string cacheHome;
        std::string overrideDataDir;
        std::string gameDir;

        PathInfo();
    };

    static PathInfo pathInfo;

    static std::string findUserHome();

    static std::string findAppDir();

public:

    static bool fileExists(std::string const& path);

    static std::string getParentDir(std::string const& path);

    static std::string getWorkingDir();

    static std::string findDataFile(std::string const& path);

    static std::string getPrimaryDataDirectory() {
        if (!pathInfo.overrideDataDir.empty())
            return pathInfo.overrideDataDir;
        return pathInfo.dataHome + "/" + appDirName + "/";
    }

    static std::string getCacheDirectory() {
        if (!pathInfo.overrideDataDir.empty())
            return pathInfo.overrideDataDir;
        return pathInfo.cacheHome + "/" + appDirName + "/";
    }

    static std::string getGameDir() {
        if (!pathInfo.gameDir.empty())
            return pathInfo.gameDir;
        return getPrimaryDataDirectory();
    }

    static void setGameDir(std::string gameDir) {
        if (!gameDir.empty() && gameDir[gameDir.length() - 1] != '/')
            gameDir += '/';
        pathInfo.gameDir = std::move(gameDir);
    }

    static std::string getIconPath() {
        return findDataFile("mcpelauncher-icon.png");
    }

};
