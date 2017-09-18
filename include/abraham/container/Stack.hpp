//
// Created by Matthew Remmel on 9/17/17.
//

#ifndef ABRAHAM_STACK_HPP
#define ABRAHAM_STACK_HPP

#include <stack>
#include "Exception.hpp"


namespace abraham {

    /**
     * A wrapper around std::stack that provides more convenient and higher level functions.
     * @tparam T - The type of the Stack.
     */
    template<typename T>
    class Stack {
    protected:
        /**
         * The internal std::stack object that this class wraps.
         */
        std::stack<T> _data;

    public:
        /**
         * Default constructor that creates an empty Stack.
         */
        Stack<T>();

        /**
         * Pushes a new object onto the Stack.
         * @param object - The object to push onto the Stack.
         * @return A self reference.
         */
        Stack<T>& push(const T& object);

        /**
         * Retrieve and remove the object at the top of the Stack.
         * @return The object at the top of the Stack.
         */
        T pop();

        /**
         * Retrieve the object at the top of the Stack without removing it.
         * @return The object at the top of the Stack.
         */
        T peak() const;

        /**
         * @return true if the Stack is empty; false otherwise.
         */
        bool isEmpty() const;

        /**
         * @return The number of objects in the Stack.
         */
        size_t size() const;

        /**
         * @return A copy of the Stack.
         */
        Stack<T> copy() const;

        /**
         * @return The internal std::stack object.
         */
        std::stack<T> std_stack() const;
    };

    /*
     * Template implementation
     */

    template<typename T>
    Stack<T>::Stack() {
        this->_data = std::stack<T>();
    }

    template<typename T>
    Stack<T>& Stack<T>::push(const T& object) {
        this->_data.push(object);
        return *this;
    }

    template<typename T>
    T Stack<T>::pop() {
        if (this->_data.empty()) {
            throw OutOfBoundsException(0);
        }

        T object = this->_data.top();
        this->_data.pop();
        return object;
    }

    template<typename T>
    T Stack<T>::peak() const {
        if (this->_data.empty()) {
            throw OutOfBoundsException(0);
        }

        return this->_data.top();
    }

    template<typename T>
    bool Stack<T>::isEmpty() const {
        return this->_data.empty();
    }

    template<typename T>
    size_t Stack<T>::size() const {
        return this->_data.size();
    }

    template<typename T>
    Stack<T> Stack<T>::copy() const {
        Stack<T> copy = Stack<T>();
        copy._data = this->_data;
        return copy;
    }

    template<typename T>
    std::stack<T> Stack<T>::std_stack() const {
        return this->_data;
    }
}

#endif //ABRAHAM_STACK_HPP
