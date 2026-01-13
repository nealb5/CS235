cmake_minimum_required(VERSION 3.29)
project(Homework2b)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework2b)

add_executable(Homework2b
    Homework2b/test_files/test1.stdout.txt
    Homework2b/test_files/test2.stdout.txt
    Homework2b/test_files/test3.stdout.txt
    Homework2b/test_files/test4.stdout.txt
    Homework2b/tests.cpp
    Homework2b/VectorSet.h)
