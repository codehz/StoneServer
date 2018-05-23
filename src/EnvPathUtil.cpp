#include <EnvPathUtil.h>

#include <unistd.h>
#include <pwd.h>
#include <stdexcept>

std::string EnvPathUtil::getWorkingDir() {
    char _cwd[256];
    getcwd(_cwd, 256);
    return std::string(_cwd);
}

std::string EnvPathUtil::getHomeDir() {
    char* env = getenv("HOME");
    if (env != nullptr)
        return env;

    struct passwd pwd;
    long int bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    if (bufsize == -1)
        bufsize = 16384;
    char* buf = new char[bufsize];
    struct passwd *result;
    getpwuid_r(getuid(), &pwd, buf, (size_t) bufsize, &result);
    if (result == nullptr) {
        delete[] buf;
        throw std::runtime_error("getpwuid failed");
    }
    std::string ret(result->pw_dir);
    delete[] buf;
    return ret;
}

std::string EnvPathUtil::getDataHome() {
    char* env = getenv("XDG_DATA_HOME");
    if (env != nullptr)
        return env;
    return getHomeDir() + "/.local/share";
}