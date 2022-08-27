cmake_minimum_required(VERSION 3.0)
project(360)

add_executable(${PROJECT_NAME}_NODE main.cc)

add_library(${PROJECT_NAME}_LIB STATIC
  practice.h
  dnafix.h
  paveroad.h
)

target_include_directories(${PROJECT_NAME}_LIB PRIVATE
  ${LC_INCLUDE_DIR}
)

target_include_directories(${PROJECT_NAME}_NODE PRIVATE
  ${LC_INCLUDE_DIR}
)

set_target_properties(${PROJECT_NAME}_LIB PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}_NODE PRIVATE
  ${PROJECT_NAME}_LIB
)
