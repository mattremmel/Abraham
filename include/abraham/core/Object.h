//
// Created by Matthew Remmel on 8/30/17.
//

#ifndef ABRAHAM_OBJECT_H
#define ABRAHAM_OBJECT_H

#include <string>

namespace abraham {

    /**
    * The base class that all Abraham classes inherit from.
    */
    class Object {
    public:
        /**
         * @return A human readable representation of the object
         */
        std::string toString();

        /**
         * @return A hash code representation of the object
         */
        size_t toHashCode();

        /**
         * Whether some object "is" this object.
         * @return true if this object is the same instance as the argument; false otherwise.
         */
        bool is(const Object& o);

        /**
         * Whether some object "is equivalently equal to" this object.
         * @return true if this object "is equivalently equal to" this object; false otherwise.
         */
        bool equals(const Object& o);

        // TODO: Compare

        // TODO: description

        // TODO: inspect
    };
}


#endif //ABRAHAM_OBJECT_H
