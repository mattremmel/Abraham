//
// Created by Matthew Remmel on 8/31/17.
//

#include "Exception.h"

using namespace abraham;

// Exception
Exception::Exception(char const *const message)
    : std::runtime_error(message) { }

char const* Exception::what() const noexcept {
    return std::exception::what();
}

// OutOfBoundsException
OutOfBoundsException::OutOfBoundsException(size_t attempted)
    : Exception(std::string("Attempted access to index " + std::to_string(attempted) + " was out of bounds.").c_str()) { }

// InvalidArgumentException
InvalidArgumentException::InvalidArgumentException()
    : Exception("Invalid argument") { }

InvalidArgumentException::InvalidArgumentException(const std::string &message)
    : Exception(message.c_str()) { }

// InvalidValueException
InvalidValueException::InvalidValueException()
    : Exception("Invalid value") { }

InvalidValueException::InvalidValueException(const std::string &message)
    : Exception(message.c_str()) { }

// NotImplementedException
NotImplementedException::NotImplementedException()
    : Exception("Function not implemented") { }