#pragma once

#include <string>

class FileUtil {

public:
    static std::string getParent(std::string const& path);

    static bool exists(std::string const& path);

    static bool isDirectory(std::string const& path);

    static void mkdirRecursive(std::string const& path);

};