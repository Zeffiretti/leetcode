cmake_minimum_required(VERSION 3.0)
project(cxx)

add_library(cxx_thread_container SHARED
  threadlist.cc
  threadlist.h
)
target_link_libraries(cxx_thread_container
  pthread
)

add_executable(${PROJECT_NAME}_node main.cc)
target_link_libraries(${PROJECT_NAME}_node
  cxx_thread_container
)
