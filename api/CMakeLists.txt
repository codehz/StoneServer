cmake_minimum_required (VERSION 3.0)

project(stone-api)

add_library(stone-api INTERFACE)
file(GLOB src "include/stone-api/*")
target_sources(stone-api INTERFACE ${src})
target_link_libraries(stone-api INTERFACE rpcws)
target_include_directories(stone-api INTERFACE "include")


if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(STONE_API_STANDALONE ON)
  option(STONE_API_BUILD_BINARY ON)
else()
  option(STONE_API_BUILD_BINARY OFF)
endif()

if (STONE_API_STANDALONE)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  include(ExternalProject)

  ExternalProject_Add(rpc-websocket
    PREFIX rpc-websocket
    GIT_REPOSITORY https://github.com/CodeHz/wsrpc
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>"
  )

  ExternalProject_Get_property(rpc-websocket INSTALL_DIR)

  include_directories(${INSTALL_DIR}/include)
  link_directories(${INSTALL_DIR}/lib)
endif()
if (STONE_API_BUILD_BINARY)
  add_executable(stone-ping src/ping.cpp)
  target_link_libraries(stone-ping stone-api rpcws rpc ws minsec)
  set_property(TARGET stone-ping PROPERTY CXX_STANDARD 17)

  add_executable(stone-cli src/cli.cpp)
  target_link_libraries(stone-cli stone-api rpcws rpc ws minsec pthread readline)
  set_property(TARGET stone-cli PROPERTY CXX_STANDARD 20)

  add_executable(stone-log src/log.cpp)
  target_link_libraries(stone-log stone-api rpcws rpc ws minsec)
  set_property(TARGET stone-log PROPERTY CXX_STANDARD 20)

  if (STONE_API_STANDALONE)
    add_dependencies(stone-ping rpc-websocket)
    add_dependencies(stone-cli rpc-websocket)
    add_dependencies(stone-log rpc-websocket)
  endif()

  install(TARGETS stone-ping RUNTIME DESTINATION bin)
  install(TARGETS stone-cli RUNTIME DESTINATION bin)
  install(TARGETS stone-log RUNTIME DESTINATION bin)
endif()