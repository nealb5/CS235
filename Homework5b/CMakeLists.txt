cmake_minimum_required(VERSION 3.29)
project(Homework5b)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework5b)

add_executable(Homework5b
    Homework5b/test_files/test1.stdout.txt
    Homework5b/test_files/test10.stdout.txt
    Homework5b/test_files/test2.stdout.txt
    Homework5b/test_files/test3.stdout.txt
    Homework5b/test_files/test4.stdout.txt
    Homework5b/test_files/test5.stdout.txt
    Homework5b/test_files/test6.stdout.txt
    Homework5b/test_files/test7.stdout.txt
    Homework5b/test_files/test8.stdout.txt
    Homework5b/test_files/test9.stdout.txt
    Homework5b/BST.h
    Homework5b/printing.h
    Homework5b/tests.cpp)
