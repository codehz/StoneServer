#pragma once

#include <string>
#include <vector>
#include <map>
#include <elf.h>

class HookManager {

private:

    struct soinfo_hookinfo {
        struct hook_section {
            Elf32_Off addr, size;
        };
        std::vector<hook_section> hookSections;
    };

    static std::map<void*, soinfo_hookinfo> hookLibraries;

    static bool patchSection(Elf32_Addr base, Elf32_Word off, Elf32_Word size, void* sym, void* override);

    static bool patchLibrary(void* lib, void* sym, void* override);

public:

    static void addHookLibrary(void *ptr, const std::string &path);

    static int hookFunction(void *symbol, void *hook, void **original);

};