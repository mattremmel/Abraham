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

// NotImplementedException
NotImplementedException::NotImplementedException()
    : Exception("Function not implemented") { }