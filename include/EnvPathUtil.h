#pragma once

#include <string>

class EnvPathUtil {

public:
    static std::string getAppDir();

    static std::string getWorkingDir();

    static std::string getHomeDir();

    static std::string getDataHome();

};