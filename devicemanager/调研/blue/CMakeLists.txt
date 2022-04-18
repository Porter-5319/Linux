cmake_minimum_required(VERSION 3.0.0)

project(blue VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

link_libraries(bluetooth)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} "main.cpp" "DeviceBluetooth.h" "DeviceBluetooth.cpp" "BTTool.h" "BTTool.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core)
