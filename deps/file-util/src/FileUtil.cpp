#include <FileUtil.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdexcept>

bool FileUtil::exists(std::string const& path) {
    return access(path.c_str(), F_OK) == 0;
}

bool FileUtil::isDirectory(std::string const& path) {
    struct stat s;
    stat(path.c_str(), &s);
    return S_ISDIR(s.st_mode);
}

std::string FileUtil::getParent(std::string const& path) {
    auto iof = path.rfind('/');
    if (iof == std::string::npos)
        return std::string();
    while (iof > 0 && path[iof - 1] == '/')
        iof--;
    return path.substr(0, iof);
}

void FileUtil::mkdirRecursive(std::string const& path) {
    if (isDirectory(path))
        return;
    if (exists(path))
        throw std::runtime_error(std::string("File exists and is not a directory: ") + path);
    mkdirRecursive(getParent(path));
    if (mkdir(path.c_str(), 0744) != 0)
        throw std::runtime_error(std::string("mkdir failed, path = ") + path);
}