cmake_minimum_required(VERSION 3.29)
project(Homework6a)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework6a)

add_executable(Homework6a
    Homework6a/test_files/test1.stdout.txt
    Homework6a/test_files/test2.stdout.txt
    Homework6a/test_files/test3.stdout.txt
    Homework6a/test_files/test4.stdout.txt
    Homework6a/test_files/test5.stdout.txt
    Homework6a/HashSet.h
    Homework6a/tests.cpp)
