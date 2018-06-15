#include <EnvPathUtil.h>

#include <stdexcept>
#include <cstring>
#include <climits>
#include <unistd.h>
#include <pwd.h>

#ifdef __APPLE__
#include <sys/param.h>
#include <mach-o/dyld.h>
#endif

std::string EnvPathUtil::getAppDir() {
#ifdef __APPLE__
    char buf[MAXPATHLEN];
    char tbuf[MAXPATHLEN];
    uint32_t size = sizeof(tbuf) - 1;
    if (_NSGetExecutablePath(tbuf, &size) || size <= 0)
        return std::string();
    if (!realpath(tbuf, buf))
        return std::string();
    size = strlen(buf);
#else
    char buf[PATH_MAX];
    ssize_t size = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (size <= 0)
        return std::string();
#endif
    buf[size] = '\0';
    char* dirs = strrchr(buf, '/');
    if (dirs != nullptr)
        dirs[0] = '\0';
    return std::string(buf);
}

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
