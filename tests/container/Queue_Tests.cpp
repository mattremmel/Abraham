//
// Created by Matthew Remmel on 9/18/17.
//

#include "gtest/gtest.h"
#include "Queue.hpp"

using namespace abraham;


// Constructors

TEST(Queue, default_constructor) {
    // Setup
    Queue<int> queue = Queue<int>();

    // Assertion
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(0, queue.size());
}

// Push

TEST(Queue, push) {
    // Setup
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2);

    // Assertion
    EXPECT_EQ(2, queue.size());
    EXPECT_EQ(1, queue.peakFront());
    EXPECT_EQ(2, queue.peakBack());
}

// Pop

TEST(Queue, pop) {
    // Setup
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2);
    int popped = queue.pop();

    // Assertion
    EXPECT_EQ(1, popped);
    EXPECT_EQ(1, queue.size());
    EXPECT_EQ(2, queue.peakFront());
}

TEST(Queue, pop_bounds_check) {
    // Setup
    Queue<int> queue = Queue<int>();

    // Assertion
    EXPECT_THROW(queue.pop(), OutOfBoundsException);
}

// PeakFront

TEST(Queue, peak_front) {
    // Setup
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2);

    // Assertion
    EXPECT_EQ(1, queue.peakFront());
    EXPECT_EQ(2, queue.size());
}

TEST(Queue, peak_front_bounds_check) {
    // Setup
    Queue<int> queue = Queue<int>();

    // Assertion
    EXPECT_THROW(queue.peakFront(), OutOfBoundsException);
}

// PeakBack

TEST(Queue, peak_back) {
    // Setup
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2);

    // Assertion
    EXPECT_EQ(2, queue.peakBack());
    EXPECT_EQ(2, queue.size());
}

TEST(Queue, peak_back_bounds_check) {
    // Setup
    Queue<int> queue = Queue<int>();

    // Assertion
    EXPECT_THROW(queue.peakBack(), OutOfBoundsException);
}

// IsEmpty

TEST(Queue, is_empty) {
    // Setup
    Queue<int> empty = Queue<int>();
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2);

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(queue.isEmpty());
}

// Size

TEST(Queue, size) {
    Queue<int> empty = Queue<int>();
    Queue<int> queue = Queue<int>();
    queue.push(1).push(2).push(3);

    // Assertion
    EXPECT_EQ(0, empty.size());
    EXPECT_EQ(3, queue.size());
}

// Copy

TEST(Queue, copy) {
    Queue<int> queue = Queue<int>();
    queue.push(1);
    Queue<int> copy = queue.copy();
    queue.push(2);

    // Assertion
    EXPECT_EQ(1, copy.size());
    EXPECT_EQ(1, copy.peakFront());
    EXPECT_EQ(2, queue.size());
}

// Std_Queue

TEST(Queue, std_queue) {
    // Setup
    Queue<int> queue = Queue<int>();
    queue.push(1);
    std::queue<int> std_queue = queue.std_queue();

    // Assertion
    EXPECT_EQ(1, std_queue.size());
    EXPECT_EQ(1, std_queue.front());
}