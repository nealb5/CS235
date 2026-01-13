cmake_minimum_required(VERSION 3.29)
project(Homework4a)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework4a)

add_executable(Homework4a
    Homework4a/test_files/test1.stdout.txt
    Homework4a/test_files/test2.stdout.txt
    Homework4a/test_files/test3.stdout.txt
    Homework4a/test_files/test4.stdout.txt
    Homework4a/SLList.h
    Homework4a/tests.cpp)
