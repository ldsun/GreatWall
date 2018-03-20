cmake_minimum_required(VERSION 3.9.3)

set(CMAKE_CXX_STANDARD 11)

project(Islands)

add_library(islands_lib islands.cpp)
add_executable(main main.cpp)
target_link_libraries(main islands_lib)