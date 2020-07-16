aux_source_directory(. lib_src_list)
message(STATUS "hello")
add_library(MathFunctions ${lib_src_list})

message(STATUS "hello-1"${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "hello-2"${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "hello-3"${CMAKE_BINARY_DIR})
message(STATUS "hello-4"${CMAKE_SOURCE_DIR})

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

