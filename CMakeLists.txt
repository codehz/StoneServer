cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-core LANGUAGES CXX)

add_library(mcpelauncher-core include/mcpelauncher/appplatform.h include/mcpelauncher/common.h include/mcpelauncher/hook.h include/mcpelauncher/modloader.h src/appplatform.cpp src/common.cpp src/hook.cpp src/modloader.cpp)
target_include_directories(mcpelauncher-core PUBLIC include/)
target_link_libraries(mcpelauncher-core mcpelauncher-common logger hybris minecraft-symbols)
target_compile_definitions(mcpelauncher-core PRIVATE SERVER) # temporary workaround to make it compile