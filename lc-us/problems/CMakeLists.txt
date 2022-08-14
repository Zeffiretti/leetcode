cmake_minimum_required(VERSION 3.0)
project(solution)

# solution file name begins with numbers
file(GLOB_RECURSE solution_files ^[0-9]*.cpp)

add_library(solution SHARED
  utils.h
  ${solution_files}
)
target_include_directories(solution PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${LC_INCLUDE_DIR}
)
set_target_properties(solution PROPERTIES LINKER_LANGUAGE CXX)

add_executable(solution_node solution.cc)
target_link_libraries(solution_node solution)
target_include_directories(solution_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${LC_INCLUDE_DIR}
)