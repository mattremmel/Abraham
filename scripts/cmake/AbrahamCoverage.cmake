################################################################
# Coverage
###############

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

