cmake_minimum_required(VERSION 3.5)
project("Linux")

add_subdirectory(${CMAKE_SOURCE_DIR}/fork)
add_subdirectory(${CMAKE_SOURCE_DIR}/exec)
add_subdirectory(${CMAKE_SOURCE_DIR}/wait)
