//
// Created by Matthew Remmel on 9/3/17.
//

#include "Interval.hpp"

using namespace abraham;


Interval::Interval() {
    this->_nanoseconds = std::chrono::nanoseconds::zero();
}

Interval::Interval(size_t value, TimeScale scale) {
    this->setInterval(value, scale);
}

Interval& Interval::operator=(const Interval &duration) {
    this->_nanoseconds = duration._nanoseconds;
    return *this;
}

const Interval Interval::operator+(const Interval &duration) const {
    Interval d = Interval();
    d._nanoseconds = this->_nanoseconds + duration._nanoseconds;
    return d;
}

const Interval Interval::operator-(const Interval &duration) const {
    Interval d = Interval();
    d._nanoseconds = this->_nanoseconds - duration._nanoseconds;
    return d;
}

Interval& Interval::operator+=(const Interval &duration) {
    this->_nanoseconds += duration._nanoseconds;
    return *this;
}

Interval& Interval::operator-=(const Interval &duration) {
    this->_nanoseconds -= duration._nanoseconds;
    return *this;
}

bool Interval::operator==(const Interval &duration) const {
    return this->_nanoseconds == duration._nanoseconds;
}

bool Interval::operator!=(const Interval &duration) const {
    return this->_nanoseconds != duration._nanoseconds;
}

bool Interval::operator<(const Interval &duration) const {
    return this->_nanoseconds < duration._nanoseconds;
}

bool Interval::operator>(const Interval &duration) const {
    return this->_nanoseconds > duration._nanoseconds;
}

bool Interval::operator<=(const Interval &duration) const {
    return this->_nanoseconds <= duration._nanoseconds;
}

bool Interval::operator>=(const Interval &duration) const {
    return this->_nanoseconds >= duration._nanoseconds;
}

Interval Interval::zero() {
    Interval d = Interval();
    d._nanoseconds = std::chrono::nanoseconds::zero();
    return d;
}

Interval Interval::min() {
    Interval d = Interval();
    d._nanoseconds = std::chrono::nanoseconds::min();
    return d;
}

Interval Interval::max() {
    Interval d = Interval();
    d._nanoseconds = std::chrono::nanoseconds::max();
    return d;
}

size_t Interval::asNanoseconds() const {
    return this->_nanoseconds.count();
}

size_t Interval::asMicroseconds() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(this->_nanoseconds).count();
}

size_t Interval::asMilliseconds() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(this->_nanoseconds).count();
}

size_t Interval::asSeconds() const {
    return std::chrono::duration_cast<std::chrono::seconds>(this->_nanoseconds).count();
}

size_t Interval::asMinutes() const {
    return std::chrono::duration_cast<std::chrono::minutes>(this->_nanoseconds).count();
}

size_t Interval::asHours() const {
    return std::chrono::duration_cast<std::chrono::hours>(this->_nanoseconds).count();
}

void Interval::setInterval(size_t value, TimeScale scale) {
    switch (scale) {
        case TimeScale::nanoseconds:
            this->_nanoseconds = std::chrono::nanoseconds(value);
            break;

        case TimeScale::microseconds:
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::microseconds(value));
            break;

        case TimeScale::milliseconds:
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::milliseconds(value));
            break;

        case TimeScale::seconds:
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(value));
            break;

        case TimeScale::minutes:
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::minutes(value));
            break;

        case TimeScale::hours:
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::hours(value));
            break;
    }
}

std::chrono::nanoseconds Interval::std_nanoseconds() const {
    return this->_nanoseconds;
}
