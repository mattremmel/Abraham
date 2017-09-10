//
// Created by Matthew Remmel on 8/30/17.
//

#include "gtest/gtest.h"
#include "Object.hpp"
#include "Exception.hpp"

using namespace abraham;


TEST(Object, toString) {
    // Setup
    Object o = Object();

    // Assertion
    EXPECT_THROW(o.toString(), NotImplementedException);
}

TEST(Object, toHashCode) {
    // Setup
    Object o = Object();

    // Assertion
    EXPECT_THROW(o.toHashCode(), NotImplementedException);
}

TEST(Object, is) {
    // Setup
    Object o = Object();

    // Assertions
    EXPECT_THROW(o.is(o), NotImplementedException);
}

TEST(Object, equals) {
    // Setup
    Object o = Object();

    // Assertions
    EXPECT_THROW(o.equals(o), NotImplementedException);
}