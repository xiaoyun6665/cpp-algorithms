cmake_minimum_required(VERSION  3.30)

project(CPP-Algorithms VERSION 0.0.1 LANGUAGES CXX)

# use cpp23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDOC ON)  # 可选，用于模块依赖追踪

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_library(cpp_algorithm_lib STATIC)

# 添加所有模块文件（使用FILE_SET CXX_MODULES）
target_sources(cpp_algorithm_lib
PUBLIC
  FILE_SET CXX_MODULES
  BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src   # 模块查找基目录
  FILES
    src/algorithms/LinkedList/LinkedList.ixx
    # 可以继续添加其他算法/数据结构模块
)

# 编译器模块选项
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(cpp_algorithm_lib PRIVATE -fmodules -fbuiltin-module-map)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(cpp_algorithm_lib PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(cpp_algorithm_lib PRIVATE /std:c++latest)
endif()

option(BUILD_TESTING "Build tests" ON)


if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()