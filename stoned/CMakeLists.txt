cmake_minimum_required(VERSION 3.3)

project(stoned LANGUAGES CXX)

add_executable(stoned
  "src/main.cpp")

set_property(TARGET stoned PROPERTY CXX_STANDARD 17)

target_link_libraries(stoned dbus-api seasocks msgpackc-cxx msgpackc-static)
if (${USE_COTIRE})
  cotire(stoned)
endif()

install(TARGETS stoned RUNTIME DESTINATION bin)