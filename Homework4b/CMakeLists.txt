cmake_minimum_required(VERSION 3.29)
project(Homework4b)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework4b)

add_executable(Homework4b
    Homework4b/test_files/test1.stdout.txt
    Homework4b/test_files/test2.stdout.txt
    Homework4b/test_files/test3.stdout.txt
    Homework4b/test_files/test4.stdout.txt
    Homework4b/test_files/test5.stdout.txt
    Homework4b/test_files/test6.stdout.txt
    Homework4b/test_files/test7.stdout.txt
    Homework4b/test_files/test8.stdout.txt
    Homework4b/DLList.h
    Homework4b/tests.cpp)
