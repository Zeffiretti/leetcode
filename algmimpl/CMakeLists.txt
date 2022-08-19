set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_library(myAlgorithm SHARED
  myalgorithm.cpp
  myalgorithm.h
  hashmap.hh
)
target_include_directories(myAlgorithm
PRIVATE
  ${LC_INCLUDE_DIR}
)

add_executable(myAlgorithm_node
  algm_test.cc
)
target_link_libraries(myAlgorithm_node
  myAlgorithm
)
target_include_directories(myAlgorithm_node
PRIVATE
  ${LC_INCLUDE_DIR}
)

# message(STATUS ${PROJECT_NAME})
set(myAlgorithm_FOUND True PARENT_SCOPE)
set(myAlgorithm_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
