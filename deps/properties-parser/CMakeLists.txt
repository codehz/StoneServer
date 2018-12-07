cmake_minimum_required (VERSION 2.6)

project(properties-parser LANGUAGES CXX)

add_library(properties-parser INTERFACE)
target_include_directories(properties-parser INTERFACE include/)