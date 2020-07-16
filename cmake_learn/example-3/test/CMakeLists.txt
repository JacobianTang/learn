
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(main main.c )
option(MYDEBUG "enable debug compilation" OFF)

target_include_directories(main PRIVATE ../include )
if (MYDEBUG)
	message(STATUS "currently is in debug mode")
else()
	message(STATUS "currently is not in debug mode")
endif()

# set(NICE_VALUE "1")
# add_compile_definitions(NICE_DEBUG NICE=${NICE_VALUE})


target_link_libraries(main testFunc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/bin)
add_compile_options(-Wall)
