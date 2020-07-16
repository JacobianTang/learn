include_directories(../include)

#aux_source_directory(. SRC_LIST1)
file(GLOB SRC_LIST1 *.c)
message(STATUS "current_dir is:" ${CMAKE_CURRENT_SOURCE_DIR})

set(NICE_VALUE "1")
#target_compile_definitions(testFunc_shared NICE_DEBUG NICE=${NICE_VALUE})

message(STATUS "src_list is:" ${SRC_LIST1})

add_library(testFunc_shared SHARED ${SRC_LIST1})
add_library(testFunc_static STATIC ${SRC_LIST1})

# target_compile_definitions(testFunc_static PRIVATE NICE_DEBUG NICE=${NICE_VALUE})
# target_compile_definitions(testFunc_shared PRIVATE NICE_DEBUG NICE=${NICE_VALUE})
set(CMAKE_CXX_FLAGS "-DNICE_DEBUG")

set_target_properties(testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")

set_target_properties(testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

#set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

# add_custom_command(TARGET testFunc_shared POST_BUILD
# 	COMMAND touch text.txt
# 	COMMAND cp libtestFunc.dylib testFun_shared)
				
