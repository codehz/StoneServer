cmake_minimum_required (VERSION 3.0)

project(stone-api)

add_library(stone-api INTERFACE)
file(GLOB src "include/stone-api/*")
target_sources(stone-api INTERFACE ${src})
target_link_libraries(stone-api INTERFACE rpcws)
target_include_directories(stone-api INTERFACE "include")