cmake_minimum_required(VERSION 3.26)
project(CPP-Algorithms VERSION 0.0.1 LANGUAGES CXX)

# use cpp23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_CXX_SCAN_FOR_MODULES ON)

option(BUILD_TESTING "Build tests" ON)

add_subdirectory(src)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()