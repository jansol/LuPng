cmake_minimum_required(VERSION 2.6)
project(LuPng C)

set(LUPNG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(LUPNG_LIBRARIES LuPng)
set(LUPNG_BUILD_EXAMPLE OFF CACHE BOOL "Whether to build the example program")
set(LUPNG_USE_ZLIB OFF CACHE BOOL "Use system-wide zlib instead of bundled miniz")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/miniz)

set(LUPNG_SOURCES
    lupng.c
)

if(LUPNG_USE_ZLIB)
    find_package(ZLIB)
    include_directories(${ZLIB_INCLUDE_DIRS})
    add_definitions(-DLUPNG_USE_ZLIB)
    list(APPEND LUPNG_LIBRARIES ${ZLIB_LIBRARIES})
else(LUPNG_USE_ZLIB)
    list(APPEND LUPNG_SOURCES miniz/miniz.c)
endif(LUPNG_USE_ZLIB)

add_library(LuPng STATIC ${LUPNG_SOURCES})

if(LUPNG_BUILD_EXAMPLE)
    add_executable(example example.c)
    target_link_libraries(example ${LUPNG_LIBRARIES})
endif(LUPNG_BUILD_EXAMPLE)
