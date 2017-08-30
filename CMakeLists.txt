cmake_minimum_required(VERSION 3.7)
project(abraham)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/library.cpp src/library.h)
add_library(abraham ${SOURCE_FILES})