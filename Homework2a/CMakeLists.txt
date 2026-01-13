cmake_minimum_required(VERSION 3.29)
project(Homework2a)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework2a
    test_files/file_test1.input.txt
    test_files/file_test1.stdout.txt
    test_files/file_test2.input.txt
    test_files/file_test2.stdout.txt
    uniq.cpp)
