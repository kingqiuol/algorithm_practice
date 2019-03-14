project(tesk6)

set(HEADER_FILES_1 adjacencyWDigraph.h graph.h utils.h)
set(SOURCE_FILES_1 adjacencyWDigraph.cpp)
add_executable(tesk6_1 ${SOURCE_FILES_1} ${HEADER_FILES_1})

set(HEADER_FILES_2 listedWDigraph.h utils.h graph.h)
set(SOURCE_FILES_2 listedWDigraph.cpp)
add_executable(tesk6_2 ${SOURCE_FILES_2} ${HEADER_FILES_2})

set(HEADER_FILES_3 listedDigraph.h utils.h graph.h)
set(SOURCE_FILES_3 listedDigraph.cpp)
add_executable(tesk6_3 ${SOURCE_FILES_3} ${HEADER_FILES_3})