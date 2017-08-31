###############
# CMake
###############

cmake_minimum_required(VERSION 3.7)


###############
# Project
###############

project(Abraham)

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(CMAKE_CXX_STANDARD 14)


###############
# Headers
###############

set(HEADERS_CORE include/abraham/core)
set(HEADERS ${HEADERS_CORE})


###############
# Source
###############

set(SOURCE_FILES
        src/core/Object.cpp
        src/core/Exception.cpp
        )


###############
# Doxygen
###############

option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)

if (DOXYGEN_FOUND)

    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYFILE_IN} ${DOXYFILE} @ONLY)
    message("Doxygen build started")

    add_custom_target(doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

else (DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


###############
# Testing
###############

set(TEST_SOURCE
        tests/core/Object_Tests.cpp
        )

set(GMOCK_SOURCE lib/gmock-1.8/gmock-gtest-all.cc lib/gmock-1.8/gmock-gtest-main.cc)
set(GMOCK_HEADERS lib/gmock-1.8/)
SET(GMOCK ${GMOCK_SOURCE} ${GMOCK_HEADERS})


###############
# Build
###############
include_directories(${HEADERS} ${GMOCK_HEADERS})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(abraham-tests ${GMOCK} ${TEST_SOURCE} ${SOURCE_FILES})
add_library(abraham ${HEADERS} ${SOURCE_FILES})


