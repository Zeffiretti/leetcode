cmake_minimum_required(VERSION 3.0)
project(jd)

add_executable(${PROJECT_NAME}_NODE main.cc)

target_include_directories(${PROJECT_NAME}_NODE PRIVATE
  ${LC_INCLUDE_DIR}
)

