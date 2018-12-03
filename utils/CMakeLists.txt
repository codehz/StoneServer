cmake_minimum_required(VERSION 3.0)

add_library(utils
  "src/utils.cpp"
  "include/stone/utils.h"
)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)