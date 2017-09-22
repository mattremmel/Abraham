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

set(STATIC_TARGET abraham)
set(TEST_TARGET abraham-tests)
set(COVERAGE_TARGET abraham-coverage)


###############
# Headers
###############

set(HEADERS_CONTAINER include/abraham/container)
set(HEADERS_CORE include/abraham/core)
set(HEADERS_MEMORY include/abraham/memory)
set(HEADERS_SYSTEM include/abraham/system)
set(HEADERS_TIME include/abraham/time)
set(HEADERS ${HEADERS_CONTAINER} ${HEADERS_CORE} ${HEADERS_MEMORY} ${HEADERS_TIME})


###############
# Source
###############

set(SOURCE_CORE
        src/core/Exception.cpp
        src/core/Object.cpp
        )
set(SOURCE_CONTAINER
        src/container/Array.cpp
        src/container/Dictionary.cpp
        src/container/Queue.cpp
        src/container/Stack.cpp
        src/container/String.cpp
        )
set(SOURCE_MEMORY
        src/memory/Singleton.cpp
        )
set(SOURCE_SYSTEM
        src/system/TerminalUtil.cpp
        )
set(SOURCE_TIME
        src/time/Interval.cpp
        src/time/Stopwatch.cpp
        src/time/Timer.cpp
        )
set(SOURCE_ALL ${SOURCE_CORE} ${SOURCE_CONTAINER} ${SOURCE_MEMORY} ${SOURCE_TIME})

###############
# Libraries
###############

set(RLUTIL_HEADERS lib/rlutil)
set(LIBRARY_HEADERS ${RLUTIL_HEADERS})


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
# Coverage
###############

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

include(CodeCoverage)

set(COVERAGE_EXCLUDES
        '${CMAKE_CURRENT_SOURCE_DIR}/lib/*'
        '${CMAKE_CURRENT_SOURCE_DIR}/tests/*'
        '/usr/include/*'
        '*/c++/v1/*'
        )

SETUP_TARGET_FOR_COVERAGE(
        NAME ${COVERAGE_TARGET}
        EXECUTABLE ${TEST_TARGET}
        DEPENDENCIES ${TEST_TARGET}
)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    APPEND_COVERAGE_COMPILER_FLAGS()
endif()


###############
# Testing
###############

set(TEST_CORE
        tests/core/Object_Tests.cpp
        )
set(TEST_CONTAINER
        tests/container/Array_Tests.cpp
        tests/container/Dictionary_Tests.cpp
        tests/container/Queue_Tests.cpp
        tests/container/Stack_Tests.cpp
        tests/container/String_Tests.cpp
        )
set(TEST_MEMORY
        tests/memory/Singleton_Tests.cpp
        )
set(TEST_TIME
        tests/time/Interval_Tests.cpp
        tests/time/Stopwatch_Tests.cpp
        tests/time/Timer_Tests.cpp
        )
set(TEST_ALL ${TEST_CORE} ${TEST_CONTAINER} ${TEST_MEMORY} ${TEST_TIME})

set(GMOCK_SOURCE lib/gmock-1.8/gmock-gtest-all.cc lib/gmock-1.8/gmock-gtest-main.cc)
set(GMOCK_HEADERS lib/gmock-1.8/)
set(GMOCK ${GMOCK_SOURCE} ${GMOCK_HEADERS})


###############
# Build
###############

include_directories(${HEADERS} ${GMOCK_HEADERS})
include_directories(${HEADERS} ${LIBRARY_HEADERS} ${GMOCK_HEADERS})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_library(${STATIC_TARGET} STATIC ${HEADERS} ${SOURCE_ALL})

add_executable(${TEST_TARGET} ${GMOCK} ${TEST_ALL})
target_link_libraries(${TEST_TARGET} ${STATIC_TARGET})
