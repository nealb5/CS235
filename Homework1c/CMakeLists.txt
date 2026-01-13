cmake_minimum_required(VERSION 3.29)
project(Homework1c)

set(CMAKE_CXX_STANDARD 14)

add_executable(Homework1c
    Homework1c/test_files/head.input.txt
    Homework1c/test_files/head_both_args.stdout.txt
    Homework1c/test_files/head_not_enough_lines.stdout.txt
    Homework1c/test_files/head_only_infile.stdout.txt
    Homework1c/test_files/sort_test1.stdout.txt
    Homework1c/test_files/sort_test2.stdout.txt
    Homework1c/test_files/sort_test3.stdout.txt
    Homework1c/test_files/sort_test4.stdout.txt
    Homework1c/head.cpp
    Homework1c/sort.cpp)
