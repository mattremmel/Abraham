//
// Created by Matthew Remmel on 9/3/17.
//

#include "gtest/gtest.h"
#include "abraham/time/Interval.h"

using namespace abraham;


TEST(Interval, default_constructor) {
    // Setup
    Interval i = Interval();

    // Assertion
    EXPECT_EQ(0, i.std_nanoseconds().count());
    EXPECT_EQ(0, i.asNanoseconds());
    EXPECT_EQ(0, i.asMicroseconds());
    EXPECT_EQ(0, i.asMilliseconds());
    EXPECT_EQ(0, i.asSeconds());
    EXPECT_EQ(0, i.asMinutes());
    EXPECT_EQ(0, i.asHours());
}

TEST(Interval, value_constructor) {
    // Setup
    Interval i = Interval(1, TimeScale::seconds);

    // Assertion
    EXPECT_EQ(1, std::chrono::duration_cast<std::chrono::seconds>(i.std_nanoseconds()).count());
    EXPECT_EQ(1'000'000'000, i.asNanoseconds());
    EXPECT_EQ(1'000'000, i.asMicroseconds());
    EXPECT_EQ(1000, i.asMilliseconds());
    EXPECT_EQ(1, i.asSeconds());
    EXPECT_EQ(0, i.asMinutes());
    EXPECT_EQ(0, i.asHours());
}

TEST(Interval, std_literals) {
    // Setup
    Interval nano = 10ns;
    Interval micro = 10us;
    Interval milli = 10ms;
    Interval sec = 10s;
    Interval min = 10min;
    Interval hour = 10h;

    // Assertion
    EXPECT_EQ(10, nano.asNanoseconds());
    EXPECT_EQ(10, micro.asMicroseconds());
    EXPECT_EQ(10, milli.asMilliseconds());
    EXPECT_EQ(10, sec.asSeconds());
    EXPECT_EQ(10, min.asMinutes());
    EXPECT_EQ(10, hour.asHours());
}

TEST(Interval, set_interval_value) {
    // Setup
    Interval i = Interval();
    i.setInterval(1, TimeScale::milliseconds);

    // Assertion
    EXPECT_EQ(1, i.asMilliseconds());
}

TEST(Interval, set_interval_literal) {
    // Setup
    Interval i = Interval();
    i.setInterval(1ms);

    // Assertion
    EXPECT_EQ(1, i.asMilliseconds());
}