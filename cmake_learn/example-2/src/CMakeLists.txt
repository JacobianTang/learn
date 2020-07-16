include_directories(../include)

aux_source_directory(. SRC_LIST1)

message(STATUS "src_list is:" ${SRC_LIST1})

add_library(testFunc_shared SHARED ${SRC_LIST1})
add_library(testFunc_static STATIC ${SRC_LIST1})

set_target_properties(testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties(testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
