//
// Created by Matthew Remmel on 9/11/17.
//

#include "gtest/gtest.h"
#include "Dictionary.hpp"

using namespace abraham;


TEST(Dictionary, default_constructor) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    std::map<char, int> expect = std::map<char, int>();

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
    EXPECT_FALSE(dictionary.hasDefaultValue());
    EXPECT_EQ(int(), dictionary.getDefaultValue());
}

TEST(Dictionary, default_value_constructor) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);
    int default_value = dictionary['a'];
    int expect = 10;

    // Assertion
    EXPECT_EQ(expect, default_value);
    EXPECT_TRUE(dictionary.hasDefaultValue());
    EXPECT_EQ(10, dictionary.getDefaultValue());
}

TEST(Dictionary, initializer_list_constructor) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    std::map<char, int> expect =  {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
    EXPECT_FALSE(dictionary.hasDefaultValue());
    EXPECT_EQ(int(), dictionary.getDefaultValue());
}

TEST(Dictionary, map_constructor) {
    // Setup
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary = Dictionary<char, int>(expect);

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
    EXPECT_FALSE(dictionary.hasDefaultValue());
    EXPECT_EQ(int(), dictionary.getDefaultValue());
}

TEST(Dictionary, unordered_map_constructor) {
    // Setup
    std::unordered_map<char, int> umap = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary = Dictionary<char, int>(umap);
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
    EXPECT_FALSE(dictionary.hasDefaultValue());
    EXPECT_EQ(int(), dictionary.getDefaultValue());
}

TEST(Dictionary, dictionary_constructr) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = Dictionary<char, int>(dictionary1);
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary2.std_map());
    EXPECT_FALSE(dictionary2.hasDefaultValue());
    EXPECT_EQ(int(), dictionary2.getDefaultValue());
}

// Operator[]

TEST(Dictionary, operator_access_get_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    int n = dictionary['a'];
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(1, n);
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_get_invalid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    int n = dictionary['c'];
    std::map<char, int> expect = {{'a', 1}, {'b', 2}, {'c', int()}};

    // Assertion
    EXPECT_EQ(int(), n);
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_set_new) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    dictionary['c'] = 3;
    std::map<char, int> expect = {{'a', 1}, {'b', 2}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_set_overwrite) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}, {'c', 4}};
    dictionary['c'] = 3;
    std::map<char, int> expect {{'a', 1}, {'b', 2}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_get_valid_with_default) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);
    dictionary['a'] = 5;
    int n = dictionary['a'];

    // Assertion
    EXPECT_EQ(5, n);
}

TEST(Dictionary, operator_access_get_invalid_with_default) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);
    dictionary['a'] = 1; dictionary['b'] = 2;
    int n = dictionary['c'];
    std::map<char, int> expect = {{'a', 1}, {'b', 2}, {'c', 10}};

    // Assertion
    EXPECT_EQ(10, n);
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_set_new_with_default) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);
    dictionary['a'] = 1; dictionary['b'] = 2; dictionary['c'] = 3;
    std::map<char, int> expect = {{'a', 1}, {'b', 2}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, operator_access_set_overwrite_with_default) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);
    dictionary['a'] = 1; dictionary['b'] = 2; dictionary['c'] = 4;
    dictionary['c'] = 3;
    std::map<char, int> expect {{'a', 1}, {'b', 2}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

// Operator=

TEST(Dictionary, operator_assign) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = dictionary1;
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary2.std_map());
}

TEST(Dictionary, operator_assign_chaining) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'b', 2}};
    Dictionary<char, int> dictionary3 = dictionary2 = dictionary1 = {{'c', 3}};
    std::map<char, int> expect = {{'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary1.std_map());
    EXPECT_EQ(expect, dictionary2.std_map());
    EXPECT_EQ(expect, dictionary3.std_map());
}

TEST(Dictionary, operator_self_assignment) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    dictionary = dictionary;
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

// Operator+

TEST(Dictionary, operator_plus_dictionary) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'b', 2}};
    Dictionary<char, int> dictionary3 = dictionary1 + dictionary2;
    std::map<char, int> expect1 = {{'a', 1}};
    std::map<char, int> expect2 = {{'b', 2}};
    std::map<char, int> expect3 = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect1, dictionary1.std_map());
    EXPECT_EQ(expect2, dictionary2.std_map());
    EXPECT_EQ(expect3, dictionary3.std_map());
}

TEST(Dictionary, operator_plus_self_assign) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'b', 2}};
    dictionary1 = dictionary1 + dictionary2;
    std::map<char, int> expect1 = {{'a', 1}, {'b', 2}};
    std::map<char, int> expect2 = {{'b', 2}};

    // Assertion
    EXPECT_EQ(expect1, dictionary1.std_map());
    EXPECT_EQ(expect2, dictionary2.std_map());

}

// Operator+=

TEST(Dictionary, operator_plus_equal_dictionary) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'b', 2}};
    dictionary1 += dictionary2;
    std::map<char, int> expect1 = {{'a', 1}, {'b', 2}};
    std::map<char, int> expect2 = {{'b', 2}};

    // Assertion
    EXPECT_EQ(expect1, dictionary1.std_map());
    EXPECT_EQ(expect2, dictionary2.std_map());
}

// Operator==

TEST(Dictionary, operator_equality) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'a', 1}};
    Dictionary<char, int> dictionary3 = {{'b', 2}};

    // Assertion
    EXPECT_TRUE(dictionary1 == dictionary2);
    EXPECT_FALSE(dictionary1 == dictionary3);
}

TEST(Dictionary, operator_equality_self) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}};

    // Assertion
    EXPECT_TRUE(dictionary == dictionary);
}

// Operator!=

TEST(Dictionary, operator_inequality) {
    Dictionary<char, int> dictionary1 = {{'a', 1}};
    Dictionary<char, int> dictionary2 = {{'a', 1}};
    Dictionary<char, int> dictionary3 = {{'b', 2}};

    // Setup
    EXPECT_FALSE(dictionary1 != dictionary2);
    EXPECT_TRUE(dictionary1 != dictionary3);
}

TEST(Dictionary, operator_inequality_self) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}};

    // Assertion
    EXPECT_FALSE(dictionary != dictionary);
}

// ObjectForKey

TEST(Dictionary, object_for_key_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    int n = dictionary.objectForKey('b');

    // Assertion
    EXPECT_EQ(n, 2);
}

TEST(Dictionary, object_for_key_invalid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_THROW(dictionary.objectForKey('c'), InvalidArgumentException);
}

// ContainsKey

TEST(Dictionary, contains_key_true) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_TRUE(dictionary.containsKey('b'));
}

TEST(Dictionary, contains_key_false) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_FALSE(dictionary.containsKey('c'));
}

// Size

TEST(Dictionary, size_empty) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();

    // Assertion
    EXPECT_EQ(0, dictionary.size());
}

TEST(Dictionary, size) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(2, dictionary.size());
}

// IsEmpty

TEST(Dictionary, is_empty_true) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();

    // Assertion
    EXPECT_TRUE(dictionary.isEmpty());
}

TEST(Dictionary, is_empty_false) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_FALSE(dictionary.isEmpty());
}

// HasDefaultValue

TEST(Dictionary, has_default_value_false) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();

    // Assertion
    EXPECT_FALSE(dictionary.hasDefaultValue());
}

TEST(Dictionary, has_default_value_true) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);

    // Assertion
    EXPECT_TRUE(dictionary.hasDefaultValue());
}

// GetDefaultValue

TEST(Dictionary, get_default_value_none) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();

    // Assertion
    EXPECT_EQ(int(), dictionary.getDefaultValue());
}

TEST(Dictionary, get_default_value) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>(10);

    // Assertion
    EXPECT_EQ(10, dictionary.getDefaultValue());
}

// SetDefaultValue

TEST(Dictionary, set_default_value) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    dictionary.setDefaultValue(10);

    // Assertion
    EXPECT_EQ(10, dictionary.getDefaultValue());
    EXPECT_TRUE(dictionary.hasDefaultValue());
}

// GetKeys

TEST(Dictionary, get_keys_empty) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    Array<char> keys = dictionary.getKeys();
    Array<char> expect = Array<char>();

    // Assertion
    EXPECT_EQ(expect, keys);
}

TEST(Dictionary, get_keys) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    Array<char> keys = dictionary.getKeys();
    Array<char> expect = {'a', 'b'};

    // Assertion
    EXPECT_EQ(expect, keys);
}

// GetValues

TEST(Dictionary, get_values_empty) {
    // Setup
    Dictionary<char, int> dictionary = Dictionary<char, int>();
    Array<int> values = dictionary.getValues();
    Array<int> expect = Array<int>();

    // Assertion
    EXPECT_EQ(expect, values);
}

TEST(Dictionary, get_values) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    Array<int> values = dictionary.getValues();
    Array<int> expect = {1, 2};

    // Assertion
    EXPECT_EQ(expect, values);
}

// AddingObject

TEST(Dictionary, add_object) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}};
    dictionary.addObject('b', 2);
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, add_object_invalid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_THROW(dictionary.addObject('b', 3), InvalidArgumentException);
}

// Remove

TEST(Dictionary, remove_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    dictionary.remove('b');
    std::map<char, int> expect = {{'a', 1}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, remove_no_key) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    dictionary.remove('c');
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

// RemoveObjects

TEST(Dictionary, remove_objects_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}, {'c', 3}};
    Array<char> removables = {'b', 'c'};
    dictionary.removeObjects(removables);
    std::map<char, int> expect = {{'a', 1}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, remove_objects_no_keys) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}, {'c', 3}};
    Array<char> removables = {'d', 'e'};
    dictionary.removeObjects(removables);
    std::map<char, int> expect = {{'a', 1}, {'b', 2}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

// RemoveAll

TEST(Dictionary, remove_all) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}, {'c', 3}};
    dictionary.removeAll();
    std::map<char, int> expect = std::map<char, int>();

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

// ReplaceObjects

TEST(Dictionary, replace_object_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}, {'c', 3}};
    dictionary.replace('b', 4);
    std::map<char, int> expect = {{'a', 1}, {'b', 4}, {'c', 3}};

    // Assertion
    EXPECT_EQ(expect, dictionary.std_map());
}

TEST(Dictionary, replace_object_invalid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_THROW(dictionary.replace('c', 3), InvalidArgumentException);
}

// Swap

TEST(Dictionary, swap_objects_valid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    dictionary.swap('a', 'b');
    std::map<char, int> expect = {{'a', 2}, {'b', 1}};
}

TEST(Dictionary, swap_objects_invalid) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_THROW(dictionary.swap('a', 'c'), InvalidArgumentException);
    EXPECT_THROW(dictionary.swap('c', 'a'), InvalidArgumentException);
    EXPECT_THROW(dictionary.swap('c', 'd'), InvalidArgumentException);
}

// IsEqualTo

TEST(Dictionary, is_equal_to_true) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_TRUE(dictionary1.isEqualTo(dictionary2));
}

TEST(Dictionary, is_equal_to_false_same_keys) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = {{'a', 1}, {'b', 3}};

    // Assertion
    EXPECT_FALSE(dictionary1.isEqualTo(dictionary2));
}

TEST(Dictionary, is_equal_to_false_same_values) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = {{'b', 1}, {'c', 2}};

    // Assertion
    EXPECT_FALSE(dictionary1.isEqualTo(dictionary2));
}

// Copy

TEST(Dictionary, dictionary_copy) {
    // Setup
    Dictionary<char, int> dictionary1 = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> dictionary2 = dictionary1.copy();

    // Assertion
    EXPECT_EQ(dictionary1.std_map(), dictionary2.std_map());
}

TEST(Dictionary, dictionary_copy_chained) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    Dictionary<char, int> copy = dictionary.copy().addObject('c', 3);
    std::map<char, int> expect1 = {{'a', 1}, {'b', 2}, {'c', 3}};
    std::map<char, int> expect2 = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect1, copy.std_map());
    EXPECT_EQ(expect2, dictionary.std_map());
}

// Std_Map

TEST(Dictionary, std_map) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    std::map<char, int> map = dictionary.std_map();
    std::map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, map);
}

// Std_Unordered_Map

TEST(Dictionary, std_unordered_map) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    std::unordered_map<char, int> hashmap = dictionary.std_unordered_map();
    std::unordered_map<char, int> expect = {{'a', 1}, {'b', 2}};

    // Assertion
    EXPECT_EQ(expect, hashmap);
}

// Iterator

TEST(Dictionary, range_loop) {
    // Setup
    Dictionary<char, int> dictionary = {{'a', 1}, {'b', 2}};
    int sum = 0;
    for (auto entry : dictionary) {
        sum += entry.second;
    }

    // Assertion
    EXPECT_EQ(3, sum);
}
