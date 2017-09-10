//
// Created by Matthew Remmel on 9/4/17.
//

#ifndef ABRAHAM_STOPWATCH_HPP
#define ABRAHAM_STOPWATCH_HPP

#include <chrono>
#include "Interval.hpp"


namespace abraham {

    /**
     * A class used for measuring time intervals.
     */
    class Stopwatch {
    protected:
        /**
         * Internal representation of the start time of the Stopwatch.
         */
        std::chrono::time_point<std::chrono::high_resolution_clock> _begin;

        /**
         * Internal representation of the end time of the Stopwatch.
         */
        std::chrono::time_point<std::chrono::high_resolution_clock> _end;

        /**
         * Indicates whether the Stopwatch is currently running.
         */
        bool _isRunning;

    public:
        /**
         * Default constructor that creates a blank Stopwatch object.
         */
        Stopwatch();

        /**
         * Starts the Stopwatch.
         */
        void start();

        /**
         * Stops the Stopwatch.
         * @return An Interval object representing the time between starting and stopping the Stopwatch.
         */
        Interval stop();

        /**
         * Resets the start time of the Stopwatch to the current time.
         */
        void reset();

        /**
         * @return true if the Stopwatch is running; false otherwise.
         */
        bool isRunning() const;

        /**
         * @return An Interval object representing the time between starting the Stopwatch, and the current time if running, or the end time if stopped.
         */
        Interval elapsedTime() const;
    };
}

#endif //ABRAHAM_STOPWATCH_HPP
