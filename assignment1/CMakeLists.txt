project(tesk1)

set(HEADER_FILES_1 array.h)
set(SOURCE_FILES_1 array.cpp)
add_executable(tesk1_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 list.h)
set(SOURCE_FILES_2 list.cpp)
add_executable(tesk1_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})

