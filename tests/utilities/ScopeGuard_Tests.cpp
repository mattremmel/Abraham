//
// Created by Matthew Remmel on 9/28/17.
//

#include "gtest/gtest.h"
#include "ScopeGuard.hpp"

using namespace abraham;


TEST(ScopeGuard, scope_exit_success) {
    // Setup
    int i = 0;
    {
        scope_exit(i = 10);
    }

    // Assertion
    EXPECT_EQ(10, i);
}

TEST(ScopeGuard, scope_exit_exception) {
    // Setup
    int i = 0;
    try {
        scope_exit(i = 10);
        throw 1;
    }
    catch(...) { }

    // Assertion
    EXPECT_EQ(10, i);
}

TEST(ScopeGuard, scope_success_success) {
    // Setup
    int i = 0;
    {
        scope_success(i = 10);
    }

    // Assertion
    EXPECT_EQ(10, i);
}

TEST(ScopeGuard, scope_success_exception) {
    // Setup
    int i = 0;
    try {
        scope_success(i = 10);
        throw 1;
    }
    catch (...) { }

    // Assertion
    EXPECT_EQ(0, i);
}

TEST(ScopeGuard, scope_failure_success) {
    // Setup
    int i = 0;
    {
        scope_failure(i = 10);
    }

    // Assertion
    EXPECT_EQ(0, i);
}

TEST(ScopeGuard, scope_failure_exception) {
    // Setup
    int i = 0;
    try {
        scope_failure(i = 10);
        throw 1;
    }
    catch (...) { }

    // Assertion
    EXPECT_EQ(10, i);
}