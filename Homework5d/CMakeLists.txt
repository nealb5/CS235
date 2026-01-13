cmake_minimum_required(VERSION 3.29)
project(Homework5d)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework5d)

add_executable(Homework5d
    Homework5d/test_files/test1.stdout.txt
    Homework5d/test_files/test10.stdout.txt
    Homework5d/test_files/test11.stdout.txt
    Homework5d/test_files/test12.stdout.txt
    Homework5d/test_files/test13.stdout.txt
    Homework5d/test_files/test14.stdout.txt
    Homework5d/test_files/test15.stdout.txt
    Homework5d/test_files/test16.stdout.txt
    Homework5d/test_files/test17.stdout.txt
    Homework5d/test_files/test18.stdout.txt
    Homework5d/test_files/test2.stdout.txt
    Homework5d/test_files/test3.stdout.txt
    Homework5d/test_files/test4.stdout.txt
    Homework5d/test_files/test5.stdout.txt
    Homework5d/test_files/test6.stdout.txt
    Homework5d/test_files/test7.stdout.txt
    Homework5d/test_files/test8.stdout.txt
    Homework5d/test_files/test9.stdout.txt
    Homework5d/AVL.h
    Homework5d/printing.h
    Homework5d/test18.out.txt
    Homework5d/tests.cpp)
