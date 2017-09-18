//
// Created by Matthew Remmel on 9/17/17.
//

#include "gtest/gtest.h"
#include "Stack.hpp"

using namespace abraham;


// Constructors

TEST(Stack, default_constructor) {
    // Setup
    Stack<int> stack = Stack<int>();

    // Assertion
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(0, stack.size());
}

// Push

TEST(Stack, push) {
    // Setup
    Stack<int> stack = Stack<int>();
    stack.push(10);

    // Assertion
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ(10, stack.peak());
}

// Pop

TEST(Stack, pop) {
    // Setup
    Stack<int> stack = Stack<int>();
    stack.push(1).push(2);
    int popped = stack.pop();

    // Assertion
    EXPECT_EQ(2, popped);
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ(1, stack.peak());
}

TEST(Stack, pop_bounds_check) {
    // Setup
    Stack<int> stack = Stack<int>();

    // Assertion
    EXPECT_THROW(stack.pop(), OutOfBoundsException);
}

// Peak

TEST(Stack, peak) {
    // Setup
    Stack<int> stack = Stack<int>();
    stack.push(1).push(2);

    // Assertion
    EXPECT_EQ(2, stack.peak());
    EXPECT_EQ(2, stack.size());
}

TEST(Stack, peak_bounds_check) {
    // Setup
    Stack<int> stack = Stack<int>();

    // Assertion
    EXPECT_THROW(stack.peak(), OutOfBoundsException);
}

// IsEmpty

TEST(Stack, is_empty) {
    // Setup
    Stack<int> empty = Stack<int>();
    Stack<int> stack = Stack<int>();
    stack.push(10);

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(stack.isEmpty());
}

// Size

TEST(Stack, size) {
    // Setup
    Stack<int> empty = Stack<int>();
    Stack<int> stack = Stack<int>();
    stack.push(1).push(2).push(3);

    // Assertion
    EXPECT_EQ(0, empty.size());
    EXPECT_EQ(3, stack.size());
}

// Copy

TEST(Stack, copy) {
    // Setup
    Stack<int> stack = Stack<int>();
    stack.push(1);
    Stack<int> copy = stack.copy();
    stack.push(2);

    // Assertion
    EXPECT_EQ(1, copy.size());
    EXPECT_EQ(1, copy.peak());
    EXPECT_EQ(2, stack.size());
}

// Std_Stack

TEST(Stack, std_stack) {
    // Setup
    Stack<int> stack = Stack<int>();
    stack.push(1);
    std::stack<int> std_stack = stack.std_stack();

    // Assertion
    EXPECT_EQ(1, std_stack.size());
    EXPECT_EQ(1, std_stack.top());
}