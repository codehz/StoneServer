cmake_minimum_required (VERSION 2.6)

project(dbus-api LANGUAGES CXX)

add_library(dbus-api INTERFACE)
file(GLOB src "include/dbus-api/*")
target_sources(dbus-api INTERFACE ${src})
target_compile_definitions(dbus-api INTERFACE SIMPPL_HAVE_INTROSPECTION=true)
target_link_libraries(dbus-api INTERFACE simppl)
target_include_directories(dbus-api INTERFACE "include")

add_executable(dbus-api-test src/test.cpp)
target_link_libraries(dbus-api-test PRIVATE dbus-api)