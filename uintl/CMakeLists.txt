cmake_minimum_required(VERSION 3.3)

project(uintl LANGUAGES CXX)

add_library(uintl
  "src/uintl.cpp"
  "include/uintl.h"
)

target_include_directories(uintl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(uintl sqlite3 mcpelauncher-common)