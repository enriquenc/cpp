cmake_minimum_required(VERSION 3.12)
project(ex02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex02
        main.cpp
        mutantstack.cpp
        mutantstack.hpp)
