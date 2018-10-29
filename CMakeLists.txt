cmake_minimum_required (VERSION 2.6)

project(mcpelauncher-common LANGUAGES CXX)

find_library(OpenSSL OPTIONAL)

set(MCPELAUNCHER_COMMON_SOURCES include/mcpelauncher/path_helper.h src/path_helper.cpp)
if (OPENSSL_FOUND)
    set(MCPELAUNCHER_COMMON_SOURCES ${MCPELAUNCHER_COMMON_SOURCES} src/openssl_multithread.h src/openssl_multithread.cpp)
endif()
if (APPLE)
    set(MCPELAUNCHER_COMMON_SOURCES ${MCPELAUNCHER_COMMON_SOURCES} src/path_helper_osx.mm)
endif()

add_library(mcpelauncher-common ${MCPELAUNCHER_COMMON_SOURCES})
target_include_directories(mcpelauncher-common PUBLIC include/)
if (OPENSSL_FOUND)
    target_link_libraries(mcpelauncher-common ${OPENSSL_CRYPTO_LIBRARY})
endif()
if (APPLE)
    target_link_libraries(mcpelauncher-common "-framework Foundation")
endif()
