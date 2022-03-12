cmake_minimum_required(VERSION 3.10)
project(myAlgorithm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)
set(Pro_Num 938)
file(GLOB src_file src/*.cpp)
add_library(myAlgorithm STATIC ${src_file})


# message(STATUS ${PROJECT_NAME})
set(${PROJECT_NAME}_FOUND True PARENT_SCOPE)
set(${PROJECT_NAME}_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
