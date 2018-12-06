cmake_minimum_required (VERSION 2.6)

project(interface LANGUAGES CXX)

add_library(interface INTERFACE)
file(GLOB src "include/interface/*")
target_sources(interface INTERFACE ${src})
target_include_directories(interface INTERFACE "include" ${CMAKE_ROOT_SOURCE_DIR}/deps/minecraft-symbols/src)