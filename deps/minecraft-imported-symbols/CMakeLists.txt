cmake_minimum_required (VERSION 2.6)

project(minecraft-imported-symbols LANGUAGES CXX)

add_library(minecraft-imported-symbols INTERFACE)
target_include_directories(minecraft-imported-symbols INTERFACE include/)