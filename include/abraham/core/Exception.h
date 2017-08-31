//
// Created by Matthew Remmel on 8/31/17.
//

#ifndef ABRAHAM_EXCEPTION_H
#define ABRAHAM_EXCEPTION_H

#include <stdexcept>


namespace abraham {

    /**
     * The base runtime exception class that all Abraham exceptions inherit from.
     */
    class Exception : public std::runtime_error {
    public:
        /**
         * Exception constructor that takes a message as an argument.
         */
        Exception(char const* const message);

        /**
         * @return The string message of the exception.
         */
        virtual char const* what() const noexcept;
    };

    /**
     * The exception class used during development for a function that hasn't been implemented yet.
     */
    class NotImplementedException : public Exception {
    public:
        /**
         * Default constructor for a NotImplementedException.
         */
        NotImplementedException();
    };
}

#endif //ABRAHAM_EXCEPTION_H
