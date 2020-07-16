cmake_minimum_required(VERSION 3.1)
project(demo)

aux_source_directory(${PROJECT_SOURCE_DIR} src_list)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message(STATUS "${CMAKE_CXX_FLAGS}")
foreach(mainfile ${src_list})
	get_filename_component(mfile ${mainfile} NAME_WE)
	message(STATUS "${mainfile}")
	message(STATUS "${mfile}")
	add_executable(${mfile} ${mainfile})
	target_link_libraries(${mfile} m)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
endforeach()
#add_executable(travel ./travel.cpp)
