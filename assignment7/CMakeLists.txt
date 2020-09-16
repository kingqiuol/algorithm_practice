project(tesk7)


set(HEADER_FILES_1 backtracking.h )
set(SOURCE_FILES_1 backtracking.cpp )
add_executable(tesk7_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 divide_conquer_algorithm.h )
set(SOURCE_FILES_2 divide_conquer_algorithm.cpp)
add_executable(tesk7_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})


set(HEADER_FILES_3 dynamic_programming.h)
set(SOURCE_FILES_3 dynamic_programming.cpp)
add_executable(tesk7_3 ${SOURCE_FILES_3} ${HEADER_FILES_3})