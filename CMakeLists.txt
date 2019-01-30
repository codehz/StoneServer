cmake_minimum_required(VERSION 3.13)

project(apid)
enable_language(C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(ae ae/ae.c ae/zmalloc.c)

add_library(hiredis hiredis/hiredis.c hiredis/async.c hiredis/sds.c hiredis/net.c hiredis/read.c)

add_library(apid src/apid.c)
target_include_directories(apid PRIVATE ae hiredis)
target_link_libraries(apid hiredis ae)

add_executable(apid-test tests/test.c)
target_link_libraries(apid-test apid)

add_executable(apid-test-client tests/test-client.c)
target_link_libraries(apid-test-client apid)