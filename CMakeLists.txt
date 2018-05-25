cmake_minimum_required (VERSION 2.6)

project(argparser LANGUAGES CXX)

add_library(argparser INTERFACE)
target_include_directories(argparser INTERFACE include/)