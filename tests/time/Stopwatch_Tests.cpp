//
// Created by Matthew Remmel on 9/4/17.
//

#include "gtest/gtest.h"
#include "abraham/time/Stopwatch.h"
#include <thread>

using namespace abraham;


TEST(Stopwatch, default_constructor) {
    // Setup
    Stopwatch s = Stopwatch();

    // Assertions
    EXPECT_EQ(Interval(0ns), s.elapsedTime());
    EXPECT_FALSE(s.isRunning());
}

TEST(Stopwatch, did_start) {
    // Setup
    Stopwatch s = Stopwatch();
    s.start();
    std::this_thread::sleep_for(100ns);

    // Assertions
    EXPECT_TRUE(s.isRunning());
    EXPECT_GT(s.elapsedTime(), Interval(0ns));
}

TEST(Stopwatch, did_stop) {
    // Setup
    Stopwatch s = Stopwatch();
    s.start();
    std::this_thread::sleep_for(100ns);
    Interval stop = s.stop();
    std::this_thread::sleep_for(100ns);
    Interval elapsed = s.elapsedTime();

    // Assertions
    EXPECT_FALSE(s.isRunning());
    EXPECT_EQ(stop, elapsed);
}

TEST(Stopwatch, did_reset) {
    // Setup
    Stopwatch s = Stopwatch();
    s.start();
    std::this_thread::sleep_for(100ns);
    s.stop();
    s.reset();

    // Assertions
    EXPECT_FALSE(s.isRunning());
    EXPECT_EQ(Interval(0ns), s.elapsedTime());
}