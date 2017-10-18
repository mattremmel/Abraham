################################################################
# CMake
###############

cmake_minimum_required(VERSION 3.7)


################################################################
# Project
###############

project(Abraham)

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(CMAKE_CXX_STANDARD 14)

# Targets
set(STATIC_TARGET abraham-static)
set(TEST_TARGET abraham-tests)
set(DOCS_TARGET abraham-docs)
set(COVERAGE_TARGET abraham-coverage)


################################################################
# Sub Projects
###############

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

# Doxygen
add_subdirectory(docs)

# Code Coverage
include(AbrahamCoverage)


################################################################
# Headers
###############

set(HEADERS_CONTAINER include/abraham/container)
set(HEADERS_CORE include/abraham/core)
set(HEADERS_LOGGING include/abraham/logging)
set(HEADERS_MEMORY include/abraham/memory)
set(HEADERS_SYSTEM include/abraham/system)
set(HEADERS_TIME include/abraham/time)
set(HEADERS_UTIL include/abraham/utilities)
set(HEADERS ${HEADERS_CONTAINER} ${HEADERS_CORE} ${HEADERS_LOGGING} ${HEADERS_MEMORY} ${HEADERS_SYSTEM} ${HEADERS_TIME} ${HEADERS_UTIL})


################################################################
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
set(SOURCE_LOGGING
        src/logging/DevelopmentLogger.cpp
        src/logging/Logger.cpp
        src/logging/MultiLogger.cpp
        src/logging/SimpleLogger.cpp
        )
set(SOURCE_MEMORY
        src/memory/Singleton.cpp
        src/memory/SharedPtr.cpp
        src/memory/UniquePtr.cpp
        )
set(SOURCE_SYSTEM
        src/system/TerminalUtil.cpp
        )
set(SOURCE_TIME
        src/time/Interval.cpp
        src/time/Stopwatch.cpp
        src/time/Timer.cpp
        )
set(SOURCE_UTIL
        src/utilities/Random.cpp
        src/utilities/ScopeGuard.cpp
        src/utilities/Types.cpp
        )
set(SOURCE_ALL ${SOURCE_CORE} ${SOURCE_CONTAINER} ${SOURCE_LOGGING} ${SOURCE_MEMORY} ${SOURCE_SYSTEM} ${SOURCE_TIME} ${SOURCE_UTIL})


################################################################
# Libraries
###############

set(RLUTIL_HEADERS lib)
set(LIBRARY_HEADERS ${RLUTIL_HEADERS})


################################################################
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
        tests/memory/SharedPtr_Tests.cpp
        tests/memory/UniquePtr_Tests.cpp
        )
set(TEST_TIME
        tests/time/Interval_Tests.cpp
        tests/time/Stopwatch_Tests.cpp
        tests/time/Timer_Tests.cpp
        )
set(TEST_UTIL
        tests/utilities/Random_Tests.cpp
        tests/utilities/ScopeGuard_Tests.cpp
        )
set(TEST_ALL ${TEST_CORE} ${TEST_CONTAINER} ${TEST_MEMORY} ${TEST_TIME} ${TEST_UTIL})

set(GMOCK_SOURCE lib/googletest-1.8/gmock-gtest-all.cc lib/googletest-1.8/gmock-gtest-main.cc)
set(GMOCK_HEADERS lib/googletest-1.8/)
set(GMOCK ${GMOCK_SOURCE} ${GMOCK_HEADERS})


################################################################
# Build
###############

# Includes
include_directories(${HEADERS} ${LIBRARY_HEADERS} ${GMOCK_HEADERS})

# Static Library
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_library(${STATIC_TARGET} STATIC ${HEADERS} ${SOURCE_ALL})

# Testing Target
add_executable(${TEST_TARGET} ${GMOCK} ${TEST_ALL})
target_link_libraries(${TEST_TARGET} ${STATIC_TARGET})
