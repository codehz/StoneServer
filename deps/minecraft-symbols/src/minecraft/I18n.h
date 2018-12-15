#pragma once

#include <vector>
#include "std/string.h"

class ResourcePackManager;

enum class ResourceLoadType;

class ResourceLoadManager{
    char filler[0x36];
public:
    ResourceLoadManager();
    void sync(ResourceLoadType);
};

class I18n {

public:
    static mcpe::string get(mcpe::string const&, std::vector<mcpe::string> const&);
    static void chooseLanguage(mcpe::string const&);
    static void loadLanguages(ResourcePackManager&, ResourceLoadManager&, mcpe::string const&);

};