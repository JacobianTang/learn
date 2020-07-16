cmake_minimum_required(VERSION 2.8)

project(demo)

add_subdirectory(src)


include_directories(./include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(main main.c)

add_compile_options(-Wall)
target_link_libraries(main testFunc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


