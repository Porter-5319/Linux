cmake_minimum_required(VERSION 3.5)

project(fork LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(APP_NAME "lscpu-demo")
project(${APP_NAME})


# 下面定义了一个函数，获取curdir目录下的所有子目录
# SUBDIRLIST 是函数名
# result 是返回值
# curdir 传入参数
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# 通过使用上面定义的函数，我们可以include_directories目录，这样在include的时候就不用包含路径了
SUBDIRLIST(dirs ${CMAKE_CURRENT_SOURCE_DIR}/src)
foreach(dir ${dirs})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/${dir})
endforeach()

find_package(Qt5 COMPONENTS Core REQUIRED)

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/src/*.c*)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
add_executable(${APP_NAME} ${SRC_CPP} ${SRC_H})

target_link_libraries(${APP_NAME} Qt5::Core)


