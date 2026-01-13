cmake_minimum_required(VERSION 3.29)
project(Homework4c)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework4c)

add_executable(Homework4c
    Homework4c/test_files/test1.stdout.txt
    Homework4c/test_files/test2.stdout.txt
    Homework4c/test_files/test3.stdout.txt
    Homework4c/test_files/test4.stdout.txt
    Homework4c/test_files/test5.stdout.txt
    Homework4c/test_files/test6.stdout.txt
    Homework4c/tests.cpp
    Homework4c/Vector.h)
