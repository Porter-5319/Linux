cmake_minimum_required(VERSION 3.5)
project("Linux")

add_subdirectory(${CMAKE_SOURCE_DIR}/signal)
add_subdirectory(${CMAKE_SOURCE_DIR}/sigaction)
add_subdirectory(${CMAKE_SOURCE_DIR}/generateSignal)
add_subdirectory(${CMAKE_SOURCE_DIR}/signal_set)