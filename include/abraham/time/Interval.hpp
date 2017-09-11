//
// Created by Matthew Remmel on 9/3/17.
//

#ifndef ABRAHAM_DURATION_HPP
#define ABRAHAM_DURATION_HPP

#include <chrono>

using namespace std::chrono_literals;


namespace abraham {

    /**
     * Values used to represent different time scales and magnitudes.
     */
    enum class TimeScale {
        nanoseconds,
        microseconds,
        milliseconds,
        seconds,
        minutes,
        hours
    };

    /**
     * Used to represent a interval or interval of time.
     */
    class Interval {
    protected:
        /**
         * The internal nanosecond representation of a time interval.
         */
        std::chrono::nanoseconds _nanoseconds;

    public:
        /**
         * Default constructor that creates an Interval of 0 nanoseconds.
         */
        Interval();

        /**
         * Constructor that creates an Interval in terms of a value and a scale.
         * @param value - The integer value of the time interval.
         * @param scale - The scale of the provided integer value.
         */
        Interval(size_t value, TimeScale scale);

        /**
         * Constructor that creates an Interval from a std::chrono::duration value.
         * @param duration - The std::chrono::duration value.
         */
        template<class Rep, class Period>
        Interval(const std::chrono::duration<Rep, Period>& duration) {
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
        };

        /**
         * Operator overload to set a new Interval value using the '=' operator.
         * @param interval - The Interval that the new value will be set to.
         * @return A self reference.
         */
        Interval& operator=(const Interval& interval);

        /**
         * Operator overload to add two Interval objects using the '+' operator.
         * @param interval - The value to add this Interval to.
         * @return A new Interval with the combined value.
         */
        const Interval operator+(const Interval& interval) const;

        /**
         * Operator overload to add subtract Interval objects using the '-' operator.
         * @param interval - The value to be subtracted from this Interval.
         * @return A new Interval with the subtracted value.
         */
        const Interval operator-(const Interval& interval) const;

        /**
         * Operator overload to add this Interval with another in place using '+=' operator.
         * @param interval - The value to add to this Interval.
         * @return A self reference.
         */
        Interval& operator+=(const Interval& interval);


        /**
         * Operator overload to subtract another Interval from this one in place using the '-=' operator.
         * @param interval - The value to subtract from this Interval.
         * @return A self reference.
         */
        Interval& operator-=(const Interval& interval);

        /**
         * Operator overload to check the equality of two Interval objects using the '==' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if the two Interval objects are equal in value; false otherwise.
         */
        bool operator==(const Interval& interval) const;

        /**
         * Operator overload to check the inequality of two Interval objects using the '!=' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if the two Interval objects are not equal in value; false otherwise.
         */
        bool operator!=(const Interval& interval) const;

        /**
         * Operator overload to check if this Interval value is less than another using the '<' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if this Interval is smaller in value than the provided Interval; false otherwise.
         */
        bool operator<(const Interval& interval) const;

        /**
         * Operator overload to check if this Interval value is greater than another using the '>' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if this Interval is greater in value than the provided Interval; false otherwise.
         */
        bool operator>(const Interval& interval) const;

        /**
         * Operator overload to check if this Interval value is less than or equal to another using the '<=' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if this Interval is less than or equal in value to the provided Interval; false otherwise.
         */
        bool operator<=(const Interval& interval) const;

        /**
         * Operator overload to check if this Interval value is greater than or equal to another using the '>=' operator.
         * @param interval - The value to compare this Interval to.
         * @return true if this Interval is greater than or equal in value to the provided Interval; false otherwise.
         */
        bool operator>=(const Interval& interval) const;

        /**
         * @return An Interval object representing a time interval of 0 nanoseconds.
         */
        static Interval zero();

        /**
         * @return An Interval object representing the minimum representable time interval.
         */
        static Interval min();

        /**
         * @return An Interval object representing the maximum representable time interval.
         */
        static Interval max();

        /**
         * @return An integer representation of the number of nanoseconds.
         */
        size_t asNanoseconds() const;

        /**
         * @return An integer representation of the number of microseconds. Any remainder is truncated.
         */
        size_t asMicroseconds() const;

        /**
         * @return An integer representation of the number of milliseconds. Any remainder is truncated.
         */
        size_t asMilliseconds() const;

        /**
         * @return An integer representation of the number of seconds. Any remainder is truncated.
         */
        size_t asSeconds() const;

        /**
         * @return An integer representation of the number of minutes. Any remainder is truncated.
         */
        size_t asMinutes() const;

        /**
         * @return An integer representation of the number of hours. Any remainder is truncated.
         */
        size_t asHours() const;

        /**
         * Sets a new value for the Interval.
         * @param value - The integer value of the time interval.
         * @param scale - The scale of the provided integer value.
         */
        void setInterval(size_t value, TimeScale scale);

        /**
         * Sets a new value for the Interval from a std::chrono::duration value or literal.
         * @param duration - The std::chrono::duration value or literal.
         */
        template<class Rep, class Period>
        void setInterval(const std::chrono::duration<Rep, Period>& duration) {
            this->_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
        };

        /**
         * @return The std::chrono::nanoseconds internal representation of the Interval.
         */
        std::chrono::nanoseconds std_nanoseconds() const;

    };
}

#endif //ABRAHAM_DURATION_HPP
