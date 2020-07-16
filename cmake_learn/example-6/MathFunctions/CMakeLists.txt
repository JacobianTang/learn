#cmake_minimum_required(VERSION 3.16)
#project(MathFunctions)
aux_source_directory(. lib_src_list)
message(STATUS "hello")
add_library(MathFunctions STATIC ${lib_src_list})

message(STATUS "hello-1"${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "hello-2"${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "hello-3"${CMAKE_BINARY_DIR})
message(STATUS "hello-4"${CMAKE_SOURCE_DIR})

#add_definitions(-DNICE_DEBUG)
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

