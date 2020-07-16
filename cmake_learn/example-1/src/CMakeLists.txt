include_directories(../include)

aux_source_directory(. SRC_LIST)

#aux_source_directory(. SRC_LIST)
#set(SRC_LIST ./main.c ./testFun.c ./testFun1.c)
message(STATUS "src_list is:" ${SRC_LIST})

add_executable(main  ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#add_executable(main main.c testFun.c)
