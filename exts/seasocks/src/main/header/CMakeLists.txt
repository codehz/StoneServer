add_library(seasocks_header INTERFACE)
file(GLOB_RECURSE seasocks_header_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/internal/*
    ${CMAKE_CURRENT_SOURCE_DIR}/include/seasocks/*
)

if (SEASOCKS_DEFLATE_SUPPORT)
    list(REMOVE_ITEM seasocks_header_SRC ${CMAKE_CURRENT_SOURCE_DIR}/include/seasocks/ZlibContextDisabled.cpp)
else()
    list(REMOVE_ITEM seasocks_header_SRC ${CMAKE_CURRENT_SOURCE_DIR}/include/seasocks/ZlibContext.cpp)
endif()

target_sources(seasocks_header INTERFACE ${seasocks_header_SRC})

target_include_directories(seasocks_header INTERFACE "include")
