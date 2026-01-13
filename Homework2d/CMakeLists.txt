cmake_minimum_required(VERSION 3.29)
project(Homework2d)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework2d
    test_files/1Nephi.txt
    basic_text_generation.cpp
    improved_text_generation.cpp)
