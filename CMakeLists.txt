cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILECOMMANDS ON)

add_subdirectory(lib/myalgorithm)

if(myAlgorithm_FOUND)
    include_directories(${myAlgorithm_INCLUDE_DIRS})
    message(STATUS "myAlgorithm found")
    message(STATUS "myAlgorithm include dirs: ${myAlgorithm_INCLUDE_DIRS}")
else()
    message(STATUS "myAlgorithm not found")
endif()

include_directories(include)

set(Pro_Num 437)
file(GLOB_RECURSE main_file src/${Pro_Num}.*.cpp)
file(GLOB_RECURSE sol_file src/lceditor/*.cpp)
add_library(Solution ${sol_file})
add_library(leetcode ${main_file})
add_executable(test_node src/alitest.cpp)
add_executable(alg_test src/000test.cpp)
add_executable(jobs_node include/jobs/huawei-rong/jobs-3.cpp)

target_link_libraries(test_node leetcode)

target_link_libraries(alg_test myAlgorithm)
target_include_directories(alg_test PUBLIC
    ${myAlgorithm_INCLUDE_DIRS})

add_executable(contest src/contest.cpp)
# target_link_libraries(test_node myAlgorithm)


