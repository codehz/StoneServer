#pragma once

#include <vector>
#include "std/string.h"

class ResourcePackManager;

class ResourceLoadManager{
    char filler[0x36];
public:
    ResourceLoadManager();
    void setAppSuspended(bool);
};

class I18n {

public:
    static mcpe::string get(mcpe::string const&, std::vector<mcpe::string> const&);
    static void chooseLanguage(mcpe::string const&);
    static void loadLanguages(ResourcePackManager&, ResourceLoadManager&, mcpe::string const&);

};