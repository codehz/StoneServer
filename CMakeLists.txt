cmake_minimum_required (VERSION 2.6)

project(base64 LANGUAGES CXX)

add_library(base64 include/base64.h src/base64.cpp)
target_include_directories(base64 PUBLIC include/)