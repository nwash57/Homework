cmake_minimum_required(VERSION 3.3)
project(Homework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hw006/hw6.cpp hw006/hw6functs.cpp hw006/hw6functs.h hw007/hw7.cpp hw007/hw7functions.cpp hw007/hw7functions.h)
add_executable(Homework ${SOURCE_FILES})