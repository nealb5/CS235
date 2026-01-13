cmake_minimum_required(VERSION 3.29)
project(Homework3d)

set(CMAKE_CXX_STANDARD 14)

include_directories(Homework3d)

add_executable(Homework3d
    Homework3d/test_files/test1.stdout.txt
    Homework3d/test_files/test2.stdout.txt
    Homework3d/test_files/test3.stdout.txt
    Homework3d/test_files/test4.stdout.txt
    Homework3d/test_files/test5.stdout.txt
    Homework3d/test_files/test6.stdout.txt
    Homework3d/test_files/test7.stdout.txt
    Homework3d/QS.h
    Homework3d/tests.cpp)
