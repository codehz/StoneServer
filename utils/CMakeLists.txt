cmake_minimum_required(VERSION 3.0)

project(utils LANGUAGES CXX)

add_library(utils
  "src/utils.cpp"
  "src/server_hook.cpp"
  "include/stone/utils.h"
  "include/stone/static_hook.h"
  "include/stone/server_hook.h"
  "include/stone/symbol.h"
  "include/stone/hook_helper.h"
  "include/stone/field_access.h"
)

set_property(TARGET utils PROPERTY CXX_STANDARD 17)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(utils minecraft-symbols mcpelauncher-core hybris)