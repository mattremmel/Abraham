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
         * Constructor that creates a Stack from a std::stack.
         * @param std_stack - The std::stack to create this Stack from.
         */
        Stack<T>(const std::stack<T>& std_stack);

        /**
         * Constructor that creates a Stack from another Stack object.
         * @param stack - The Stack object that this Stack is created from.
         */
        Stack<T>(const Stack<T>& stack);

        /**
         * Move constructor.
         * @param stack - The Stack to move to this Stack.
         */
        Stack<T>(const Stack<T>&& stack);

        /**
         * Operator overload to set new Stack contents using the '=' operator.
         * @param stack - The Stack object to set the new contents from.
         * @return A self reference.
         */
        Stack<T>& operator=(const Stack<T>& stack);

        /**
         * Operator overload to set new Stack contents by moving.
         * @param stack - The Stack object to set the new contents from.
         * @return A self reference.
         */
        Stack<T>& operator=(const Stack<T>&& stack);

        /**
         * Operator overload to check the equality of two Stack objects using the '==' operator.
         * @param stack - The Stack object to compare this Stack to.
         * @return true if the contents of the Stack objects are equal in value; false otherwise.
         */
        bool operator==(const Stack<T>& stack);

        /**
         * Operator overload to check the inequality of two Stack objects using the '!=' operator.
         * @param stack - The Stack object to compare this Stack to.
         * @return true if the contents of the Stack objects are not equal in value; false otherwise.
         */
        bool operator!=(const Stack<T>& stack);

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
    Stack<T>::Stack(const Stack<T>& stack) {
        this->_data = stack._data;
    }

    template<typename T>
    Stack<T>::Stack(const Stack<T>&& stack) {
        this->_data = stack._data;
    }

    template<typename T>
    Stack<T>::Stack(const std::stack<T>& std_stack) {
        this->_data = std_stack;
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& stack) {
        this->_data = stack._data;
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>&& stack) {
        this->_data = stack._data;
    }

    template<typename T>
    bool Stack<T>::operator==(const Stack<T>& stack) {
        this->_data == stack._data;
    }

    template<typename T>
    bool Stack<T>::operator!=(const Stack<T>& stack) {
        this->_data = stack._data;
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
