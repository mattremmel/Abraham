//
// Created by Matthew Remmel on 9/5/17.
//

#ifndef ABRAHAM_ARRAY_HPP
#define ABRAHAM_ARRAY_HPP

#include <vector>
#include <string>
#include <sstream>
#include "Exception.hpp"


namespace abraham {

    /**
     * A wrapper around std::vector that provides more convenient and higher level functions.
     * @tparam T - The type of the Array.
     */
    template<typename T>
    class Array {
    protected:
        /**
         * The internal std::vector object that this class wraps.
         */
        std::vector<T> _data;

    public:
        /**
         * Default constructor that creates an empty Array.
         */
        Array<T>();

        /**
         * Constructor that creates an Array of pre-allocated size.
         * @param size - The size in terms of number of elements of the pre-allocated Array.
         */
        Array<T>(size_t size);

        /**
         * Constructor that creates an Array from an initialization list.
         * @param i_list - List of objects to initialize the Array with.
         */
        Array<T>(std::initializer_list<T> i_list);

        /**
         * Constructor that creates an Array from a std::vector.
         * @param vector - An std::vector to create the Array from.
         */
        Array<T>(const std::vector<T>& vector);

        /**
         * Constructor that creates an Array from another Array object.
         * @param array - The Array object that this Array is created from.
         */
        Array<T>(const Array<T>& array);

        /**
         * Move constructor.
         * @param array - The Array to move to this Array.
         */
        Array<T>(Array<T>&& array) noexcept;

        /**
         * Operator overload to access Array elements using the '[ ]' operator.
         * @param index - The 0-based index of the element in the Array.
         * @return A reference to the element at the provided index.
         */
        T& operator[](size_t index);

        /**
         * Operator overload to set new Array contents using the '=' operator.
         * @param array - The Array object to set the new contents from.
         * @return A self reference.
         */
        Array<T>& operator=(const Array<T>& array);

        /**
         * Operator overload to allow setting new contents by moving.
         * @param array - The Array object to set the new contents from.
         * @return A self reference.
         */
        Array<T>& operator=(Array<T>&& array) noexcept;

        /**
         * Operator overload to concatenate two Array objects using the '+' operator.
         * @param array - The Array object to concatenate with this Array.
         * @return A new Array containing the contents of both Array objects.
         */
        const Array<T> operator+(const Array<T>& array) const;

        /**
         * Operator overload to concatenate another Array with this one using the '+=' operator.
         * @param array - The Array object to concatenate with this Array.
         * @return A self reference.
         */
        Array<T>& operator+=(const Array<T>& array);

        /**
         * Operator overload to check the content equality of two Array objects using the '==' operator.
         * @param array - The Array object to compare this Array to.
         * @return true if the contents of the Array objects are equal in value; false otherwise.
         */
        bool operator==(const Array<T>& array) const;

        /**
         * Operator overload to check the content inequality of two Array objects using the '!=' operator.
         * @param array - The Array object to compare this Array to.
         * @return true if the contents of the Array objects are not equal in value; false otherwise.
         */
        bool operator!=(const Array<T>& array) const;

        /**
         * Retrieves the element at the specified index.
         * @param index - The index of the element.
         * @return The element at the specified index.
         */
        T objectAtIndex(size_t index) const;

        /**
         * @return The element at the beginning of the Array.
         */
        T firstObject() const;

        /**
         * @return The element at the end of the Array.
         */
        T lastObject() const;

        /**
         * Determines whether an object is present in the Array.
         * @param object - The object to be found.
         * @return true if the object is present in the Array; false otherwise.
         */
        bool contains(const T& object) const;

        /**
         * Determines whether an Array of objects is present in the Array.
         * @param objects - The Array of objects to be found.
         * @return true if all the objects are present in the Array; false otherwise.
         */
        bool containsAll(const Array<T>& objects) const;

        /**
         * @return The number of elements contained in the Array.
         */
        size_t size() const;

        /**
         * @return true if there are no elements in the Array; false otherwise.
         */
        bool isEmpty() const;

        /**
         * Appends an object to the end of the Array.
         * @param object - The object to add to the Array.
         * @return A self reference.
         */
        Array<T>& add(const T& object);

        /**
         * Appends an Array of objects to the end of the Array.
         * @param objects - The Array of objects to add to the Array.
         * @return A self reference.
         */
        Array<T>& addAll(const Array<T>& objects);

        /**
         * Inserts an object at a specific index in the Array.
         * @param object - The object to add to the Array.
         * @param index - The index to insert the object at.
         * @return A self reference.
         */
        Array<T>& insert(const T& object, size_t index);

        /**
         * Removes the first occurrence of an object from the Array.
         * @param object - The object to remove from the Array.
         * @return A self reference.
         */
        Array<T>& remove(const T& object);

        /**
         * Removes the object at the specified index from the Array.
         * @param index - The index of the object to remove.
         * @return A self reference.
         */
        Array<T>& removeIndex(size_t index);

        /**
         * Removes a range of objects between the specified indexes, from the Array.
         * @param from_index - The starting index of the range.
         * @param to_index - The ending index of the range.
         * @return A self reference.
         */
        Array<T>& removeRange(size_t from_index, size_t to_index);

        /**
         * Removes all occurrences of the object from the Array.
         * @param object - The object to remove from the Array.
         * @return A self reference.
         */
        Array<T>& removeAll(const T& object);

        /**
         * Removes all occurrences of each object from the Array.
         * @param objects - The Array of objects to remove from the Array.
         * @return A self reference.
         */
        Array<T>& removeAll(const Array<T>& objects);

        /**
         * Removes all elements from the Array.
         * @return A self reference.
         */
        Array<T>& removeAll();

        /**
         * Removes all elements except for the objects specified.
         * @param objects - The elements that shouldn't be removed.
         * @return A self reference.
         */
        Array<T>& retainAll(const Array<T>& objects);

        /**
         * Replace the first occurrence of an element in the Array with another object.
         * @param old_object - The object to be replaced.
         * @param new_object - The new object to be inserted.
         * @return A self reference.
         */
        Array<T>& replace(const T& old_object, const T& new_object);

        /**
         * Replace the last occurrence of an element in the Array with another object.
         * @param old_object - The object to be replaced.
         * @param new_object - The new object to be inserted.
         * @return A self reference.
         */
        Array<T>& replaceLast(const T& old_object, const T& new_object);

        /**
         * Replace the element at the specified index with another object.
         * @param index - The index of the element to be replaced.
         * @param new_object - The new object to be inserted.
         * @return A self reference.
         */
        Array<T>& replaceIndex(size_t index, const T& new_object);

        /**
         * Replace all occurrences of an object in the Array with another object.
         * @param old_object - The object to be replaced.
         * @param new_object - The new object to be inserted.
         * @return A self reference.
         */
        Array<T>& replaceAll(const T& old_object, const T& new_object);

        /**
         * Swap the positions of two elements in the Array.
         * @param first_index - The index of the first element.
         * @param second_index - The index of the second element.
         * @return A self reference.
         */
        Array<T>& swap(size_t first_index, size_t second_index);

        /**
         * Retrieve a subsection of the Array.
         * @param from_index - The starting index of the desired subsection.
         * @param to_index - The ending index of the desired subsection.
         * @return A new Array with the elements of the specified subsection.
         */
        Array<T> subarray(size_t from_index, size_t to_index) const;

        /**
         * Retrieve a subsection of the Array from the specified index to the end.
         * @param index - The starting index of the desired subsection.
         * @return A new Array with the elements of the specified subsection.
         */
        Array<T> subarrayFromIndex(size_t index) const;

        /**
         * Retrieve a subsection of the Array from the beginning to the specified index.
         * @param index The ending index of the desired subsection.
         * @return A new Array with the elements of the specified subsection.
         */
        Array<T> subarrayToIndex(size_t index) const;

        /**
         * Returns the index of the first occurrence of the provided object.
         * @param object - The object to be found.
         * @return The index of the object. -1 if not found.
         */
        size_t indexOf(const T& object) const;

        /**
         * Returns the index of the first occurrence of the provided object found after the specified index.
         * @param object - The object to be found.
         * @param min_index - The index to start search from.
         * @return The index of the object. -1 if not found.
         */
        size_t indexOf(const T& object, size_t min_index) const;

        /**
         * Returns the index of the last occurrence of the provided object.
         * @param object - The object to be found.
         * @return The index of the object. -1 if not found.
         */
        size_t indexOfLast(const T& object) const;

        /**
         * Returns the index of the last occurrence of the provided object found before the specified index.
         * @param object - The object to be found.
         * @param max_index - The index where the search should stop.
         * @return The index of the object. -1 if not found.
         */
        size_t indexOfLast(const T& object, size_t max_index) const;

        /**
         * Returns the index of the first occurrence of the provided object in the specified range.
         * @param object - The object to be found.
         * @param from_index - The starting index of the range.
         * @param to_index - The ending index of the range.
         * @return The index of the object. -1 if not found.
         */
        size_t indexOfObjectInRange(const T& object, size_t from_index, size_t to_index) const;

        /**
         * Sorts the elements in the Array.
         * @return A self reference.
         */
        Array<T>& sort();

        /**
         * Reverses the order of the elements in the Array.
         * @return A self reference.
         */
        Array<T>& reverse();

        /**
         * Checks the equality of two Array objects.
         * @param array - The other Array to compare this Array to.
         * @return true if the elements in the two Array objects are equal; false otherwise.
         */
        bool isEqualTo(const Array<T>& array) const;

        /**
         * @return A copy of the Array.
         */
        Array<T> copy() const;

        /**
         * @return The internal std::vector object.
         */
        std::vector<T> std_vector() const;

        /**
         * @return std::vector iterator.
         */
        typename std::vector<T>::iterator begin();

        /**
         * @return std::vector iterator.
         */
        typename std::vector<T>::iterator end();

        /**
         * @return std::vector const iterator.
         */
        typename std::vector<T>::const_iterator begin() const;

        /**
         * @return std::vector const iterator.
         */
        typename std::vector<T>::const_iterator end() const;

        /**
         * @return std::vector const iterator.
         */
        typename std::vector<T>::const_iterator cbegin() const;

        /**
         * @return std::vector const iterator.
         */
        typename std::vector<T>::const_iterator cend() const;

        /**
         * Value representing a non-existent index.
         */
        static const size_t NO_INDEX;
    };

    /*
     * Template implementation
     */

    template<typename T>
    Array<T>::Array() {
        this->_data = std::vector<T>();
    }

    template<typename T>
    Array<T>::Array(size_t size) {
        this->_data = std::vector<T>(size);
    }

    template<typename T>
    Array<T>::Array(std::initializer_list<T> i_list) {
        this->_data = std::vector<T>(i_list);
    }

    template<typename T>
    Array<T>::Array(const std::vector<T>& vector) {
        this->_data = vector;
    }

    template<typename T>
    Array<T>::Array(const Array<T>& array) {
        this->_data = array._data;
    }

    template<typename T>
    Array<T>::Array(Array<T>&& array) noexcept {
        this->_data = array._data;
    }

    template<typename T>
    T& Array<T>::operator[](size_t index) {
        if (index < this->_data.size()) {
            return this->_data[index];
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::operator=(const Array<T>& array) {
        this->_data = array._data;
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::operator=(Array<T>&& array) noexcept {
        if (this == &array) return *this;
        this->_data = array._data;
        return *this;
    }

    template<typename T>
    const Array<T> Array<T>::operator+(const Array<T>& array) const {
        Array<T> buffer = Array();
        buffer._data.insert(buffer._data.begin(), this->_data.begin(), this->_data.end());
        buffer._data.insert(buffer._data.end(), array._data.begin(), array._data.end());
        return buffer;
    }

    template<typename T>
    Array<T>& Array<T>::operator+=(const Array<T>& array) {
        if (this == &array) return *this;
        this->_data.insert(this->_data.end(), array._data.begin(), array._data.end());
        return *this;
    }

    template<typename T>
    bool Array<T>::operator==(const Array<T>& array) const {
        return this->_data == array._data;
    }

    template<typename T>
    bool Array<T>::operator!=(const Array<T>& array) const {
        return this->_data != array._data;
    }

    template<typename T>
    T Array<T>::objectAtIndex(size_t index) const {
        if (index < this->_data.size()) {
            return this->_data[index];
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    T Array<T>::firstObject() const {
        if (this->_data.size() > 0) {
            return this->_data[0];
        } else {
            throw OutOfBoundsException(0);
        }
    }

    template<typename T>
    T Array<T>::lastObject() const {
        if (this->_data.size() > 0) {
            return this->_data[this->_data.size() - 1];
        } else {
            throw OutOfBoundsException(0);
        }
    }

    template<typename T>
    bool Array<T>::contains(const T& object) const {
        return this->indexOf(object) != NO_INDEX;
    }

    template<typename T>
    bool Array<T>::containsAll(const Array<T>& objects) const {
        for (const T& object : objects._data) {
            if (this->indexOf(object) == NO_INDEX) return false;
        }

        return true;
    }

    template<typename T>
    size_t Array<T>::size() const {
        return this->_data.size();
    }

    template<typename T>
    bool Array<T>::isEmpty() const {
        return this->_data.empty();
    }

    template<typename T>
    Array<T>& Array<T>::add(const T& object) {
        this->_data.push_back(object);
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::addAll(const Array<T>& objects) {
        for (const T& object : objects._data) {
            this->_data.push_back(object);
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::insert(const T& object, size_t index) {
        if (index < this->_data.size()) {
            this->_data.insert(this->_data.begin() + index, object);
            return *this;
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::remove(const T& object) {
        size_t index = this->indexOf(object);

        if (index != NO_INDEX) {
            this->_data.erase(this->_data.begin() + index);
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::removeIndex(size_t index) {
        if (index < this->_data.size()) {
            this->_data.erase(this->_data.begin() + index);
            return *this;
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::removeRange(size_t from_index, size_t to_index) {
        if (from_index > to_index) {
            throw InvalidArgumentException("from_index must be less than to_index");
        }

        if (from_index < this->_data.size() && to_index < this->_data.size()) {
            this->_data.erase(this->_data.begin() + from_index, this->_data.begin() + to_index);
            return *this;
        } else {
            throw OutOfBoundsException(to_index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::removeAll(const T& object) {
        this->_data.erase(std::remove(this->_data.begin(), this->_data.end(), object), this->_data.end());
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::removeAll(const Array<T>& objects) {
        for (const T& object : objects._data) {
            this->removeAll(object);
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::removeAll() {
        this->_data.clear();
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::retainAll(const Array<T>& objects) {
        std::vector<T> new_array = std::vector<T>();

        for (const T& object : this->_data) {
            if (objects.contains(object)) {
                new_array.push_back(object);
            }
        }

        this->_data = new_array;
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::replace(const T& old_object, const T& new_object) {
        size_t index = this->indexOf(old_object);
        if (index != NO_INDEX) {
            this->_data[index] = new_object;
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::replaceLast(const T& old_object, const T& new_object) {
        size_t index = this->indexOfLast(old_object);
        if (index != NO_INDEX) {
            this->_data[index] = new_object;
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::replaceIndex(size_t index, const T& new_object) {
        if (index < this->_data.size()) {
            this->_data[index] = new_object;
            return *this;
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::replaceAll(const T& old_object, const T& new_object) {
        for (size_t i = 0; i < this->_data.size(); ++i) {
            if (this->_data[i] == old_object) {
                this->_data[i] = new_object;
            }
        }

        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::swap(size_t first_index, size_t second_index) {
        if (first_index < this->_data.size() && second_index < this->_data.size()) {
            T temp = this->_data[first_index];
            this->_data[first_index] = this->_data[second_index];
            this->_data[second_index] = temp;
            return *this;
        } else {
            throw OutOfBoundsException(std::max(first_index, second_index));
        }
    }

    template<typename T>
    Array<T> Array<T>::subarray(size_t from_index, size_t to_index) const {
        if (from_index > to_index) {
            throw InvalidArgumentException("from_index must be less than to_index");
        }

        if (from_index < this->_data.size() && to_index < this->_data.size()) {
            Array<T> subarray = Array<T>();
            std::copy(this->_data.begin() + from_index, this->_data.begin() + to_index + 1,
                      std::back_inserter(subarray._data));
            return subarray;
        } else {
            throw OutOfBoundsException(to_index);
        }
    }

    template<typename T>
    Array<T> Array<T>::subarrayFromIndex(size_t index) const {
        if (index < this->_data.size()) {
            Array<T> subarray = Array<T>();
            std::copy(this->_data.begin() + index, this->_data.end(), std::back_inserter(subarray._data));
            return subarray;
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    Array<T> Array<T>::subarrayToIndex(size_t index) const {
        if (index < this->_data.size()) {
            Array<T> subarray = Array<T>();
            std::copy(this->_data.begin(), this->_data.begin() + index, std::back_inserter(subarray._data));
            return subarray;
        } else {
            throw OutOfBoundsException(index);
        }
    }

    template<typename T>
    size_t Array<T>::indexOf(const T& object) const {
        for (size_t i = 0; i < this->_data.size(); ++i) {
            if (this->_data[i] == object) {
                return i;
            }
        }

        return NO_INDEX;
    }

    template<typename T>
    size_t Array<T>::indexOf(const T& object, size_t min_index) const {
        if (min_index < this->_data.size()) {
            for (size_t i = min_index; i < this->_data.size(); ++i) {
                if (this->_data[i] == object) {
                    return i;
                }
            }

            return NO_INDEX;
        } else {
            throw OutOfBoundsException(min_index);
        }
    }

    template<typename T>
    size_t Array<T>::indexOfLast(const T& object) const {
        return this->indexOfLast(object, this->_data.size() - 1);
    }

    template<typename T>
    size_t Array<T>::indexOfLast(const T& object, size_t max_index) const {
        if (max_index < this->_data.size()) {
            for (size_t i = max_index; i < this->_data.size(); --i) {
                if (this->_data[i] == object) {
                    return i;
                }
            }

            return NO_INDEX;
        } else {
            throw OutOfBoundsException(max_index);
        }
    }

    template<typename T>
    size_t Array<T>::indexOfObjectInRange(const T& object, size_t from_index, size_t to_index) const {
        if (from_index > to_index) {
            throw InvalidArgumentException("from_index must be less than to_index");
        }

        if (from_index < this->_data.size() && to_index < this->_data.size()) {
            for (size_t i = from_index; i < to_index; ++i) {
                if (object == this->_data[i]) {
                    return i;
                }
            }

            return NO_INDEX;
        } else {
            throw OutOfBoundsException(to_index);
        }
    }

    template<typename T>
    Array<T>& Array<T>::sort() {
        std::sort(this->_data.begin(), this->_data.end());
        return *this;
    }

    template<typename T>
    Array<T>& Array<T>::reverse() {
        std::reverse(this->_data.begin(), this->_data.end());
        return *this;
    }

    template<typename T>
    bool Array<T>::isEqualTo(const Array<T>& array) const {
        size_t size = this->_data.size();
        if (size != array._data.size()) return false;

        for (size_t i = 0; i < size; ++i) {
            if (this->_data[i] != array._data[i]) return false;
        }

        return true;
    }

    template<typename T>
    Array<T> Array<T>::copy() const {
        return Array<T>(this->_data);
    }

    template<typename T>
    std::vector<T> Array<T>::std_vector() const {
        return this->_data;
    }

    template<typename T>
    typename std::vector<T>::iterator Array<T>::begin() {
        return this->_data.begin();
    }

    template<typename T>
    typename std::vector<T>::iterator Array<T>::end() {
        return this->_data.end();
    }

    template<typename T>
    typename std::vector<T>::const_iterator Array<T>::begin() const {
        return this->_data.begin();
    }

    template<typename T>
    typename std::vector<T>::const_iterator Array<T>::end() const {
        return this->_data.end();
    }

    template<typename T>
    typename std::vector<T>::const_iterator Array<T>::cbegin() const {
        return this->_data.cbegin();
    }

    template<typename T>
    typename std::vector<T>::const_iterator Array<T>::cend() const {
        return this->_data.cend();
    }

    template<typename T>
    const size_t Array<T>::NO_INDEX = -1;
}

#endif //ABRAHAM_ARRAY_HPP
