cmake_minimum_required(VERSION 2.8)

project(hello)

include_directories("${PROJECT_SOURCE_DIR}/mylib")
add_subdirectory(mylib)
add_executable(hello main.cpp)
target_link_libraries(hello mylib)