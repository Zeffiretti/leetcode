cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILECOMMANDS ON)

set(LC_INCLUDE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(lib/myalgorithm)
add_subdirectory(jobs)

if(myAlgorithm_FOUND)
    include_directories(${myAlgorithm_INCLUDE_DIRS})
    message(STATUS "myAlgorithm found")
    message(STATUS "myAlgorithm include dirs: ${myAlgorithm_INCLUDE_DIRS}")
else()
    message(STATUS "myAlgorithm not found")
endif()

# include_directories(include)

set(Pro_Num 437)
file(GLOB_RECURSE main_file src/${Pro_Num}.*.cpp)
file(GLOB_RECURSE sol_file src/lceditor/*.cpp)
add_library(Solution ${sol_file})
add_library(leetcode ${main_file})
add_executable(test_node src/alitest.cpp)
add_executable(jobs_node include/jobs/huawei-rong/jobs-3.cpp)
add_executable(contest src/contest.cpp)

target_link_libraries(test_node leetcode)

# target_link_libraries(alg_test myAlgorithm)
# target_include_directories(alg_test PUBLIC
#     ${myAlgorithm_INCLUDE_DIRS})

target_include_directories(leetcode PRIVATE
    include)

target_include_directories(Solution PRIVATE
    ${PROJECT_SOURCE_DIR}
    include)

target_include_directories(test_node PRIVATE
    include)

target_include_directories(jobs_node PRIVATE
    include)
target_include_directories(contest PRIVATE
    include)
# target_link_libraries(test_node myAlgorithm)


