//
// Created by Matthew Remmel on 8/30/17.
//

#include "Object.hpp"
#include "Exception.hpp"

using namespace abraham;

std::string Object::toString() {
    throw NotImplementedException();
}

size_t Object::toHashCode() {
    throw NotImplementedException();
}

bool Object::is(const Object& o) {
    throw NotImplementedException();
}

bool Object::equals(const Object& o) {
    throw NotImplementedException();
}