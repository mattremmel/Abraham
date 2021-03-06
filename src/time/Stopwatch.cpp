//
// Created by Matthew Remmel on 9/4/17.
//

#include "Stopwatch.hpp"

using namespace abraham;


Stopwatch::Stopwatch() {
    std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
    this->_begin = now;
    this->_end = now;
    this->_isRunning = false;
}

Stopwatch::Stopwatch(const Stopwatch& stopwatch) {
    this->_begin = stopwatch._begin;
    this->_end = stopwatch._end;
}

Stopwatch::Stopwatch(Stopwatch&& stopwatch) noexcept {
    this->_begin = stopwatch._begin;
    this->_end = stopwatch._end;
}

Stopwatch& Stopwatch::operator=(const Stopwatch& stopwatch) {
    if (this == &stopwatch) return *this;
    this->_begin = stopwatch._begin;
    this->_end = stopwatch._end;
    return *this;
}

Stopwatch& Stopwatch::operator=(Stopwatch&& stopwatch) noexcept {
    if (this == &stopwatch) return *this;
    this->_begin = stopwatch._begin;
    this->_end = stopwatch._end;
    return *this;
}

void Stopwatch::start() {
    this->_begin = std::chrono::high_resolution_clock::now();
    this->_isRunning = true;
}

Interval Stopwatch::stop() {
    if (!this->_isRunning) {
        return Interval(0ns);
    }

    this->_end = std::chrono::high_resolution_clock::now();
    this->_isRunning = false;
    return Interval(std::chrono::duration_cast<std::chrono::nanoseconds>(this->_end - this->_begin));
}

void Stopwatch::reset() {
    std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
    this->_begin = now;
    this->_end = now;
}

bool Stopwatch::isRunning() const {
    return this->_isRunning;
}

Interval Stopwatch::elapsedTime() const {
    if (this->_isRunning) {
        std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
        return Interval(std::chrono::duration_cast<std::chrono::nanoseconds>(now - this->_begin));
    } else {
        return Interval(std::chrono::duration_cast<std::chrono::nanoseconds>(this->_end - this->_begin));
    }
}