cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-common LANGUAGES CXX)

add_library(mcpelauncher-common include/openssl_multithread.h include/path_helper.h src/openssl_multithread.cpp src/path_helper.cpp)
target_include_directories(mcpelauncher-common PUBLIC include/)