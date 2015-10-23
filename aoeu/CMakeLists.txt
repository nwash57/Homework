cmake_minimum_required(VERSION 3.3)
project(aoeu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hw6.cpp rotors.cpp rotors.h)
add_executable(aoeu ${SOURCE_FILES})