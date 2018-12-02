cmake_minimum_required(VERSION 3.3)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(GetGitRevisionDescription)
git_describe(VERSION --always --tags --dirty=-modified --long --abbrev=40)
add_compile_options(-DBUILD_VERSION=\"${VERSION}\")

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif()

string(TIMESTAMP BUILD_TIMESTAMP "%Y%m%d-%H%M%S" UTC)

add_subdirectory(uintl)
add_subdirectory(logger)

file(GLOB DEPS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/deps/*)
file(GLOB EXTS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/exts/*)

foreach(dep ${DEPS})
  message("Found DEP: " ${dep})
  add_subdirectory(${dep})
endforeach()
foreach(ext ${EXTS})
  message("Found EXT: " ${ext})
  add_subdirectory(${ext})
endforeach()

add_subdirectory(stone)