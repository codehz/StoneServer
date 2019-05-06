cmake_minimum_required (VERSION 3.0)

project(stone-api)

add_library(stone-api INTERFACE)
file(GLOB src "include/stone-api/*")
target_sources(stone-api INTERFACE ${src})
target_link_libraries(stone-api INTERFACE rpcws)
target_include_directories(stone-api INTERFACE "include")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
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

  add_executable(stone-ping src/ping.cpp)
  target_include_directories(stone-ping PRIVATE ${INSTALL_DIR}/include)
  target_link_directories(stone-ping PRIVATE ${INSTALL_DIR}/lib)
  target_link_libraries(stone-ping stone-api rpcws rpc ws minsec)
  set_property(TARGET stone-ping PROPERTY CXX_STANDARD 17)

  add_executable(stone-cli src/cli.cpp)
  target_include_directories(stone-cli PRIVATE ${INSTALL_DIR}/include)
  target_link_directories(stone-cli PRIVATE ${INSTALL_DIR}/lib)
  target_link_libraries(stone-cli stone-api rpcws rpc ws minsec pthread readline)
  set_property(TARGET stone-cli PROPERTY CXX_STANDARD 17)

  add_dependencies(stone-ping rpc-websocket)
  add_dependencies(stone-cli rpc-websocket)
endif()