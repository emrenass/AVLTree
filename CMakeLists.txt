cmake_minimum_required(VERSION 3.7)
project(AVLTree)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Source/main.cpp Source/AVLTree.cpp Headers/AVLTree.h)
add_executable(AVLTree ${SOURCE_FILES})