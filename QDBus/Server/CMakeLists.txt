cmake_minimum_required(VERSION 3.5)

project(fork LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(APP_NAME "Server")
project(${APP_NAME})

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/src/*.h)

find_package(Qt5Core)
find_package(Qt5 COMPONENTS DBus REQUIRED)
add_executable(${APP_NAME} ${SRC_CPP} ${SRC_H})
target_link_libraries(${PROJECT_NAME} Qt5::DBus)
