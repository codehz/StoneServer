cmake_minimum_required (VERSION 2.6)

project(logger LANGUAGES CXX)

add_library(logger include/log.h src/log.cpp)
target_link_libraries(logger)
target_include_directories(logger PUBLIC include/)