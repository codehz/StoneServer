cmake_minimum_required(VERSION 3.3)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(SEASOCKS_ROOT_PATH ${CMAKE_CURRENT_BINARY_DIR})

project(Seasocks VERSION 1.4.1)


option(SEASOCKS_UNITTESTS "Build seasocks unittests." OFF)
option(SEASOCKS_COVERAGE "Build seasocks with code coverage enabled" OFF)
option(SESOCKS_DEFLATE_SUPPORT "Include support for deflate (requires zlib)." ON)
if (SESOCKS_DEFLATE_SUPPORT)
    set(SEASOCKS_DEFLATE_SUPPORT_BOOL "true")
else ()
    set(SEASOCKS_DEFLATE_SUPPORT_BOOL "false")
endif ()
message(STATUS "${PROJECT_NAME} ${VERSION}")
message(STATUS "Seasocks Unittests: ${SEASOCKS_UNITTESTS}")
message(STATUS "Seasocks Coverage: ${SEASOCKS_COVERAGE}")


set(SEASOCKS_MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/src/test/suppressions.txt" CACHE INTERNAL "")
include(CTest)
include(Compiler)
include(GNUInstallDirs)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.h.in internal/Config.h)
include_directories(${CMAKE_BINARY_DIR})
add_compile_options(-Wall -Werror -Wextra -pedantic)
if (SEASOCKS_COVERAGE)
    add_compile_options(--coverage -O0)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif ()

find_package(Threads)


find_program(PYTHON_BIN python DOC "Python executable")

if (NOT PYTHON_BIN)
    message(SEND_ERROR "Python not found")
else()
    message(STATUS "Using Python: '${PYTHON_BIN}'")
endif ()

if (SESOCKS_DEFLATE_SUPPORT)
    find_package(ZLIB REQUIRED)
endif ()

add_subdirectory("src")

