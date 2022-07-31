set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_library(myAlgorithm SHARED
  include/myalgorithm/myalgorithm.h
  src/myalgorithm.cpp)

target_include_directories(myAlgorithm
PRIVATE
  include)


# message(STATUS ${PROJECT_NAME})
set(myAlgorithm_FOUND True PARENT_SCOPE)
set(myAlgorithm_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
