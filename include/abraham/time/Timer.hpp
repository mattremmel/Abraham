//
// Created by Matthew Remmel on 9/2/17.
//

#ifndef ABRAHAM_TIMER_HPP
#define ABRAHAM_TIMER_HPP

#include "Interval.hpp"
#include <chrono>
#include <thread>

namespace abraham {

    /**
     * A class that allows a function to be run at a set interval with varying options.
     */
    class Timer {
    protected:
        /**
         * The thread object that's running the asynchronous Timer.
         */
        std::thread _thread;

        /**
         * Used to determine whether the timer is currently running.
         */
        volatile bool _isAlive;

        /**
         * A counter used to keep track of how many times the target has been called.
         */
        volatile size_t _callCount;

        /**
         * The number of times the target should be called.
         */
        size_t _repeatCount;

        /**
         * The time interval in between calls to the target.
         */
        std::chrono::nanoseconds _interval;

        /**
         * The point in time that the target should be executed.
         */
        time_t _timepoint;

        /**
         * The function that should be called when the Timer fires.
         */
        std::function<void(void)> _target;

        /**
         * The function that starts the Timer loop.
         */
        void _run();

    public:
        /**
         * Default constructor that creates a Timer that returns when started.
         */
        Timer();

        /**
         * Basic constructor that creates a Timer which runs the target after a set interval.
         * @param interval - A duration that determines the amount of time between calls to the target.
         * @param target - The function that's called when the Timer fires.
         */
        Timer(const Interval& interval, const std::function<void(void)>& target);

        /**
         * Constructor that creates a Timer which runs the target at a set interval, for the number of times specified.
         * @param interval - A duration that determines the amount of time between calls to the target.
         * @param repeat_count - The number of times that the target should be called.
         * @param target - The function that's called when the Timer fires.
         */
        Timer(const Interval& interval, size_t repeat_count,
              const std::function<void(void)>& target);

        /**
         * Constructor that creates a Timer which runs the target at the specified timepoint in the future.
         * @param timepoint - The point in time that the target should be executed.
         * @param target - The function that's called when the Timer fires.
         */
        Timer(time_t timepoint, const std::function<void(void)>& target);

        /**
         * Constructor that creates a Timer which runs the target starting at the specified timepoint at a set interval, for the number of times specified.
         * @param timepoint - The point in time that the target should be executed.
         * @param interval - A duration that determines the amount of time between calls to the target.
         * @param repeat_count - The number of times that the target should be called.
         * @param target - The function that's called when the Timer fires.
         */
        Timer(time_t timepoint, const Interval& interval, size_t repeat_count,
              const std::function<void(void)>& target);

        /**
         * @return true if the Timer is running; false otherwise.
         */
        bool isAlive() const;

        /**
         * @return The number of times that the target has been called.
         */
        size_t getCallCount() const;

        /**
         * @return The number of times that the target should be called.
         */
        size_t getRepeatCount() const;

        /**
         * @return The time interval between calls to the target.
         */
        Interval getInterval() const;

        /**
         * @return The point in time that the target should be executed.
         */
        time_t getTimePoint() const;

        /**
         * @return The function that's called when the Timer fires.
         */
        std::function<void(void)> getTarget() const;

        /**
         * Sets the number of times that the target should be called.
         * @param count - The number of times that the target should be called.
         */
        void setRepeatCount(size_t count);

        /**
         * Sets the time interval between calls to the target.
         * @param interval - A duration that determines that amount of time between calls to the target.
         */
        void setInterval(const Interval& interval);

        /**
         * Sets the point in time that the target should be executed.
         * @param timepoint - The point in time that the target should be executed.
         */
        void setTimePoint(time_t timepoint);

        /**
         * Sets the function that should be called when the Timer fires.
         * @param target - The function that's called when the Timer fires.
         */
        void setTarget(const std::function<void(void)>& target);

        /**
         * Starts the Timer loop.
         * @param async - Whether the Timer should be executed asynchronously. Default = true.
         */
        void start(bool async = true);

        /**
         * Stops the Timer loop.
         */
        void stop();

        /**
         * Resets the internal call count, but retains the Timer settings. If Timer was running, it remains running.
         */
        void reset();

        /**
         * This function blocks until the asynchronous thread exits.
         */
        void waitUntilFinished();

        /**
         * The value representing repeating forever.
         */
        static const size_t Forever;
    };
}

#endif //ABRAHAM_TIMER_HPP
