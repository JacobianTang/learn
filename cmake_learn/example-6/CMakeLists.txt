cmake_minimum_required(VERSION 2.8)

project(Tutorial)
 

option(USE_MYMATH "use tutorial provied math implementation" ON)
add_compile_definitions(NICE_DEBUG)

if (USE_MYMATH)
	message(STATUS "set use_mymath open")
	set(include_path ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/MathFunctions)
	message(STATUS "set use_mymath open :${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}")
	message(STATUS ${include_path})
	add_subdirectory(MathFunctions)
	include_directories(${include_path})
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
	add_definitions("-DUSE_MYMATH")
endif(USE_MYMATH)

link_directories(${PROJECT_BINARY_DIR}/MathFunctions)
add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
