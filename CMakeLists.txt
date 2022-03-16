cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/myalgorithm)
if(myAlgorithm_FOUND)
    include_directories(${myAlgorithm_INCLUDE_DIRS})
    message(STATUS "myAlgorithm found")
    message(STATUS "myAlgorithm include dirs: ${myAlgorithm_INCLUDE_DIRS}")
else()
    message(STATUS "myAlgorithm not found")
endif()

include_directories(include)

set(Pro_Num 938)
file(GLOB_RECURSE main_file src/${Pro_Num}.*.cpp)
file(GLOB_RECURSE sol_file src/*.cpp)
add_library(Solution ${sol_file})
add_executable(leetcode ${main_file})
add_executable(test_node src/000test.cpp)
target_link_libraries(test_node myAlgorithm)
