cmake_minimum_required (VERSION 2.6)

project(minecraft-symbols LANGUAGES CXX)

set(MINECRAFT_SYMBOLS_SOURCES src/minecraft/symbols.cpp)

if (APPLE)
    set(MINECRAFT_SYMBOLS_SOURCES ${MINECRAFT_SYMBOLS_SOURCES} src/minecraft/std/string_darwin.cpp)
else()
    set(MINECRAFT_SYMBOLS_SOURCES ${MINECRAFT_SYMBOLS_SOURCES} src/minecraft/std/string_linux.cpp)
endif()

add_library(minecraft-symbols ${MINECRAFT_SYMBOLS_SOURCES})
set_property(TARGET minecraft-symbols PROPERTY CXX_STANDARD 17)
target_include_directories(minecraft-symbols PUBLIC src/)
target_link_libraries(minecraft-symbols logger hybris)