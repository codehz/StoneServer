#pragma once

#include <memory>
#include "Resource.h"

enum class ResourceFileSystem;

class ResourceLoader {
};

class ResourceLoaders {

public:
    static void registerLoader(ResourceFileSystem, std::unique_ptr<ResourceLoader>);

};