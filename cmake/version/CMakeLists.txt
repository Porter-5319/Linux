cmake_minimum_required(VERSION 3.5)

project(version LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置版本号
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

# 配置一个头文件用于传递一些CMake中的配置到源代码中
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

# 添加一个路径使得我们可以找到Config.h文件 默认是在编译的文件里面的
include_directories("${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} main.cpp)
