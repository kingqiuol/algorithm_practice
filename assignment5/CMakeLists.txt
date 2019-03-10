project(tesk4)

set(HEADER_FILES_1 hashing.h list.h lru.h)
set(SOURCE_FILES_1 hashing.cpp)
add_executable(tesk4_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 string.h)
set(SOURCE_FILES_2 string.cpp)
add_executable(tesk4_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})