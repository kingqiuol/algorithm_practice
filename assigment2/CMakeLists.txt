project(tesk2)

set(HEADER_FILES_1 stack.h
        list.h)
set(SOURCE_FILES_1 stack.cpp)
add_executable(tesk2_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 queue.h
        list.h)
set(SOURCE_FILES_2 queue.cpp)
add_executable(tesk2_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})



