project(tesk5)


set(HEADER_FILES_1 binary_tree.h list.h)
set(SOURCE_FILES_1 binary_tree.cpp)
add_executable(tesk5_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 priority_queue.h array.h)
set(SOURCE_FILES_2 priority_queue.cpp)
add_executable(tesk5_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})