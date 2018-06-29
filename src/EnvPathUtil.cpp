#include <EnvPathUtil.h>

#include <stdexcept>
#include <cstring>
#include <climits>
#include <unistd.h>
#include <pwd.h>

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

bool EnvPathUtil::findInPath(std::string const& what, std::string& result, const char* path) {
    if (path == nullptr) {
        path = getenv("PATH");
        if (path == nullptr || strlen(path) == 0)
            path = "/bin:/usr/bin";
    }
    auto appDir = EnvPathUtil::getAppDir() + "/";
    std::string buf;
    while (path != nullptr) {
        const char* pathn = strchr(path, ':');
        size_t len = (pathn - path);
        if (pathn == nullptr)
            len = strlen(path);
        // length 0 should be handled as '.' - in this case, we'll need to append a slash as well
        bool willAppendSlash = (len == 0 || path[len - 1] != '/');
        buf.resize(len + (willAppendSlash ? 1 : 0) + (len == 0 ? 1 : 0) + what.size());
        memcpy(&buf[0], path, len);
        size_t o = len;
        if (len == 0)
            buf[o++] = '.';
        if (willAppendSlash)
            buf[o++] = '/';
        memcpy(&buf[o], what.data(), what.size());
        if (access(buf.c_str(), X_OK) == 0) {
            result = std::move(buf);
            return true;
        }
        path = pathn;
        if (path)
            path++;
    }
    return false;
}