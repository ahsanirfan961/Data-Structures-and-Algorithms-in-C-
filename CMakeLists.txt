cmake_minimum_required(VERSION 3.26)
project(Data_Structures___Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Structures___Algorithms
        Algorithm.cpp
        Algorithm.h
        main.cpp
        DataStructures.h
        DataStructures.cpp)
