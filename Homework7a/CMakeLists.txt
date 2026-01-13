cmake_minimum_required(VERSION 3.29)
project(Hw7a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hw7a
    AVL.h
    BST.h
    HashSet.h
    main.cpp
    template_test.cpp
    timing.h
    VectorSet.h)
