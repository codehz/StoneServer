set(SEASOCKS_SOURCE_FILES
        Connection.cpp
        HybiAccept.cpp
        HybiPacketDecoder.cpp
        internal/Base64.cpp
        Logger.cpp
        md5/md5.cpp
        md5/md5.h
        PageRequest.cpp
        Response.cpp
        Server.cpp
        sha1/sha1.cpp
        sha1/sha1.h
        StringUtil.cpp
        util/CrackedUri.cpp
        util/Json.cpp
        util/PathHandler.cpp
        util/RootPageHandler.cpp
        )


add_library(seasocks_obj OBJECT ${SEASOCKS_SOURCE_FILES})
target_include_directories(seasocks_obj PRIVATE . ${SEASOCKS_ROOT_PATH} $<TARGET_PROPERTY:seasocks_header,INTERFACE_INCLUDE_DIRECTORIES>)
set_property(TARGET seasocks_obj PROPERTY POSITION_INDEPENDENT_CODE TRUE)

add_library(seasocks STATIC $<TARGET_OBJECTS:seasocks_obj> $<TARGET_OBJECTS:embedded>)
target_include_directories(seasocks PRIVATE .)
target_link_libraries(seasocks PRIVATE ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(seasocks PUBLIC seasocks_header)

add_library(seasocks_so SHARED $<TARGET_OBJECTS:seasocks_obj> $<TARGET_OBJECTS:embedded>)
target_include_directories(seasocks_so PRIVATE ${ZLIB_INCLUDE_DIRS} .)
if (SEASOCKS_DEFLATE_SUPPORT)
    target_link_libraries(seasocks_so PRIVATE ${CMAKE_THREAD_LIBS_INIT} "${ZLIB_LIBRARIES}")
endif()
set_target_properties(seasocks_so PROPERTIES OUTPUT_NAME seasocks VERSION ${VERSION})
target_link_libraries(seasocks_so PUBLIC seasocks_header)

install(TARGETS seasocks seasocks_so
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
install(DIRECTORY seasocks
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
        )
