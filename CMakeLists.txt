cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-just LANGUAGES CXX)

add_executable(mcpelauncher-just src/main.cpp)
target_link_libraries(mcpelauncher-just logger mcpelauncher-core properties-parser)
