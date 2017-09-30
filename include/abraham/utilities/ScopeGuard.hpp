//
// Created by Matthew Remmel on 9/28/17.
//

#ifndef ABRAHAM_SCOPEGUARD_HPP
#define ABRAHAM_SCOPEGUARD_HPP

#include <functional>
#include <exception>

// Macros for creating unique variable names using line numbers.
#define SG_UNIQUE_NAME2(name, line) name ## line
#define SG_UNIQUE_NAME(name, line) SG_UNIQUE_NAME2(name, line)

/**
 * Macro to creates a ScopeGuard that executes at the exit of the current scope, even if an exception was thrown.
 */
#define scope_exit(code) auto SG_UNIQUE_NAME(sg_exit, __LINE__) = abraham::MakeScopeGuard(ScopeLevel::EXIT, [&]{code;})

/**
 * Macro that creates a ScopeGuard that executes at the exit of the current scope, unless an exception was thrown.
 */
#define scope_success(code) auto SG_UNIQUE_NAME(sg_success, __LINE__) = abraham::MakeScopeGuard(abraham::ScopeLevel::SUCCESS, [&]{code;})

/**
 * Macro that creates a ScopeGuard that executes at the exit of the current scope, only if an exception was thrown.
 */
#define scope_failure(code) auto SG_UNIQUE_NAME(sg_failure, __LINE__) = abraham::MakeScopeGuard(abraham::ScopeLevel::FAILURE, [&]{code;})


namespace abraham {

    /**
     * Enum that represents the different scope levels of the scope guard.
     */
    enum class ScopeLevel {
        EXIT = 0,
        SUCCESS = 1,
        FAILURE = 2
    };

    /**
     * A class that can be used to for resource management when exception safety is a concern. In some cases they are
     * used instead of nesting try/catch blocks because scope guards scale better than a series of nested and complicated
     * try/catch logic.
     *
     * They can be used via the three provided macros:
     *
     * scope_exit(code);
     *     - ScopeGuard that executes at the exit of the current scope, even if an exception was thrown.
     *
     * scope_success(code);
     *     - ScopeGuard that executes at the exit of the current scope, unless an exception was thrown.
     *
     * scope_failure(code);
     *     - ScopeGuard that executes at the exit of the current scope, only if an exception was thrown.
     *
     * Example:
     *     FILE file = fopen(test.txt);
     *     scope_exit(fclose(file));
     */
    template<typename F>
    class ScopeGuard {
    protected:
        /**
         * The scope level of the ScopeGuard.
         */
        ScopeLevel _level;

        /**
         * The code that should be run when the ScopeGuard executes.
         */
        F _target;

    public:
        /**
         * Constructor that configures a ScopeGuard with the provided parameters.
         * @param level - The level of the ScopeGuard.
         * @param target - The code to be run with the ScopeGuard executes.
         */
        ScopeGuard(ScopeLevel level, F target) : _level(level), _target(target) { };

        /**
         * Destructor that will execute the target if the scope conditions are met.
         */
        ~ScopeGuard() {
            // Execute if scope is exit.
            if (this->_level == ScopeLevel::EXIT) {
                this->_target();
                return;
            }

            // Find out if exception is uncaught in current scope.
            bool is_unwinding = std::uncaught_exception();

            // Execute if scope is success and is not unwinding.
            if (this->_level == ScopeLevel::SUCCESS && !is_unwinding) {
                this->_target();
                return;
            }

            // Execute if scope is failure and is unwinding.
            if (this->_level == ScopeLevel::FAILURE && is_unwinding) {
                this->_target();
                return;
            }
        };
    };

    /**
     * Factory style method to create a ScopeGuard with the provided parameters.
     * @param level - The scope level of the ScopeGuard.
     * @param target - The code that should be called when the ScopeGuard executes.
     * @return A ScopeGuard configured with the provided parameters.
     */
    template<typename F>
    ScopeGuard<F> MakeScopeGuard(ScopeLevel level, F target) {
        return ScopeGuard<F>(level, target);
    }
}

#endif //ABRAHAM_SCOPEGUARD_HPP
