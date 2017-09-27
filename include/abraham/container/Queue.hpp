//
// Created by Matthew Remmel on 9/18/17.
//

#ifndef ABRAHAM_QUEUE_HPP
#define ABRAHAM_QUEUE_HPP

#include <queue>
#include <Exception.hpp>


namespace abraham {

    /**
     * A wrapper around std::queue that provides more convenient and higher level functions.
     * @tparam T - The type of the Queue.
     */
    template<typename T>
    class Queue {
    protected:
        /**
         * The internal std::queue object that this class wraps.
         */
        std::queue<T> _data;

    public:
        /**
         * Default constructor that creates and empty Queue.
         */
        Queue<T>();

        /**
         * Constructor that creates a Queue from a std::queue.
         * @param queue - The std::queue to create this Queue from.
         */
        Queue<T>(const std::queue<T>& queue);

        /**
         * Constructor that creates a Queue from another Queue object.
         * @param queue - The Queue object that this Queue is created from.
         */
        Queue<T>(const Queue<T>& queue);

        /**
         * Move constructor.
         * @param queue - The Queue to move to this Queue.
         */
        Queue<T>(Queue<T>&& queue) noexcept;

        /**
         * Operator overload to set new Queue contents using the '=' operator.
         * @param queue - The Queue object to set the new contents from.
         * @return A self reference.
         */
        Queue<T>& operator=(const Queue<T>& queue);

        /**
         * Operator overload to set new Queue contents by moving.
         * @param queue - The Queue object to set the new contents from.
         * @return A self reference.
         */
        Queue<T>& operator=(Queue<T>&& queue) noexcept;

        /**
         * Operator overload to check the equality of two Queue objects using the '==' operator.
         * @param queue - The Queue object to compare this Queue to.
         * @return true if the contents of the Queue objects are equal in value; false otherwise.
         */
        bool operator==(const Queue<T>& queue);

        /**
         * Operator overload to check the inequality of the two Queue objects using the '!=' operator.
         * @param queue - The Queue object to compare this Queue to.
         * @return true if the contents of the Queue objects are not equal in value; false otherwise.
         */
        bool operator!=(const Queue<T>& queue);

        /**
         * Pushes a new object onto the back of the Queue.
         * @param object - The object to push onto the Queue.
         * @return A self reference.
         */
        Queue<T>& push(const T& object);

        /**
         * Retrieve and remove the object at the top of the Queue.
         * @return The object at the front of the Queue.
         */
        T pop();

        /**
         * Retrieve the object at the front of the Queue without removing it.
         * @return The object at the front of the Queue.
         */
        T peakFront() const;

        /**
         * Retrieve the object at the back of the Queue without removing it.
         * @return The object at the back of the Queue.
         */
        T peakBack() const ;

        /**
         * @return true if the Queue is empty; false otherwise.
         */
        bool isEmpty() const;

        /**
         * @return The number of objects in the Queue.
         */
        size_t size() const;

        /**
         * @return A copy of the Queue.
         */
        Queue<T> copy() const;

        /**
         * @return The internal std::queue object.
         */
        std::queue<T> std_queue() const;
    };

    /*
     * Template implementation
     */

    template<typename T>
    Queue<T>::Queue() {
        this->_data = std::queue<T>();
    }

    template<typename T>
    Queue<T>::Queue(const Queue<T>& queue) {
        this->_data = queue._data;
    }

    template<typename T>
    Queue<T>::Queue(Queue<T>&& queue) noexcept {
        this->_data = queue._data;
    }

    template<typename T>
    Queue<T>::Queue(const std::queue<T>& queue) {
        this->_data = queue;
    }

    template<typename T>
    Queue<T>& Queue<T>::operator=(const Queue<T>& queue) {
        if (this == &queue) return *this;
        this->_data = queue._data;
        return *this;
    }

    template<typename T>
    Queue<T>& Queue<T>::operator=(Queue<T>&& queue) noexcept {
        if (this == &queue) return *this;
        this->_data = queue._data;
        return *this;
    }

    template<typename T>
    bool Queue<T>::operator==(const Queue<T>& queue) {
        return this->_data == queue._data;
    }

    template<typename T>
    bool Queue<T>::operator!=(const Queue<T>& queue) {
        return this->_data != queue._data;
    }

    template<typename T>
    Queue<T>& Queue<T>::push(const T& object) {
        this->_data.push(object);
        return *this;
    }

    template<typename T>
    T Queue<T>::pop() {
        if (this->_data.empty()) {
            throw OutOfBoundsException(0);
        }

        T object = this->_data.front();
        this->_data.pop();
        return object;
    }

    template<typename T>
    T Queue<T>::peakFront() const {
        if (this->_data.empty()) {
            throw OutOfBoundsException(0);
        }

        return this->_data.front();
    }

    template<typename T>
    T Queue<T>::peakBack() const {
        if (this->_data.empty()) {
            throw OutOfBoundsException(0);
        }

        return this->_data.back();
    }

    template<typename T>
    bool Queue<T>::isEmpty() const {
        return this->_data.empty();
    }

    template<typename T>
    size_t Queue<T>::size() const {
        return this->_data.size();
    }

    template<typename T>
    Queue<T> Queue<T>::copy() const {
        Queue<T> copy = Queue<T>();
        copy._data = this->_data;
        return copy;
    }

    template<typename T>
    std::queue<T> Queue<T>::std_queue() const {
        return this->_data;
    }
}

#endif //ABRAHAM_QUEUE_HPP
