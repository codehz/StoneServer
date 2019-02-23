#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <elf.h>

class HookManager {

private:
    struct HookedSymbol;
    class LibInfo;
public:
    struct HookInstance {
    private:
        friend class HookManager;
        HookedSymbol* symbol;
        HookInstance* parent = nullptr;
        HookInstance* child = nullptr;
        void* replacement;
        void** orig = nullptr;
    };

private:
    struct LibSymbolPair {
        LibInfo* lib;
        Elf32_Word symbolIndex;

        bool operator==(LibSymbolPair const& o) const {
            return lib == o.lib && symbolIndex == o.symbolIndex;
        }
    };
    struct LibSymbolPairHash {
        std::size_t operator()(const HookManager::LibSymbolPair &k) const {
            return (((size_t) (void*) k.lib) << 11) | k.symbolIndex;
        }
    };
    struct HookedSymbol {
        LibInfo* lib;
        Elf32_Word symbolIndex;

        void* original = nullptr;
        HookInstance* firstHook = nullptr;
        HookInstance* lastHook = nullptr;
    };

    class LibInfo {

    private:
        friend class HookManager;
        void* handle;
        void* base;

        const char* strtab = nullptr;
        Elf32_Sym* symtab = nullptr;
        Elf32_Rel* rel = nullptr;
        Elf32_Word relsz = 0;
        Elf32_Rel* pltrel = nullptr;
        Elf32_Word pltrelsz = 0;
        void* relro = nullptr;
        Elf32_Word relrosize = 0;

        std::unordered_map<Elf32_Word, std::shared_ptr<HookedSymbol>> hookedSymbols;

        std::vector<void*> dependencies;

        LibInfo(void* handle);


        void applyHooks(Elf32_Rel* rel, Elf32_Word relsz);

    public:
        const char* getSymbolName(Elf32_Word symbolIndex);

        void setHook(Elf32_Word symbolIndex, std::shared_ptr<HookedSymbol> hook);

        void setHook(const char* symbolName, std::shared_ptr<HookedSymbol> hook);

        void applyHooks();

    };

    std::unordered_map<void*, std::unique_ptr<LibInfo>> libs;
    std::unordered_map<void*, std::vector<LibInfo*>> dependents;
    std::unordered_map<LibSymbolPair, std::shared_ptr<HookedSymbol>, LibSymbolPairHash> hookedSymbols;

    HookedSymbol* getOrCreateHookSymbol(void* lib, Elf32_Word symbolIndex);

    static Elf32_Word getSymbolIndex(void* lib, const char* symbolName);

public:
    static HookManager instance;

    void addLibrary(void* handle);

    void removeLibrary(void* handle);

    HookInstance* createHook(void* lib, Elf32_Word symbolIndex, void* replacement, void** orig);

    HookInstance* createHook(void* lib, const char* symbolName, void* replacement, void** orig);

    void deleteHook(HookInstance* hook);

    void applyHooks();

    static std::string translateConstructorName(const char *name);

};