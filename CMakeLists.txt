cmake_minimum_required (VERSION 2.6)

project(file-util LANGUAGES CXX)

add_library(file-util include/FileUtil.h src/FileUtil.cpp include/EnvPathUtil.h src/EnvPathUtil.cpp)
target_include_directories(file-util PUBLIC include/)