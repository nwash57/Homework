cmake_minimum_required(VERSION 3.2)
project(Perlin_Height_Maps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h)
add_executable(Perlin_Height_Maps ${SOURCE_FILES})