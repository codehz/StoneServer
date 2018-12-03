cmake_minimum_required(VERSION 3.7)

project(stone LANGUAGES CXX)

include(ExternalProject)

add_executable(stone
  "src/main.cpp"

  "src/server_properties.h"
  "src/server_minecraft_app.h"
  "src/stub_key_provider.h"
  "src/services.h"
)

ExternalProject_Add(
  simppl_ext
  PREFIX "simppl"
  GIT_REPOSITORY "${CMAKE_ROOT_SOURCE_DIR}/cached-exts/simppl"
  GIT_TAG "master"
  PATCH_COMMAND git apply ${CMAKE_CURRENT_SOURCE_DIR}/simppl.patch
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS} -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS} -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR> <SOURCE_DIR>
)
ExternalProject_Get_Property(simppl_ext INSTALL_DIR)

add_library(simppl STATIC IMPORTED)
set_property(TARGET simppl PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/lib/libsimppl.a)
include_directories(simppl INTERFACE ${INSTALL_DIR}/include)

find_path(BOOST_INCLUDE_DIR
     boost/fusion/adapted.hpp
     PATHS /usr/include /usr/local/include
     ONLY_CMAKE_FIND_ROOT_PATH
     NO_DEFAULT_PATH
)

find_path(DBUS_INCLUDE_DIR
    dbus/dbus-bus.h
    PATHS /usr/include /usr/local/include
    PATH_SUFFIXES dbus-1.0
    ONLY_CMAKE_FIND_ROOT_PATH
    NO_DEFAULT_PATH
)

find_path(DBUS_ARCHDEPS_INCLUDE_DIR
    dbus/dbus-arch-deps.h
    PATHS /usr/lib /usr/lib/* /usr/local/lib /usr/local/lib/*
    PATH_SUFFIXES dbus-1.0/include
    ONLY_CMAKE_FIND_ROOT_PATH
    NO_DEFAULT_PATH
)

find_path(DBUS_LIBDIR
    libdbus-1.so
    PATHS /usr/lib /usr/lib/* /usr/local/lib /usr/local/lib/*
    ONLY_CMAKE_FIND_ROOT_PATH
    NO_DEFAULT_PATH
)

if(DBUS_INCLUDE_DIR)
    target_include_directories(simppl INTERFACE ${DBUS_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Didn't find dbus directory")
endif()

if(DBUS_ARCHDEPS_INCLUDE_DIR)
    target_include_directories(simppl INTERFACE ${DBUS_ARCHDEPS_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Didn't find dbus arch-deps directory")
endif()

if(DBUS_LIBDIR)
    link_directories(${DBUS_LIBDIR})
else()
    message(FATAL_ERROR "Didn't find dbus-1 shared library")
endif()

set_property(TARGET stone PROPERTY CXX_STANDARD 17)
target_compile_options(stone PRIVATE -Wall -Wno-reorder -Wno-class-memaccess)
target_link_libraries(stone logger mcpelauncher-core properties-parser utils uintl simppl dbus-1)

install(TARGETS stone RUNTIME DESTINATION bin)
