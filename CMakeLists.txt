cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILECOMMANDS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LC_INCLUDE_DIR ${CMAKE_SOURCE_DIR})
include_directories(${LC_INCLUDE_DIR})

add_subdirectory(algmimpl)
add_subdirectory(jobs)
add_subdirectory(lc-us)
add_subdirectory(cxx)
add_subdirectory(concurrency)

