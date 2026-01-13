cmake_minimum_required(VERSION 3.29)
project(Homework3c)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework3c
    test_files/test1.input.txt
    test_files/test2.input.txt
    test_files/test3.input.txt
    sort.cpp)
