cmake_minimum_required(VERSION 3.0)
project(microsoft)



add_library(${PROJECT_NAME}_LIB STATIC
  practice.h
  reducepollution.h
  fractionsum.h
  rehabitalition.h
  consubstr.h
  alignedset.h
  mergearray.h
)
target_include_directories(${PROJECT_NAME}_LIB PRIVATE
  ${LC_INCLUDE_DIR}
)
set_target_properties(${PROJECT_NAME}_LIB PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME}_NODE main.cc)
target_include_directories(${PROJECT_NAME}_NODE PRIVATE
  ${LC_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME}_NODE PRIVATE
  ${PROJECT_NAME}_LIB
)
