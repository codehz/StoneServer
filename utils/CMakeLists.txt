cmake_minimum_required(VERSION 3.0)

add_library(utils
  "src/utils.cpp"
  "include/stone/utils.h"
  "include/stone/static_hook.h"
  "include/stone/symbol.h"
  "include/stone/hook_helper.h"
)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(utils minecraft-symbols mcpelauncher-core hybris)