cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
set(Pro_Num 952)
file(GLOB_RECURSE sol_file src/${Pro_Num}.*.cpp)
add_executable(leetcode ${sol_file})
