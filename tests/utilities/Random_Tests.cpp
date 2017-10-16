//
// Created by Matthew Remmel on 10/12/17.
//

#include "gtest/gtest.h"
#include "Random.hpp"

// Macro for asserting value between two values
#define EXPECT_BETWEEN(actual, lower, upper) EXPECT_GE(actual, lower); EXPECT_LE(actual, upper);
#define LOOP for(int _i = 0; _i < 1000; _i++)

using namespace abraham;


// Compile Templates

TEST(Random, compiles) {
    // Setup
    int i = Random::get();
    long l = Random::get<long>();
    float f = Random::get<float>();
    char c = Random::get<char>();
    bool b = Random::get<bool>();
}

// Get

TEST(Random, get_int_any) {
    // Setup
    LOOP {
        int i = Random::get();

        // Assertion
        EXPECT_BETWEEN(i, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }
}

TEST(Random, get_int_limit) {
    // Setup
    LOOP {
        int i = Random::get(1, 10);

        // Assertion
        EXPECT_BETWEEN(i, 1, 10);
    }
}

TEST(Random, get_double_any) {
    // Setup
    LOOP {
        double i = Random::get<double>();

        // Assertion
        EXPECT_BETWEEN(i, std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
    }
}

TEST(Random, get_double_limit) {
    // Setup
    LOOP {
        double i = Random::get<double>(1, 10);

        // Assertion
        EXPECT_BETWEEN(i, 1, 10);
    }
}

TEST(Random, get_byte_any) {
    // Setup
    LOOP {
        char i = Random::get<char>();

        // Assertion
        EXPECT_BETWEEN(i, std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
    }
}

TEST(Random, get_byte_limit) {
    // Setup
    LOOP {
        char i = Random::get<char>(1, 10);

        // Assertion
        EXPECT_BETWEEN(i, 1, 10);
    }
}

TEST(Random, get_bool_any) {
    // Setup
    int trueCount = 0;
    int falseCount = 0;

    LOOP {
        bool i = Random::get<bool>();
        if (i) ++trueCount;
        else ++falseCount;
    }

    EXPECT_NEAR(trueCount, falseCount, (trueCount + falseCount) * 0.1);
}

TEST(Random, get_bool_true) {
    // Setup
    LOOP {
        bool i = Random::get<bool>(1);

        // Assertion
        EXPECT_TRUE(i);
    }
}

TEST(Random, get_bool_false) {
    // Setup
    LOOP {
        bool i = Random::get<bool>(0);

        // Assertion
        EXPECT_FALSE(i);
    }
}

// Seed

TEST(Random, seed) {
    // Setup
    Random::seed(0);
    int i = Random::get();
    Random::seed(0);
    int j = Random::get();

    // Assertion
    EXPECT_EQ(i, j);
}

// Reseed

TEST(Random, reseed) {
    // Setup
    Random::seed(0);
    int i = Random::get();
    Random::seed(0);
    Random::reseed();
    int j = Random::get();

    // Assertion
    EXPECT_NE(i, j);
}

// Min

TEST(Random, min) {
    // Setup
    int i = Random::min();

    // Assertion
    EXPECT_EQ(i, std::numeric_limits<uint32_t>::min());
}

// Max

TEST(Random, max) {
    // Setup
    int i = Random::max();

    // Assertion
    EXPECT_EQ(i, std::numeric_limits<uint32_t>::max());
}

// Discard

TEST(Random, discard) {
    // Setup
    Random::seed(0);
    int i = Random::get();
    i = Random::get();
    Random::seed(0);
    Random::discard(1);
    int j = Random::get();

    // Assertion
    EXPECT_EQ(i, j);
}