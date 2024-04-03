cmake_minimum_required(VERSION 3.2)

project(FixedPoint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(main FixedPoint.cpp FixedPoint.h)
