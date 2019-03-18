cmake_minimum_required(VERSION 2.8)

include_directories(.)
include_directories(interop)

add_subdirectory(interop)

set(EMPTY_SRC
    emptyinterop.c)
set(EMPTY_HEADERS)

if(WIN32)
    list(APPEND EMPTY_SRC windows/resource.rc)
    list(APPEND EMPTY_HEADERS windows/resource.h)
endif()

project(empty C)

add_library(${PROJECT_NAME} SHARED ${EMPTY_SRC} ${EMPTY_HEADERS})
target_link_libraries(${PROJECT_NAME} interoplib)

if(WIN32)
    set(CMAKE_MODULE_LINKER_FLAGS
        "${CMAKE_MODULE_LINKER_FLAGS} \"/DEF:${CMAKE_CURRENT_SOURCE_DIR}/windows/empty.def\"")
elseif(APPLE)
    ucm_set_xcode_attrib(EXPORTED_SYMBOLS_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/mac/workflow.def")
elseif(UNIX)
    set(CMAKE_SHARED_LINKER_FLAGS 
        "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/linux/workflow.def")
    set(CMAKE_SHARED_LINKER_FLAGS 
        "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--gc-sections")
endif()
