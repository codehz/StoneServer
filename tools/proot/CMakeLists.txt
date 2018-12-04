cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

ExternalProject_Add(
  proot
  PREFIX result
  GIT_REPOSITORY ${CMAKE_CURRENT_SOURCE_DIR}/source
  BUILD_IN_SOURCE TRUE
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND cd src && env make CC=${CMAKE_CURRENT_SOURCE_DIR}/gcc-wrapper
  INSTALL_COMMAND cd src && cmake -E copy <SOURCE_DIR>/src/proot <INSTALL_DIR>/proot
)