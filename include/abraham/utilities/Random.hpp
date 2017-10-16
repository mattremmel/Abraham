//
// Created by Matthew Remmel on 10/12/17.
//

#ifndef ABRAHAM_RANDOM_HPP
#define ABRAHAM_RANDOM_HPP

#include <random>
#include <chrono>
#include <type_traits>
#include <cassert>


namespace abraham {

    // Internal functions
    namespace details {
        /**
         * True if type T is applicable by a std::uniform_int_distribution
         */
        template<typename T>
        struct is_integer_type {
            static constexpr bool value =
                    std::is_same<T, short>::value
                    || std::is_same<T, int>::value
                    || std::is_same<T, long>::value
                    || std::is_same<T, long long>::value
                    || std::is_same<T, unsigned short>::value
                    || std::is_same<T, unsigned int>::value
                    || std::is_same<T, unsigned long>::value
                    || std::is_same<T, unsigned long long>::value;
        };

        /**
         * True if type T is floating type.
         */
        template<typename T>
        struct is_floating_type {
            static constexpr bool value =
                    std::is_same<T, float>::value
                    || std::is_same<T, double>::value
                    || std::is_same<T, long double>::value;
        };

        /**
         * True if type T is byte type.
         */
        template<typename T>
        struct is_byte_type {
            static constexpr bool value =
                    std::is_same<T, char>::value
                    || std::is_same<T, signed char>::value
                    || std::is_same<T, unsigned char>::value;
        };
    }


    /**
     * Static random number generator, based on effolkronium/random.
     * Alias has been added so StaticRandom class can be accessed with the form Random::get().
     */
    class StaticRandom {
    protected:
        /**
         * The internal random number engine used by the class.
         */
        static std::mt19937 _engine;

    public:
        /**
         * Template overload for retrieving integer type random numbers.
         * @note Not thread safe but more efficient than thread or local scoped generator.
         * @param from - The inclusive lower limit of the randomly generated number.
         * @param to - The inclusive upper limit of the randomly generated number.
         * @return A random integer between or including the provided limits.
         */
        template<typename T = int>
        static typename std::enable_if<details::is_integer_type<T>::value, T>::type
        get(T from = std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max());

        /**
         * Template overload for retrieving real type random numbers.
         * @param from - The inclusive lower limit of the randomly generated number.
         * @param to - The inclusive upper limit of the randomly generated number.
         * @return A real type value between or including the provided limits.
         */
        template<typename T>
        static typename std::enable_if<details::is_floating_type<T>::value, T>::type
        get(T from = std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max());

        /**
         * Template overload for retrieving byte type random numbers.
         * @param from - The inclusive lower limit of the randomly generated number.
         * @param to - The inclusive upper limit of the randomly generated number.
         * @return A byte type value between or including the provided limits.
         */
        template<typename T>
        static typename std::enable_if<details::is_byte_type<T>::value, T>::type
        get(T from = std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max());

        /**
         * Template overload for retrieving random boolean values.
         * @param probability - A 0-1 value representing the probability the boolean will be true.
         * @return A random boolean value.
         */
        template<typename T>
        static typename std::enable_if<std::is_same<T, bool>::value, bool>::type
        get(double probability = 0.5);

        /**
         * Set a seed for the random number engine.
         * @param seed - The seed value to set.
         */
        static void seed(unsigned int seed);

        /**
         * Reset the seed to a random value.
         */
        static void reseed();

        /**
         * @return The smallest possible value producible by the internal engine, before being mapped to a distribution.
         */
        static unsigned int min();

        /**
         * @return The largest possible value producible by the internal engine, before being mapped to a distribution.
         */
        static unsigned int max();

        /**
         * Advances the internal state a specified number of times.
         * @param n - The number of times to advance the state.
         * @note Equivalent to retrieving a value and discarding it.
         */
        static void discard(unsigned long long n);
    };

    using Random = StaticRandom;


    // Template implementation

    std::mt19937 StaticRandom::_engine = std::mt19937(
            static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

    template<typename T>
    typename std::enable_if<details::is_integer_type<T>::value, T>::type
    StaticRandom::get(T from, T to) {
        if (from < to) {
            return std::uniform_int_distribution<T>{from, to}(_engine);
        } else {
            return std::uniform_int_distribution<T>{to, from}(_engine);
        }
    };

    template<typename T>
    typename std::enable_if<details::is_floating_type<T>::value, T>::type
    StaticRandom::get(T from, T to) {
        if (from < to) {
            return std::uniform_real_distribution<T>{from, to}(_engine);
        } else {
            return std::uniform_real_distribution<T>{to, from}(_engine);
        }
    };

    template<typename T>
    typename std::enable_if<details::is_byte_type<T>::value, T>::type
    StaticRandom::get(T from, T to) {
        // Choose between short and unsigned short for byte conversion
        using short_type = typename std::conditional<std::is_signed<T>::value, short, unsigned short>::type;
        return static_cast<T>(get<short_type>(from, to));
    }

    template<typename T>
    typename std::enable_if<std::is_same<T, bool>::value, bool>::type
    StaticRandom::get(const double probability) {
        assert(0 <= probability && 1 >= probability);
        return std::bernoulli_distribution{probability}(_engine);
    }

    void StaticRandom::seed(unsigned int seed) {
        _engine.seed(seed);
    }

    void StaticRandom::reseed() {
        _engine.seed(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    }

    unsigned int StaticRandom::min() {
        return _engine.min();
    }

    unsigned int StaticRandom::max() {
        return _engine.max();
    }

    void StaticRandom::discard(unsigned long long n) {
        _engine.discard(n);
    }
}

#endif //ABRAHAM_RANDOM_HPP
