cmake_minimum_required(VERSION 3.5)

project(option_library LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 这里会影响到两个地方：
#   1. CMakeList(本文件)里面的USE_MATH
#   2. 源码里面的USE_MATH
#   ON和OFF会同时打开或关闭CMakeList和源码里面的USE_MATH宏
option (USE_MATH "use math" ON)

# 配置一个头文件用于传递一些CMake中的配置到源代码中
configure_file (${PROJECT_SOURCE_DIR}/Config.h.in ${PROJECT_BINARY_DIR}/Config.h @ONLY)
# 添加一个路径使得我们可以找到Config.h文件 默认是在编译的文件里面的
include_directories("${PROJECT_BINARY_DIR}")

#根据USE_MATH决定是否使用MathFunctions  # 上面的 option (USE_MATH "use math" OFF)
if (USE_MATH)
  message(" use math ********************************** ")
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MATH)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
