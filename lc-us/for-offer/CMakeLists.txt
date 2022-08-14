project(foroffer)

add_library(${PROJECT_NAME} SHARED
  for-offer-03.h
  for-offer-05.h
  for-offer-06.h
  for-offer-09.h
  for-offer-10.h
  for-offer-13.h
  for-offer-17.h
  for-offer-18.h
  for-offer-20.h
  for-offer-21.h
  for-offer-22.h
  for-offer-26.h
  for-offer-30.h
  for-offer-33.h
  for-offer-36.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


add_executable(${PROJECT_NAME}_NODE for-offer-test.cc)
target_link_libraries(${PROJECT_NAME}_NODE ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_NODE PRIVATE ${LC_INCLUDE_DIR})