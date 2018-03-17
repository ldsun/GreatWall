cmake_minimum_required(VERSION 3.9.3)

set(CMAKE_CXX_STANDARD 11)

project(LongestOnes)

add_library(LongestOnes LongestOnes.cpp)
add_executable(main main.cpp)
target_link_libraries(main LongestOnes)