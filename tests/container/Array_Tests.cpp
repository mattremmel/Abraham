//
// Created by Matthew Remmel on 9/5/17.
//

#include "gtest/gtest.h"
#include "Array.hpp"
#include "Exception.hpp"

using namespace abraham;


TEST(Array, default_constructor) {
    // Setup
    Array<int> array = Array<int>();
    std::vector<int> expect = std::vector<int>();

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, size_constructor) {
    // Setup
    Array<int> array = Array<int>(5);
    std::vector<int> expect = std::vector<int>(5);

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, size_constructor_populate) {
    // Setup
    Array<int> array = Array<int>(5);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;
    array[4] = 4;
    std::vector<int> expect = {0, 1, 2, 3, 4};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, initializer_list) {
    // Setup
    Array<int> array = {12, 21, 10};
    std::vector<int> expect = {12, 21, 10};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, vector_constructor) {
    // Setup
    std::vector<int> expect = {1, 2, 3};
    Array<int> array = Array<int>(expect);

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, array_constructor) {
    // Setup
    Array<int> expect = {1, 2, 3};
    Array<int> array = Array<int>(expect);

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Operator[]

TEST(Array, operator_access_get) {
    // Setup
    Array<int> array = {1, 2, 3};
    int n = array[0];

    // Assertion
    EXPECT_EQ(1, n);
}

TEST(Array, operator_access_get_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array[10]);
}

TEST(Array, operator_access_set) {
    // Setup
    Array<int> array = {1, 2, 3};
    array[0] = 4;
    std::vector<int> expect = {4, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());

}

TEST(Array, operator_access_set_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array[10] = 4);
}

// Operator=

TEST(Array, operator_assign) {
    // Setup
    Array<int> array1 = {4, 5, 6};
    Array<int> array2 = array1;
    std::vector<int> expect = {4, 5, 6};

    // Assertion
    EXPECT_EQ(expect, array2.std_vector());
    EXPECT_EQ(expect, array1.std_vector());
}

TEST(Array, operator_assign_chaining) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {4, 5, 6};
    Array<int> array3 = array2 = array1 = {7, 8, 9};
    std::vector<int> expect = {7, 8, 9};

    // Assertion
    EXPECT_EQ(expect, array1.std_vector());
    EXPECT_EQ(expect, array2.std_vector());
    EXPECT_EQ(expect, array3.std_vector());
}

TEST(Array, operator_assign_self_assignment) {
    // Setup
    Array<int> array = {1, 2, 3};
    array = array;
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Operator+

TEST(Array, operator_plus_array) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {4, 5, 6};
    Array<int> array3 = array1 + array2;
    std::vector<int> expect1 = {1, 2, 3};
    std::vector<int> expect2 = {4, 5, 6};
    std::vector<int> expect3 = {1, 2, 3, 4, 5, 6};

    // Assertion
    EXPECT_EQ(expect1, array1.std_vector());
    EXPECT_EQ(expect2, array2.std_vector());
    EXPECT_EQ(expect3, array3.std_vector());
}

TEST(Array, operator_plus_self_assign) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {4, 5, 6};
    array1 = array1 + array2;
    std::vector<int> expect1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> expect2 = {4, 5, 6};

    // Assertion
    EXPECT_EQ(expect1, array1.std_vector());
    EXPECT_EQ(expect2, array2.std_vector());
}

// Operator+=

TEST(Array, operator_plus_equal_array) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {4, 5, 6};
    array1 += array2;
    std::vector<int> expect1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> expect2 = {4, 5, 6};

    // Assertion
    EXPECT_EQ(expect1, array1.std_vector());
    EXPECT_EQ(expect2, array2.std_vector());
}

// Operator==

TEST(Array, operator_equality) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {1, 2, 3};
    Array<int> array3 = {4, 5, 6};

    // Assertion
    EXPECT_TRUE(array1 == array2);
    EXPECT_FALSE(array1 == array3);
}

TEST(Array, operator_equality_self) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_TRUE(array == array);
}

// Operator!=

TEST(Array, operator_inequality) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {1, 2, 3};
    Array<int> array3 = {4, 5, 6};

    // Assertion
    EXPECT_TRUE(array1 != array3);
    EXPECT_FALSE(array1 != array2);
}

TEST(Array, operator_inequality_self) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_FALSE(array != array);
}

// ObjectAtIndex

TEST(Array, object_at_index) {
    // Setup
    Array<int> array = {1, 2, 3};
    int n = array.objectAtIndex(0);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(1, n);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, object_at_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.objectAtIndex(4));
}

// FirstObject

TEST(Array, first_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    int n = array.firstObject();
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(n, 1);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, first_object_bounds_check) {
    // Setup
    Array<int> array = Array<int>();

    // Assertion
    EXPECT_ANY_THROW(array.firstObject());
}

// LastObject

TEST(Array, last_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    int n = array.lastObject();
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(n, 3);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, last_object_bounds_check) {
    // Setup
    Array<int> array = Array<int>();

    // Assertion
    EXPECT_ANY_THROW(array.lastObject());
}

// Contains

TEST(Array, contains_valid) {
    // Setup
    Array<int> array = {1, 2, 3};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_TRUE(array.contains(3));
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, contains_invalid) {
    // Setup
    Array<int> array = {1, 2, 3};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_FALSE(array.contains(4));
    EXPECT_EQ(expect, array.std_vector());
}

// ContainsAll

TEST(Array, contains_all_valid) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> cont = {1, 2};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_TRUE(array.containsAll(array));
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, contains_all_invalid) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> cont = {1, 2, 4};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_FALSE(array.containsAll(cont));
    EXPECT_EQ(expect, array.std_vector());
}

// Size

TEST(Array, size_empty) {
    // Setup
    Array<int> array = Array<int>();
    size_t size = array.size();

    // Assertion
    EXPECT_EQ(0, size);
}

TEST(Array, size) {
    // Setup
    Array<int> array = {1, 2, 3};
    size_t size = array.size();
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(size, 3);
    EXPECT_EQ(expect, array.std_vector());
}

// IsEmpty

TEST(Array, is_empty_true) {
    // Setup
    Array<int> array = Array<int>();

    // Assertion
    ASSERT_TRUE(array.isEmpty());
}

TEST(Array, is_empty_false) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    ASSERT_FALSE(array.isEmpty());
}

// Add

TEST(Array, add) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.add(4);
    std::vector<int> expect = {1, 2, 3, 4};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, add_all) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> to_add = {4, 5, 6};
    array.addAll(to_add);
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Insert

TEST(Array, insert) {
    // Setup
    Array<int> array = {1, 2, 4};
    array.insert(3, 2);
    std::vector<int> expect = {1, 2, 3, 4};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, insert_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.insert(4, 5));
}

// Remove

TEST(Array, remove_valid) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.remove(2);
    std::vector<int> expect = {1, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, remove_no_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.remove(5);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// RemoveIndex

TEST(Array, remove_index) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.removeIndex(1);
    std::vector<int> expect = {1, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, remove_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.removeIndex(5));
}

// RemoveRange

TEST(Array, remove_range) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    array.removeRange(2, 4);
    std::vector<int> expect = {1, 2, 5};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, remove_range_bound_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.removeRange(2, 5));
}

TEST(Array, remove_range_invalid_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.removeRange(2, 1));
}

// RemoveAllOfObject

TEST(Array, remove_all_of_object_valid) {
    // Setup
    Array<int> array = {1, 2, 2, 3, 2};
    array.removeAll(2);
    std::vector<int> expect = {1, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, remove_all_of_object_no_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.removeAll(4);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// RemoveAllObjects

TEST(Array, remove_objects_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> removables = {4, 3};
    array.removeAll(removables);
    std::vector<int> expect1 = {1, 2, 5};
    std::vector<int> expect2 = {4, 3};

    // Assertion
    EXPECT_EQ(expect1, array.std_vector());
    EXPECT_EQ(expect2, removables.std_vector());
}

TEST(Array, remove_objects_no_object) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> removables = {6, 7, 8};
    array.removeAll(removables);
    std::vector<int> expect1 = {1, 2, 3, 4, 5};
    std::vector<int> expect2 = {6, 7, 8};

    // Assertion
    EXPECT_EQ(expect1, array.std_vector());
    EXPECT_EQ(expect2, removables.std_vector());
}

// RemoveAll

TEST(Array, remove_all) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.removeAll();
    std::vector<int> expect = std::vector<int>();

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// RetainAll

TEST(Array, retain_all_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> ret = {2, 3, 1};
    array.retainAll(ret);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, retain_all_none) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> ret = {4, 5};
    array.retainAll(ret);
    std::vector<int> expect = std::vector<int>();

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Replace

TEST(Array, replace_valid) {
    // Setup
    Array<int> array = {1, 3, 3, 4};
    array.replace(3, 2);
    std::vector<int> expect = {1, 2, 3, 4};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, replace_no_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.replace(4, 5);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// ReplaceLast

TEST(Array, replace_last_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 3};
    array.replaceLast(3, 4);
    std::vector<int> expect = {1, 2, 3, 4};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, replace_last_no_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.replaceLast(4, 5);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// ReplaceIndex

TEST(Array, replace_index) {
    // Setup
    Array<int> array = {1, 4, 3};
    array.replaceIndex(1, 2);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, replace_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.replaceIndex(5, 4));
}

// ReplaceAll

TEST(Array, replace_all_valid) {
    // Setup
    Array<int> array = {1, 2, 2, 3};
    array.replaceAll(2, 3);
    std::vector<int> expect = {1, 3, 3, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, replace_all_no_object) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.replaceAll(4, 5);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Swap

TEST(Array, swap_valid) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.swap(0, 2);
    std::vector<int> expect = {3, 2, 1};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, swap_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.swap(2, 4));
}

// Subarray

TEST(Array, subarray_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> sub = array.subarray(2, 4);
    std::vector<int> expect1 = {3, 4, 5};
    std::vector<int> expect2 = {1, 2, 3, 4, 5};

    // Assertion
    EXPECT_EQ(expect1, sub.std_vector());
    EXPECT_EQ(expect2, array.std_vector());
}

TEST(Array, subarray_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.subarray(2, 5));
}

TEST(Array, subarray_invalid_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.subarray(2, 1));
}

// SubarrayFromIndex

TEST(Array, subarray_from_index_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> sub = array.subarrayFromIndex(2);
    std::vector<int> expect1 = {3, 4, 5};
    std::vector<int> expect2 = {1, 2, 3, 4, 5};

    // Assertion
    EXPECT_EQ(expect1, sub.std_vector());
    EXPECT_EQ(expect2, array.std_vector());
}

TEST(Array, subarray_from_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.subarrayFromIndex(5));
}

// SubarrayToIndex

TEST(Array, subarray_to_index_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    Array<int> sub = array.subarrayToIndex(3);
    std::vector<int> expect1 = {1, 2, 3};
    std::vector<int> expect2 = {1, 2, 3, 4, 5};

    // Assertion
    EXPECT_EQ(expect1, sub.std_vector());
    EXPECT_EQ(expect2, array.std_vector());
}

TEST(Array, subarry_to_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.subarrayToIndex(5));
}

// IndexOf

TEST(Array, index_of_valid) {
    // Setup
    Array<int> array = {1, 2, 3};
    size_t index = array.indexOf(3);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(2, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_no_index) {
    // Setup
    Array<int> array = {1, 2, 3};
    size_t index = array.indexOf(4);
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(Array<int>::NO_INDEX, index);
    EXPECT_EQ(expect, array.std_vector());
}

// IndexOfMinIndex

TEST(Array, index_of_min_index_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOf(1, 2);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(3, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_min_index_no_index) {
    // Setup
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOf(4, 1);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(Array<int>::NO_INDEX, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_min_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.indexOf(1, 5));
}

// IndexOfLast

TEST(Array, index_of_last_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOfLast(1);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(3, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_last_no_index) {
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOfLast(4, 1);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(Array<int>::NO_INDEX, index);
    EXPECT_EQ(expect, array.std_vector());
}

// IndexOfLastMaxIndex

TEST(Array, index_of_last_max_index_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOfLast(1, 2);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(0, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_last_max_index_no_index) {
    // Setup
    Array<int> array = {1, 2, 3, 1};
    size_t index = array.indexOfLast(4, 2);
    std::vector<int> expect = {1, 2, 3, 1};

    // Assertion
    EXPECT_EQ(Array<int>::NO_INDEX, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_last_max_index_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.indexOfLast(1, 5));
}

// IndexOfObjectInRange

TEST(Array, index_of_object_in_range_valid) {
    // Setup
    Array<int> array = {1, 2, 3, 1, 4, 5, 6, 1};
    size_t index = array.indexOfObjectInRange(1, 2, 5);
    std::vector<int> expect = {1, 2, 3, 1, 4, 5, 6, 1};

    // Assertion
    EXPECT_EQ(3, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_object_in_range_no_index) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5};
    size_t index = array.indexOfObjectInRange(6, 1, 3);
    std::vector<int> expect = {1, 2, 3, 4, 5};

    // Assertion
    EXPECT_EQ(Array<int>::NO_INDEX, index);
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, index_of_object_in_range_bounds_check) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.indexOfObjectInRange(1, 2, 5));
}

TEST(Array, index_of_object_in_range_invalid) {
    // Setup
    Array<int> array = {1, 2, 3};

    // Assertion
    EXPECT_ANY_THROW(array.indexOfObjectInRange(1, 2, 1));
}

// Sort

TEST(Array, sort) {
    // Setup
    Array<int> array = {3, 2, 5, 1, 4, 6};
    array.sort();
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, sort_sorted) {
    // Setup
    Array<int> array = {1, 2, 3, 4, 5, 6};
    array.sort();
    std::vector<int> expect = {1, 2, 3, 4, 5, 6};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// Reverse

TEST(Array, reverse) {
    // Setup
    Array<int> array = {1, 2, 3};
    array.reverse();
    std::vector<int> expect = {3, 2, 1};

    // Assertion
    EXPECT_EQ(expect, array.std_vector());
}

// IsEqualTo

TEST(Array, is_equal_to_true) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {1, 2, 3};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_TRUE(array1.isEqualTo(array2));
    EXPECT_EQ(expect, array1.std_vector());
    EXPECT_EQ(expect, array2.std_vector());
}

TEST(Array, is_equal_to_false) {
    // Setup
    Array<int> array1 = {1, 2, 3};
    Array<int> array2 = {3, 2, 1};
    std::vector<int> expect1 = {1, 2, 3};
    std::vector<int> expect2 = {3, 2, 1};

    // Assertion
    EXPECT_FALSE(array1.isEqualTo(array2));
    EXPECT_EQ(expect1, array1.std_vector());
    EXPECT_EQ(expect2, array2.std_vector());
}

TEST(Array, is_equal_to_self) {
    // Setup
    Array<int> array = {1, 2, 3};
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_TRUE(array.isEqualTo(array));
    EXPECT_EQ(expect, array.std_vector());
}

// Copy

TEST(Array, copy) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> copy = array.copy();
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, copy.std_vector());
    EXPECT_EQ(expect, array.std_vector());
}

TEST(Array, copy_chained) {
    // Setup
    Array<int> array = {1, 2, 3};
    Array<int> copy = array.copy().reverse();
    std::vector<int> expect1 = {3, 2, 1};
    std::vector<int> expect2 = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect1, copy.std_vector());
    EXPECT_EQ(expect2, array.std_vector());
}

// Std_Vector

TEST(Array, std_vector) {
    // Setup
    Array<int> array = {1, 2, 3};
    std::vector<int> vector = array.std_vector();
    std::vector<int> expect = {1, 2, 3};

    // Assertion
    EXPECT_EQ(expect, vector);
}

// Iterator

TEST(Array, range_loop) {
    // Setup
    Array<int> array = {1, 2, 3};
    int sum = 0;
    for (auto i : array) {
        sum += i;
    }

    // Assertion
    EXPECT_EQ(6, sum);
}