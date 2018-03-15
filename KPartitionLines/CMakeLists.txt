cmake_minimum_required(VERSION 2.8)

project(KPartitionLines)

add_library(KPartitionLines KPartitionLines.cpp)
add_executable(main main.cpp)
target_link_libraries(main KPartitionLines)