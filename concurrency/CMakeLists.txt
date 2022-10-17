cmake_minimum_required(VERSION 3.0)
project(concurrency)

add_executable(${PROJECT_NAME}_node main.cc)
target_link_libraries(${PROJECT_NAME}_node
  cxx_thread_container
)
