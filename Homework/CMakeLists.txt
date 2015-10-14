cmake_minimum_required(VERSION 3.3)
project(Homework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hw006/main.h hw006/main.cpp hw006/main.h)
add_executable(Homework ${SOURCE_FILES})