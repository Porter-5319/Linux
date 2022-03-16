cmake_minimum_required(VERSION 3.0.0)

project(LPlugin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(PROJECT_NAME "Main")
project(${PROJECT_NAME})

find_package(Qt5Core)

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
add_executable(${PROJECT_NAME} ${SRC_CPP} ${SRC_H})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
