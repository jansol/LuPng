cmake_minimum_required(VERSION 2.6)
project(LuPng C)

set(LUPNG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/miniz)

add_library(LuPng STATIC lupng.c miniz/miniz.c)
