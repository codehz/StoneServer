cmake_minimum_required(VERSION 3.0)

project(stone LANGUAGES CXX)

add_executable(stone
  "src/main.cpp"

  "src/utils.cpp"
  "src/utils.h"
  "src/server_properties.h"
)

set_property(TARGET stone PROPERTY CXX_STANDARD 20)
target_compile_options(stone PRIVATE -Wall -Wno-reorder)
target_link_libraries(stone logger mcpelauncher-core properties-parser uintl)

install(TARGETS stone RUNTIME DESTINATION bin)
