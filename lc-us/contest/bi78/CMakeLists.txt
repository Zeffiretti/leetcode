project(biwc-78)

add_library(${PROJECT_NAME} SHARED 
  pro-01.h
  pro-02.h
  pro-03.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)