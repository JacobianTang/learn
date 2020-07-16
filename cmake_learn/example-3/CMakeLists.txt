cmake_minimum_required(VERSION 2.8)

project(demo)

list(APPEND CMAKE_PREFIX_PATH  /usr/local/Cellar/opencv\@3/3.4.9_1)
find_package(OpenCV)

find_file(var1 NAMES libopencv_videoio.a PATHS /usr/local/Cellar/opencv\@3/3.4.9_1/lib)
find_library(var2 NAMES opencv_videoio PATHS /usr/local/Cellar/opencv\@3/3.4.9_1/lib)
find_path(var3 NAMES libopencv_videoio.a PATHS /usr/local/Cellar/opencv\@3/3.4.9_1/lib)

message(STATUS "ok:"${var1})
message(STATUS "ok:"${var2})
message(STATUS "ok:"${var3})

message(STATUS "ver :${OpenCV_VERSION}")
message(STATUS "libs: ${OpenCV_LIBS}")
message(STATUS "lib_path: ${OpenCV_LIBRARIES_DIRS}")
message(STATUS "include_path: ${OpenCV_INCLUDE_DIRS}")

set(NICE_VALUE "1")
add_compile_definitions(NICE_DEBUG NICE=${NICE_VALUE})
#add_definitions(-DNICE_DEBUG)

set(print_str "hxlx")
list(APPEND print_str "hxdl" "atom")

message(STATUS "print_str:"${print_str})

foreach(loop_var IN LISTS print_str)
	message(STATUS "current ${loop_var}")
endforeach()

list(FILTER print_str INCLUDE REGEX "hx*")

foreach(loop_var IN LISTS print_str)
	message(STATUS "current ${loop_var}")
endforeach()

list(INSERT print_str 0 PUBLIC "good")
foreach(loop_var IN LISTS print_str)
	message(STATUS "current ${loop_var}")
endforeach()


#foreach(loop_var IN LISTS test_file)
#	message(STATUS "current ${loop_var}")
#endforeach()

message(STATUS "main_current_dir is:" ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "HELLO:${PROJECT_BINARY_DIR}")
file(WRITE ${PROJECT_BINARY_DIR}/__init__.py "HELLO")

file(GLOB src_files src/*.c)
file(GLOB head_files include/*.h)

list(APPEND src_files ${head_files})
set(test_file ${src_files})

message(STATUS "test:${test_file}")

#foreach(loop_var IN LISTS test_file)
#	message(STATUS "current ${loop_var}")
#endforeach()

foreach(loop_var ${test_file})
	message(STATUS "current ${loop_var}")
endforeach()

message(STATUS "src_files:${src_files}")
message(STATUS "head_files:${head_files}")

message(STATUS "good: ${CMAKE_BINARY_DIR}")
message(STATUS "${PROJECT_BINARY_DIR}")

add_subdirectory(src)

add_subdirectory(test)


