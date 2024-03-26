cmake_minimum_required(VERSION 3.10)

project(Tuple)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tuple TupleSrc/main.cpp TupleHeader/Tuple.hpp TupleHeader/Tuple.cpp)
