//
// Created by Matthew Remmel on 8/31/17.
//

#ifndef ABRAHAM_EXCEPTION_HPP
#define ABRAHAM_EXCEPTION_HPP

#include <stdexcept>
#include <string>


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
     * The Exception class used for indicating an invalid index access.
     */
    class OutOfBoundsException : public Exception {
    public:
        /**
         * Default constructor for OutOfBoundsException.
         */
        OutOfBoundsException(size_t attempted);
    };

    /**
     * The Exception class used for indicating an invalid argument.
     */
    class InvalidArgumentException : public Exception {
    public:
        /**
         * Default constructor for InvalidArgumentException.
         */
        InvalidArgumentException();

        /**
         * Constructor that allows a helpful message to be set.
         */
        InvalidArgumentException(const std::string& message);
    };

    /**
     * The Exception class used for indicating an invalid value.
     */
    class InvalidValueException : public Exception {
    public:
        /**
         * Default constructor for InvalidValueException.
         */
        InvalidValueException();

        /**
         * Constructor that allows a helpful message to be set.
         */
        InvalidValueException(const std::string& message);
    };

    /**
     * The Exception class used during development for a function that hasn't been implemented yet.
     */
    class NotImplementedException : public Exception {
    public:
        /**
         * Default constructor for a NotImplementedException.
         */
        NotImplementedException();
    };
}

#endif //ABRAHAM_EXCEPTION_HPP
