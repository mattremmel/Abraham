# CMake
cmake_minimum_required(VERSION 3.7)

# Project
project(abraham)
set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(CMAKE_CXX_STANDARD 14)

# Headers
set(HEADERS_CORE include/core)
set(HEADERS ${HEADERS_CORE})

# Source
set(SOURCE_FILES
        src/core/Object.cpp
        )

# Testing
set(TEST_SOURCE
        tests/core/Object_Tests.cpp
        )
set(GMOCK_SOURCE lib/gmock-1.8/gmock-gtest-all.cc lib/gmock-1.8/gmock-gtest-main.cc)
set(GMOCK_HEADERS lib/gmock-1.8/)
SET(GMOCK ${GMOCK_SOURCE} ${GMOCK_HEADERS})

# Build
include_directories(${HEADERS} ${GMOCK_HEADERS})
add_executable(abraham-tests ${GMOCK} ${TEST_SOURCE} ${SOURCE_FILES})
add_library(abraham ${SOURCE_FILES})