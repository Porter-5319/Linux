cmake_minimum_required(VERSION 3.5)

project(fork LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(APP_NAME "create")
project(${APP_NAME})

link_libraries("pthread")

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/*.h)
add_executable(${APP_NAME} ${SRC_CPP} ${SRC_H})
