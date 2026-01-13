cmake_minimum_required(VERSION 3.29)
project(Homework3b)

set(CMAKE_CXX_STANDARD 14)

include_directories(__MACOSX/Homework3b)
include_directories(Homework3b)

add_executable(Homework3b
    .idea/.gitignore
    .idea/editor.xml
    .idea/Homework3b.iml
    .idea/misc.xml
    .idea/modules.xml
    __MACOSX/Homework3b/._Grid.h
    __MACOSX/Homework3b/._maze.cpp
    __MACOSX/._Homework3b
    Homework3b/test_files/solvable1.maze.txt
    Homework3b/test_files/solvable2.maze.txt
    Homework3b/test_files/solvable3.maze.txt
    Homework3b/test_files/unsolvable1.maze.txt
    Homework3b/test_files/unsolvable2.maze.txt
    Homework3b/test_files/unsolvable3.maze.txt
    Homework3b/Grid.h
    Homework3b/maze.cpp)
