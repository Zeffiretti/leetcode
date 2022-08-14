# weekly contest
add_subdirectory(292)
add_subdirectory(293)
add_subdirectory(294)
add_subdirectory(295)
add_subdirectory(296)
add_subdirectory(297)
add_subdirectory(298)
add_subdirectory(300)
add_subdirectory(301)
add_subdirectory(302)
add_subdirectory(303)
add_subdirectory(305)
add_subdirectory(306)

# biweekly contest
add_subdirectory(bi78)
add_subdirectory(bi79)
add_subdirectory(bi80)
add_subdirectory(bi81)
add_subdirectory(bi84)


add_executable(contest_debug
  contest-debug.cc
)

# change the line when you want to test the contest
target_link_libraries(contest_debug biwc-84)

target_include_directories(contest_debug PRIVATE
  ${LC_INCLUDE_DIR}
)