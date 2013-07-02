cmake_minimum_required (VERSION 2.8.9)
project (Gravity)

#enable_testing()

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_VERBOSE_MAKEFILE ON)

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-ansi -Wall -pedantic -std=c++11")
endif()

set(SOURCE_DIRECTORY ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)