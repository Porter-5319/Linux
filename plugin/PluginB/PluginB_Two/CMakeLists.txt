cmake_minimum_required(VERSION 3.0.0)

project(LPlugin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(PROJECT_NAME "PluginB_2")
project(${PROJECT_NAME})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../Main/pluginsB)

include_directories(${CMAKE_SOURCE_DIR}/Main/src)

find_package(Qt5Core)

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
add_library(${PROJECT_NAME} SHARED ${SRC_CPP} ${SRC_H})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
