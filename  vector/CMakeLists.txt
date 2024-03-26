cmake_minimum_required(VERSION 3.10)

project(Vector)

set(CMAKE_CXX_STANDARD 20)

add_executable(Vector 
    VectorSrc/main.cpp 
    VectorHeader/Vector.hpp 
    VectorHeader/Vector.cpp
)
