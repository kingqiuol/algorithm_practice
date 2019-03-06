project(tesk3)

set(HEADER_FILES_1 sort.h list.h)
set(SOURCE_FILES_1 sort.cpp)
add_executable(tesk3_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(SOURCE_FILES_2 binary_chop.cpp)
add_executable(tesk3_2 ${SOURCE_FILES_2} )


