cmake_minimum_required(VERSION 3.29)
project(Homework5c)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework5c)

add_executable(Homework5c
    Homework5c/test_files/test1.stdout.txt
    Homework5c/test_files/test10.stdout.txt
    Homework5c/test_files/test2.stdout.txt
    Homework5c/test_files/test3.stdout.txt
    Homework5c/test_files/test4.stdout.txt
    Homework5c/test_files/test5.stdout.txt
    Homework5c/test_files/test6.stdout.txt
    Homework5c/test_files/test7.stdout.txt
    Homework5c/test_files/test8.stdout.txt
    Homework5c/test_files/test9.stdout.txt
    Homework5c/printing.h
    Homework5c/rebalance.h
    Homework5c/tests.cpp)
