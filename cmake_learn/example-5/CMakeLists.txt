cmake_minimum_required(VERSION 2.8)

project(Tutorial)
 

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

configure_file(
"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
find_package(Math REQUIRED)

message(STATUS ${Math_INCLUDE_DIR})
message(STATUS ${Math_LIBRARIES})

option(USE_MYMATH "use tutorial provied math implementation" ON)

if (USE_MYMATH)
	message(STATUS "set use_mymath open")
	set(include_path ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/MathFunctions)
	message(STATUS "set use_mymath open :${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}")
	message(STATUS ${include_path})
	add_subdirectory(MathFunctions)
	include_directories(${include_path})
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
	#add_definitions("-DUSE_MYMATH")
endif(USE_MYMATH)

#link_directories(${PROJECT_SOURCE_DIR}/MathFunctions)

add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
