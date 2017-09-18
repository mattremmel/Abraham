//
// Created by Matthew Remmel on 9/10/17.
//

#ifndef ABRAHAM_DICTIONARY_HPP
#define ABRAHAM_DICTIONARY_HPP

#include <map>
#include <unordered_map>
#include "Array.hpp"


namespace abraham {

    /**
     * A wrapper around std::map that provides more convenient and higher level functions.
     * @tparam K - They key type of the Dictionary.
     * @tparam V - The value type of the Dictionary.
     */
    template<typename K, typename V>
    class Dictionary {
    protected:
        /**
         * The internal std::map object that this class wraps.
         */
        std::map<K, V> _data;

        /**
         * Indicates whether a default value has been set.
         */
        bool _hasDefault;

        /**
         * The default value that has been set.
         */
        V _defaultValue;

    public:
        /**
         * Default constructor that creates an empty Dictionary.
         */
        Dictionary<K, V>();

        /**
         * Constructor that creates a Dictionary with a default value.
         * @param default_value - The value a key should default to.
         */
        Dictionary<K, V>(const V& default_value);

        /**
         * Constructor that creates a Dictionary from an initialization list.
         * @param i_list - List of objects to initialize the Dictionary with.
         */
        Dictionary<K, V>(std::initializer_list<std::pair<const K, V>> i_list);

        /**
         * Constructor that creates a Dictionary from a std::map.
         * @param map - A std::map to create the Dictionary from.
         */
        Dictionary<K, V>(const std::map<K, V>& map);

        /**
         * Constructor that creates a Dictionary from a std::unordered_map.
         * @param map - A std::unordered_map to create the Dictionary from.
         */
        Dictionary<K, V>(const std::unordered_map<K, V>& map);

        /**
         * Constructor that creates a Dictionary from another Dictionary object.
         * @param dictionary - The Dictionary object that this Dictionary is created from.
         */
        Dictionary<K, V>(const Dictionary<K, V>& dictionary);

        /**
         * Move constructor.
         * @param dictionary - The Dictionary to move to this Dictionary.
         */
        Dictionary<K, V>(const Dictionary<K, V>&& dictionary);

        /**
         * Operator overload to access Dictionary values using the '[ ]' operator.
         * @param key - The key whose value should be accessed.
         * @return - A reference to the element associated with the key.
         */
        V& operator[](const K& key);

        /**
         * Operator overload to set new Dictionary contents using the '=' operator.
         * @param dictionary - The Dictionary object to set the new contents from.
         * @return A self reference.
         */
        Dictionary<K, V>& operator=(const Dictionary<K, V>& dictionary);

        /**
         * Operator overload to set new Dictionary contents by moving.
         * @param dictionary - The Dictionary object to set the new contents from.
         * @return A self reference.
         */
        Dictionary<K, V>& operator=(const Dictionary<K, V>&& dictionary);

        /**
         * Operator overload to combine two Dictionary objects using the '+' operator.
         * @param dictionary - The Dictionary object to combine with this Array.
         * @return A new Dictionary containing the contents of both Dictionary objects.
         */
        const Dictionary<K, V> operator+(const Dictionary<K, V>& dictionary) const;

        /**
         * Operator overload to combine another Dictionary with this one using the '+=' operator.
         * @param dictionary - The Dictionary object to combine with this one.
         * @return A self reference.
         */
        Dictionary<K, V>& operator+=(const Dictionary<K, V>& dictionary);

        /**
         * Operator overload to check the equality of two Dictionary objects using the '==' operator.
         * @param dictionary - The Dictionary object to compare this Dictionary to.
         * @return true if the contents of the Dictionary objects are equal in value; false otherwise.
         */
        bool operator==(const Dictionary<K, V>& dictionary) const;

        /**
         * Operator overload to check the inequality of two Dictionary objects using the '!=' operator.
         * @param dictionary - The Dictionary object to compare this Dictionary to.
         * @return true if the contents of the Dictionary objects are not equal in value; false otherwise.
         */
        bool operator!=(const Dictionary<K, V>& dictionary) const;

        /**
         * Retrieves the element associated with the specified key.
         * @param key - The key associated with the desired element.
         * @return - The element associated with the specified key.
         */
        V objectForKey(const K& key);

        /**
         * Determines whether the specified key exists in the Dictionary.
         * @param key - The key to be found.
         * @return true if the key is present in the Dictionary; false otherwise.
         */
        bool containsKey(const K& key) const;

        /**
         * @return The number of key/value pairs in the Dictionary.
         */
        size_t size() const;

        /**
         * @return true if the Dictionary is empty; false otherwise.
         */
        bool isEmpty() const;

        /**
         * @return true if a default value has been set; false otherwise.
         */
        bool hasDefaultValue() const;

        /**
         * @return The default value that will be set for a value if one is not provided.
         */
        V getDefaultValue() const;

        /**
         * @param value - The default value that will be set for a value if one is not provided.
         * @return A self reference.
         */
        Dictionary<K, V>& setDefaultValue(const V& value);

        /**
         * @return An Array object containing all the keys of this Dictionary.
         */
        Array<K> getKeys() const;

        /**
         * @return An Array object containing all the values of this Dictionary.
         */
        Array<V> getValues() const;

        /**
         * Add a new key/value pair to the Dictionary.
         * @param key - The key of the key/value pair.
         * @param value - The value associated with the key.
         * @return A self reference.
         */
        Dictionary<K, V>& addObject(const K& key, const V& value);

        /**
         * Remove a key/value pair from the Dictionary.
         * @param key - The key to remove from the Dictionary, along with its associated value.
         * @return A self reference.
         */
        Dictionary<K, V>& remove(const K& key);

        /**
         * Remove an Array of key/value pairs from the Dictionary.
         * @param keys - The Array of keys to remove from the Dictionary.
         * @return A self reference.
         */
        Dictionary<K, V>& removeObjects(const Array<K>& keys);

        /**
         * Remove all key/value pairs from the Dictionary.
         * @return A self reference.
         */
        Dictionary<K, V>& removeAll();

        /**
         * Replace the value of a pre-existing key with a new value.
         * @param key - The keys whose value will be replaced.
         * @param new_value - The new value to be set.
         * @return A self reference.
         */
        Dictionary<K, V>& replace(const K& key, const V& new_value);

        /**
         * Swap the value of a key with another.
         * @param first_key - The first key whose value will be swapped with the second.
         * @param second_key - The second key whose value will be swapped with the first.
         * @return A self reference.
         */
        Dictionary<K, V>& swap(const K& first_key, const K& second_key);

        /**
         * Checks the equality of two Dictionary objects.
         * @param dictionary - The other Dictionary to compare this Dictionary to.
         * @return true if the contents of the Dictionary objects are equal in value; false otherwise.
         */
        bool isEqualTo(const Dictionary<K, V>& dictionary) const;

        /**
         * @return A copy of the Dictionary.
         */
        Dictionary<K, V> copy() const;

        /**
         * @return The internal std::map object.
         */
        std::map<K, V> std_map() const;

        /**
         * @return A std::unordered_map representation of the Dictionary.
         */
        std::unordered_map<K, V> std_unordered_map() const;

        /**
         * @return std::map iterator.
         */
        typename std::map<K, V>::iterator begin();

        /**
         * @return std::map iterator.
         */
        typename std::map<K, V>::iterator end();

        /**
         * @return std::map const iterator.
         */
        typename std::map<K, V>::const_iterator begin() const;

        /**
         * @return std::map const iterator.
         */
        typename std::map<K, V>::const_iterator end() const;

        /**
         * @return std::map const iterator.
         */
        typename std::map<K, V>::const_iterator cbegin() const;

        /**
         * @return std::map const iterator.
         */
        typename std::map<K, V>::const_iterator cend() const;
    };


/*
 * Template Implementation
 */

#include "Exception.hpp"

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary() {
        this->_data = std::map<K, V>();
        this->_hasDefault = false;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(const V& default_value) {
        this->_data = std::map<K, V>();
        this->_hasDefault = true;
        this->_defaultValue = default_value;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(const std::map<K, V>& map) {
        this->_data = map;
        this->_hasDefault = false;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(const std::unordered_map<K, V>& map) {
        for (auto it = map.begin(); it != map.end(); ++it) {
            this->_data[it->first] = it->second;
        }
        this->_hasDefault = false;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(const Dictionary<K, V>& dictionary) {
        this->_data = dictionary._data;
        this->_hasDefault = dictionary._hasDefault;
        this->_defaultValue = dictionary._defaultValue;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(const Dictionary<K, V>&& dictionary) {
        this->_data = dictionary._data;
        this->_hasDefault = dictionary._hasDefault;
        this->_defaultValue = dictionary._defaultValue;
    }

    template<typename K, typename V>
    Dictionary<K, V>::Dictionary(std::initializer_list<std::pair<const K, V>> i_list) {
        this->_data = i_list;
        this->_hasDefault = false;
    }

    template<typename K, typename V>
    V& Dictionary<K, V>::operator[](const K& key) {
        if (this->_hasDefault && !this->containsKey(key)) {
            this->_data[key] = this->_defaultValue;
            return this->_data[key];
        } else {
            return this->_data[key];
        }
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary<K, V>& dictionary) {
        if (this == &dictionary) return *this;

        this->_data = dictionary._data;
        return *this;
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary<K, V>&& dictionary) {
        if (this == &dictionary) return *this;

        this->_data = dictionary._data;
        return *this;
    }

    template<typename K, typename V>
    const Dictionary<K, V> Dictionary<K, V>::operator+(const Dictionary<K, V>& dictionary) const {
        Dictionary<K, V> buffer = this->_data;
        for (auto it : dictionary._data) {
            buffer[it.first] = it.second;
        }

        return buffer;
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::operator+=(const Dictionary<K, V>& dictionary) {
        for (auto it : dictionary._data) {
            this->_data[it.first] = it.second;
        }

        return *this;
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::operator==(const Dictionary<K, V>& dictionary) const {
        return this->_data == dictionary._data;
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::operator!=(const Dictionary<K, V>& dictionary) const {
        return this->_data != dictionary._data;
    }

    template<typename K, typename V>
    V Dictionary<K, V>::objectForKey(const K& key) {
        if (this->_data.count(key) == 1) {
            return this->_data[key];
        } else {
            throw InvalidArgumentException("Key does not exist");
        }
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::containsKey(const K& key) const {
        return this->_data.count(key) == 1;
    }

    template<typename K, typename V>
    size_t Dictionary<K, V>::size() const {
        return this->_data.size();
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::isEmpty() const {
        return this->_data.size() == 0;
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::hasDefaultValue() const {
        return this->_hasDefault;
    }

    template<typename K, typename V>
    V Dictionary<K, V>::getDefaultValue() const {
        if (this->_hasDefault) {
            return this->_defaultValue;
        } else {
            return V();
        }
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::setDefaultValue(const V& value) {
        this->_hasDefault = true;
        this->_defaultValue = value;
        return *this;
    }

    template<typename K, typename V>
    Array<K> Dictionary<K, V>::getKeys() const {
        Array<K> keys = Array<K>(this->_data.size());
        size_t index = 0;
        for (auto it = this->_data.begin(); it != this->_data.end(); ++it) {
            keys[index] = it->first;
            ++index;
        }

        return keys;
    }

    template<typename K, typename V>
    Array<V> Dictionary<K, V>::getValues() const {
        Array<V> values = Array<V>(this->_data.size());
        size_t index = 0;
        for (auto it = this->_data.begin(); it != this->_data.end(); ++it) {
            values[index] = it->second;
            ++index;
        }

        return values;
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::addObject(const K& key, const V& value) {
        if (this->_data.count(key) == 0) {
            this->_data[key] = value;
            return *this;
        } else {
            throw InvalidArgumentException("Key already exists");
        }
    }


    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::remove(const K& key) {
        this->_data.erase(key);
        return *this;
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::removeObjects(const Array<K>& keys) {
        for (const K& key : keys) {
            this->_data.erase(key);
        }

        return *this;
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::removeAll() {
        this->_data.clear();
        return *this;
    }


    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::replace(const K& key, const V& new_value) {
        if (this->_data.count(key) == 1) {
            this->_data[key] = new_value;
            return *this;
        } else {
            throw InvalidArgumentException("Cannot replace key that doesn't exist");
        }
    }

    template<typename K, typename V>
    Dictionary<K, V>& Dictionary<K, V>::swap(const K& first_key, const K& second_key) {
        if (this->_data.count(first_key) == 1 && this->_data.count(second_key) == 1) {
            V first = this->_data[first_key];
            this->_data[first_key] = this->_data[second_key];
            this->_data[second_key] = first;
            return *this;
        } else {
            throw InvalidArgumentException("Cannot swap key that doesn't exist");
        }
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::isEqualTo(const Dictionary<K, V>& dictionary) const {
        return this->_data == dictionary._data;
    }

    template<typename K, typename V>
    Dictionary<K, V> Dictionary<K, V>::copy() const {
        return Dictionary<K, V>(this->_data);
    }

    template<typename K, typename V>
    std::map<K, V> Dictionary<K, V>::std_map() const {
        return this->_data;
    }

    template<typename K, typename V>
    std::unordered_map<K, V> Dictionary<K, V>::std_unordered_map() const {
        std::unordered_map<K, V> hash_map = std::unordered_map<K, V>();
        for (auto it : this->_data) {
            hash_map[it.first] = it.second;
        }

        return hash_map;
    }

    template<typename K, typename V>
    typename std::map<K, V>::iterator Dictionary<K, V>::begin() {
        return this->_data.begin();
    }

    template<typename K, typename V>
    typename std::map<K, V>::iterator Dictionary<K, V>::end() {
        return this->_data.end();
    }

    template<typename K, typename V>
    typename std::map<K, V>::const_iterator Dictionary<K, V>::begin() const {
        return this->_data.begin();
    }

    template<typename K, typename V>
    typename std::map<K, V>::const_iterator Dictionary<K, V>::end() const {
        return this->_data.end();
    }

    template<typename K, typename V>
    typename std::map<K, V>::const_iterator Dictionary<K, V>::cbegin() const {
        return this->_data.cbegin();
    }

    template<typename K, typename V>
    typename std::map<K, V>::const_iterator Dictionary<K, V>::cend() const {
        return this->_data.cend();
    }
}

#endif //ABRAHAM_DICTIONARY_HPP
