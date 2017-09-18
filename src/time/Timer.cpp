//
// Created by Matthew Remmel on 9/2/17.
//

#include "Timer.hpp"

using namespace abraham;


Timer::Timer() {
    this->_isAlive = false;
    this->_callCount = 0;
    this->_repeatCount = 0;
    this->_interval = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::nanoseconds::zero());
    this->_timepoint = 0;
    this->_callback = []() { return; };
}

Timer::Timer(const Interval& interval, const std::function<void(void)>& callback) {
    this->_isAlive = false;
    this->_callCount = 0;
    this->_repeatCount = 1;
    this->_interval = interval.std_nanoseconds();
    this->_timepoint = 0;
    this->_callback = callback;
}

Timer::Timer(const Interval& interval, size_t repeat_count,
             const std::function<void(void)>& callback) {
    this->_isAlive = false;
    this->_callCount = 0;
    this->_repeatCount = repeat_count;
    this->_interval = interval.std_nanoseconds();
    this->_timepoint = 0;
    this->_callback = callback;
}

Timer::Timer(time_t timepoint, const std::function<void(void)>& callback) {
    this->_isAlive = false;
    this->_callCount = 0;
    this->_repeatCount = 1;
    this->_interval = Interval::zero().std_nanoseconds();
    this->_timepoint = timepoint;
    this->_callback = callback;
}

Timer::Timer(time_t timepoint, const Interval& interval, size_t repeat_count,
             const std::function<void(void)>& callback) {
    this->_isAlive = false;
    this->_callCount = 0;
    this->_repeatCount = repeat_count;
    this->_interval = interval.std_nanoseconds();
    this->_timepoint = timepoint;
    this->_callback = callback;
}

bool Timer::isAlive() const {
    return this->_isAlive;
}

size_t Timer::getCallCount() const {
    return this->_callCount;
}

size_t Timer::getRepeatCount() const {
    return this->_repeatCount;
}

Interval Timer::getInterval() const {
    return Interval(this->_interval.count(), TimeScale::nanoseconds);
}

time_t Timer::getTimePoint() const {
    return this->_timepoint;
}

std::function<void(void)> Timer::getTarget() const {
    return this->_callback;
}

void Timer::setRepeatCount(size_t count) {
    this->_repeatCount = count;
}

void Timer::setInterval(const Interval& interval) {
    this->_interval = interval.std_nanoseconds();
}

void Timer::setTimePoint(time_t timepoint) {
    this->_timepoint = timepoint;
}

void Timer::setTarget(const std::function<void(void)>& callback) {
    this->_callback = callback;
}

void Timer::start(bool async) {
    if (this->_isAlive) return;

    this->_isAlive = true;

    if (async) {
        this->_thread = std::thread(&Timer::_run, this);
    } else {
        this->_run();
    }
}

void Timer::stop() {
    this->_isAlive = false;
}

void Timer::reset() {
    this->_callCount = 0;
}

void Timer::_run() {

    // If timepoint is set
    if (this->_timepoint > time(0)) {
        std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(this->_timepoint));
        this->_callback();
        ++this->_callCount;
    }

    while (this->_isAlive && (this->_repeatCount == Forever || this->_callCount < this->_repeatCount)) {
        std::this_thread::sleep_for(this->_interval);
        this->_callback();
        ++this->_callCount;
    }

    this->_isAlive = false;
}

void Timer::waitUntilFinished() {
    if (this->_thread.joinable()) {
        this->_thread.join();
    }
}

const size_t Timer::Forever = -1;
