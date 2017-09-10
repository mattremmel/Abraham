//
// Created by Matthew Remmel on 9/2/17.
//

#include "gtest/gtest.h"
#include "Timer.hpp"

using namespace abraham;


// Constructors

TEST(Timer, default_constructor) {
    // Setup
    Timer t = Timer();

    // Assertion
    EXPECT_FALSE(t.isAlive());
    EXPECT_EQ(0, t.getCallCount());
    EXPECT_EQ(0, t.getRepeatCount());
    EXPECT_EQ(0, t.getTimePoint());
    EXPECT_EQ(Interval::zero(), t.getInterval());
}

TEST(Timer, interval_constructor) {
    // Setup
    Timer t = Timer(1s, [](){});

    // Assertion
    EXPECT_FALSE(t.isAlive());
    EXPECT_EQ(0, t.getCallCount());
    EXPECT_EQ(1, t.getRepeatCount());
    EXPECT_EQ(0, t.getTimePoint());
    EXPECT_EQ(Interval(1s), t.getInterval());
}

TEST(Timer, repeat_constructor) {
    // Setup
    Timer t = Timer(1s, 5, [](){});

    // Assertion
    EXPECT_FALSE(t.isAlive());
    EXPECT_EQ(0, t.getCallCount());
    EXPECT_EQ(5, t.getRepeatCount());
    EXPECT_EQ(0, t.getTimePoint());
    EXPECT_EQ(Interval(1s), t.getInterval());
}

TEST(Timer, timepoint_constructor) {
    // Setup
    Timer t = Timer(12345, [](){});

    // Assertion
    EXPECT_FALSE(t.isAlive());
    EXPECT_EQ(0, t.getCallCount());
    EXPECT_EQ(1, t.getRepeatCount());
    EXPECT_EQ(12345, t.getTimePoint());
    EXPECT_EQ(Interval::zero(), t.getInterval());
}

TEST(Timer, set_repeat_count) {
    // Setup
    Timer t = Timer();
    t.setRepeatCount(10);

    // Assertion
    EXPECT_EQ(10, t.getRepeatCount());
}

// SetInterval

TEST(Timer, set_interval) {
    // Setup
    Timer t = Timer();
    t.setInterval(100ns);

    // Assertion
    EXPECT_EQ(Interval(100ns), t.getInterval());
}

// SetTimePoint

TEST(Timer, set_timepoint) {
    // Setup
    Timer t = Timer();
    t.setTimePoint(12345);

    // Assertion
    EXPECT_EQ(12345, t.getTimePoint());
}

// SetTarget

TEST(Timer, set_target) {
    // Setup
    Timer t = Timer(1ms, [](){});
    int i = 0;
    auto target = [&i]() { i = 5; };
    t.setTarget(target);

    t.start(false);

    // Assertion
    EXPECT_EQ(i, 5);
    EXPECT_EQ(1, t.getCallCount());
}

// Start

TEST(Timer, started_sync) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, [&i](){
        i = 5;
    });

    t.start(false);

    // Assertion
    EXPECT_EQ(5, i);
    EXPECT_EQ(1, t.getCallCount());
}

TEST(Timer, started_async) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, [&i](){
        i = 5;
    });

    t.start();
    t.waitUntilFinished();

    // Assertion
    EXPECT_EQ(5, i);
    EXPECT_EQ(1, t.getCallCount());
}

// TODO: Test timepoint with Timer

TEST(Timer, did_repeat_five_sync) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, 5, [&i](){
        ++i;
    });

    t.start(false);

    // Assertion
    EXPECT_EQ(5, i);
    EXPECT_EQ(5, t.getCallCount());
}

TEST(Timer, did_repeat_five_async) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, 5, [&i](){
        ++i;
    });

    t.start();
    t.waitUntilFinished();

    // Assertion
    EXPECT_EQ(5, i);
    EXPECT_EQ(5, t.getCallCount());
}

// Stop

TEST(Timer, stopped_early_sync) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, 5, [&i, &t](){
        ++i;
        if (i == 3) { t.stop(); }
    });

    t.start(false);

    // Assertion
    EXPECT_EQ(3, i);
    EXPECT_EQ(3, t.getCallCount());
}

TEST(Timer, stopped_early_async) {
    // Setup
    int i = 0;
    Timer t = Timer(1ms, 5, [&i, &t](){
        ++i;
        if (i == 3) { t.stop(); }
    });

    t.start();
    t.waitUntilFinished();

    // Assertion
    EXPECT_EQ(3, i);
    EXPECT_EQ(3, t.getCallCount());
}