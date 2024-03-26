cmake_minimum_required(VERSION 3.10)

project(Forward_List)

set(CMAKE_CXX_STANDARD 20)

add_executable(Forward_List 
    ForwardSrc/main.cpp 
    ForwardHeader/ForwardList.h 
    ForwardHeader/ForwardList.cpp
)
