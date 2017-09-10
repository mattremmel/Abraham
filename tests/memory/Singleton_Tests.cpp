//
// Created by Matthew Remmel on 9/4/17.
//

#include "gtest/gtest.h"
#include "Singleton.hpp"

using namespace abraham;


TEST(Singleton, shared_instance) {
    // Setup
    Singleton<int>::SharedInstance() = 5;

    // Assertions
    EXPECT_EQ(5, Singleton<int>::SharedInstance());
}

TEST(Singleton, shared_instance_reference) {
    // Setup
    int& n = Singleton<int>::SharedInstance();
    n = 5;

    // Assertions
    EXPECT_EQ(5, Singleton<int>::SharedInstance());
}