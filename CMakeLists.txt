cmake_minimum_required (VERSION 3.0)

project(stone-api)

add_library(stone-api INTERFACE)
file(GLOB src "include/stone-api/*")
target_sources(stone-api INTERFACE ${src})
target_link_libraries(stone-api INTERFACE apid ae)
target_include_directories(stone-api INTERFACE "include")

add_executable(stone-client src/client.cpp)
target_link_libraries(stone-client stone-api)
set_property(TARGET stone-client PROPERTY CXX_STANDARD 17)