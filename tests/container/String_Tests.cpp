//
// Created by Matthew Remmel on 9/1/17.
//

#include "gtest/gtest.h"
#include "String.hpp"
#include "Exception.hpp"

using namespace abraham;


TEST(String, default_constructor) {
    // Setup
    String empty = String();

    // Assertion
    EXPECT_STREQ("", empty.c_string());
}

TEST(String, c_str_constructor) {
    // Setup
    char* c_str = new char[5];
    c_str[0] = 't'; c_str[1] = 'e'; c_str[2] = 's'; c_str[3] = 't'; c_str[4] = '\0';
    String string = String(c_str);

    // Assertion
    EXPECT_STREQ("test", string.c_string());
    EXPECT_STREQ("test", c_str);

    // Clean up
    delete[](c_str);
}

TEST(String, std_str_constructor) {
    // Setup
    std::string std_str = "test";
    String string = String(std_str);

    // Assertion
    EXPECT_STREQ("test", string.c_string());
}

TEST(String, literal_constructor) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_STREQ("test", string.c_string());
}

TEST(String, string_constructor) {
    // Setup
    String string1 = String("test");
    String string2 = String(string1);

    // Assertion
    EXPECT_STREQ("test", string2.c_string());
}

// Operator[]

TEST(String, operator_access_get) {
    // Setup
    String string = String("test");
    char c = string[1];

    // Assertion
    EXPECT_EQ('e', c);
}

TEST(String, operator_access_get_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(string[10], OutOfBoundsException);
}

TEST(String, operator_access_set) {
    // Setup
    String string = String("test");
    string[0] = 'b';

    // Assertion
    EXPECT_STREQ("best", string.c_string());
}

TEST(String, operator_access_set_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(string[10] = 'b', OutOfBoundsException);
}

// Operator=

TEST(String, operator_assign) {
    // Setup
    String string1 = String("test");
    String string2 = string1;

    // Assertion
    EXPECT_STREQ("test", string2.c_string());
}

TEST(String, operator_assign_chaining) {
    // Setup
    String string1 = String("code");
    String string2 = String("edoc");
    String string3 = string2 = string1 = "test";

    // Assertion
    EXPECT_STREQ("test", string1.c_string());
    EXPECT_STREQ("test", string2.c_string());
    EXPECT_STREQ("test", string3.c_string());
}

TEST(String, operator_assign_self_assignment) {
    // Setup
    String string = String("test");
    string = string;

    // Assertion
    EXPECT_STREQ("test", string.c_string());
}

// Operator+

TEST(String, operator_plus) {
    // Setup
    String string1 = String("hello");
    String string2 = String("world");
    String string3 = string1 + string2;

    // Assertion
    EXPECT_STREQ("hello", string1.c_string());
    EXPECT_STREQ("world", string2.c_string());
    EXPECT_STREQ("helloworld", string3.c_string());
}

TEST(String, operator_plus_self_assign) {
    // Setup
    String string1 = String("hello");
    String string2 = String("world");
    string1 = string1 + string2;

    // Assertion
    EXPECT_STREQ("helloworld", string1.c_string());
    EXPECT_STREQ("world", string2.c_string());
}

// Operator+=

TEST(String, operator_plus_equal) {
    // Setup
    String string1 = String("hello");
    String string2 = String("world");
    string1 += string2;

    // Assertion
    EXPECT_STREQ("helloworld", string1.c_string());
    EXPECT_STREQ("world", string2.c_string());
}

// Operator==

TEST(String, operator_equality) {
    // Setup
    String string1 = String("test");
    String string2 = String("test");
    String string3 = String("code");

    // Assertion
    EXPECT_TRUE(string1 == string2);
    EXPECT_FALSE(string1 == string3);
}

TEST(String, operator_equality_self) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_TRUE(string == string);
}

// Operator!=

TEST(String, operator_inequality) {
    // Setup
    String string1 = String("test");
    String string2 = String("test");
    String string3 = String("code");

    // Assertion
    EXPECT_FALSE(string1 != string2);
    EXPECT_TRUE(string1 != string3);
}

TEST(String, operator_inequality_self) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_FALSE(string != string);
}

// Operator<

TEST(String, operator_less) {
    // Setup
    String string1 = String("1");
    String string2 = String("2");

    // Assertions
    EXPECT_TRUE(string1 < string2);
    EXPECT_FALSE(string2 < string1);
}

TEST(String, operator_less_self) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_FALSE(string < string);   
}

// Operator>

TEST(String, operator_greater) {
    // Setup
    String string1 = String("2");
    String string2 = String("1");

    // Assertions
    EXPECT_TRUE(string1 > string2);
    EXPECT_FALSE(string2 > string1);
}

TEST(String, operator_greater_self) {
    // Setup
    String string = String("test");

    // Assert
    EXPECT_FALSE(string > string);
}

// Operator<=

TEST(String, operator_less_equal) {
    // Setup
    String string1 = String("1");
    String string2 = String("1");
    String string3 = String("2");

    // Assertions
    EXPECT_TRUE(string1 <= string2);
    EXPECT_TRUE(string1 <= string3);
    EXPECT_FALSE(string3 <= string1);
}

TEST(String, operator_less_equal_self) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_TRUE(string <= string);
}

// Operator>=

TEST(String, operator_greater_equal) {
    // Setup
    String string1 = String("2");
    String string2 = String("2");
    String string3 = String("1");

    // Assertions
    EXPECT_TRUE(string1 >= string2);
    EXPECT_TRUE(string1 >= string3);
    EXPECT_FALSE(string3 >= string1);
}

TEST(String, operator_greater_equal_self) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_TRUE(string >= string);
}

// Length

TEST(String, string_length_empty) {
    // Setup
    String empty = String();

    // Assertion
    EXPECT_EQ(0, empty.length());
}

TEST(String, string_length) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_EQ(4, string.length());
}

// CharacterAtIndex

TEST(String, char_at_index) {
    // Setup
    String string = String("test");
    char c = string.characterAtIndex(1);

    // Assertion
    EXPECT_EQ('e', c);
}

TEST(String, char_at_index_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(string.characterAtIndex(10), OutOfBoundsException);
}

// SetCharacterAtIndex

TEST(String, set_char_at_index) {
    // Setup
    String string = String("test");
    string.setCharacterAtIndex('b', 0);

    // Assertion
    EXPECT_STREQ("best", string.c_string());
}

TEST(String, set_char_at_index_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(string.setCharacterAtIndex('b', 10), OutOfBoundsException);
}

// SetValue

TEST(String, string_set_value) {
    String string1 = String("hello");
    String string2 = String("world");
    string1.setValue(string2);

    // Assertion
    EXPECT_STREQ("world", string1.c_string());
}

TEST(String, string_set_value_chaining) {
    // Setup
    String string = String("test");
    string.setValue("hello").setValue("world");

    // Assertion
    EXPECT_STREQ("world", string.c_string());
}

// ToLowerCase

TEST(String, to_lower_case) {
    // Setup
    String string = String("TEST");
    string.toLowerCase();

    // Assertion
    EXPECT_STREQ("test", string.c_string());
}

// ToUpperCase

TEST(String, to_upper_case) {
    // Setup
    String string = String("test");
    string.toUpperCase();

    // Assertion
    EXPECT_STREQ("TEST", string.c_string());
}

// ToCapitalCase

TEST(String, to_capitalized_string) {
    // Setup
    String string = "hello world";
    string.toCapitalCase();

    // Assertion
    EXPECT_STREQ("Hello World", string.c_string());
}

// SwapCase

TEST(String, swap_case) {
    // Setup
    String string = String("Hello World");
    string.swapCase();

    // Assertion
    EXPECT_STREQ("hELLO wORLD", string.c_string());
}

// Append

TEST(String, append) {
    // Setup
    String string1 = String("hello");
    String string2 = String("world");
    string1.append(string2);

    // Assertion
    EXPECT_STREQ("helloworld", string1.c_string());
}

TEST(String, append_chaining) {
    // Setup
    String string1 = String("hello");
    String string2 = string1.append("world").append("!");

    // Assertion
    EXPECT_STREQ("helloworld!", string1.c_string());
    EXPECT_STREQ("helloworld!", string2.c_string());
}

// Substring

TEST(String, substring) {
    // Setup
    String string = String("hello world");
    String substring = string.substring(0, 5);

    // Assertion
    EXPECT_STREQ("hello", substring.c_string());
}

TEST(String, substring_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(String sub = string.substring(0, 10), OutOfBoundsException);
}

// SubstringFromIndex

TEST(String, substring_from_index) {
    // Setup
    String string = String("hello world");
    String substring = string.substringFromIndex(6);

    // Assertion
    EXPECT_STREQ("world", substring.c_string());
}

TEST(String, substring_from_index_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(String sub = string.substringFromIndex(10), OutOfBoundsException);
}

// SubstringToIndex

TEST(String, substring_to_index) {
    // Setup
    String string = String("hello world");
    String substring = string.substringToIndex(5);

    // Assertion
    EXPECT_STREQ("hello", substring.c_string());
}

TEST(String, substring_to_index_bounds_check) {
    // Setup
    String string = String("test");

    // Assertion
    EXPECT_THROW(String sub = string.substringToIndex(10), OutOfBoundsException);
}

// Split

TEST(String, split_extra_space) {
    // Setup
    String string = String("hello  world");
    String delim = String(" ");
    std::vector<String> split_string = string.split(delim);

    // Assertion
    EXPECT_STREQ("hello", split_string[0].c_string());
    EXPECT_STREQ("", split_string[1].c_string());
    EXPECT_STREQ("world", split_string[2].c_string());
    EXPECT_EQ(3, split_string.size());
}

TEST(String, split_no_delimeter) {
    // Setup
    String string = String("hello");
    String delim = String("");
    std::vector<String> split_string = string.split(delim);

    // Assertion
    EXPECT_STREQ("", delim.c_string());
    EXPECT_STREQ("h", split_string[0].c_string());
    EXPECT_STREQ("e", split_string[1].c_string());
    EXPECT_STREQ("l", split_string[2].c_string());
    EXPECT_STREQ("l", split_string[3].c_string());
    EXPECT_STREQ("o", split_string[4].c_string());
    EXPECT_EQ(5, split_string.size());
}

// Insert

TEST(String, insert) {
    // Setup
    String string = String("hello world");
    String insert = String("cruel ");
    string.insert(insert, 6);

    // Assertion
    EXPECT_STREQ("hello cruel world", string.c_string());
}

TEST(String, insert_bounds_check) {
    // Setup
    String string = String("test");
    String insert = String("foo");

    // Assertion
    EXPECT_THROW(string.insert(insert, 10), OutOfBoundsException);
}

// Trim

TEST(String, trim_whitespace) {
    // Setup
    String string = String("\n\r\t hello world \n\r\t");
    string.trim();

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

TEST(String, trim_ascii) {
    // Setup
    String string = String("ababhello worldabab");
    string.trim("ab");

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

TEST(String, trim_nothing) {
    // Setup
    String string = String("hello world");
    string.trim();

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

// TrimLeading

TEST(String, trim_leading_whitespace) {
    // Setup
    String string = String("\n\r\t hello world \n\r\t");
    string.trimLeading();

    // Assertion
    EXPECT_STREQ("hello world \n\r\t", string.c_string());
}

TEST(String, trim_leading_ascii) {
    // Setup
    String string = String("ababhello worldabab");
    string.trimLeading("ab");

    // Assertion
    EXPECT_STREQ("hello worldabab", string.c_string());
}

TEST(String, trim_leading_nothing) {
    // Setup
    String string = String("hello world");
    string.trim();

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

// TrimTrailing

TEST(String, trim_trailing_whitespace) {
    // Setup
    String string = String("\n\r\t hello world \n\r\t");
    string.trimTrailing();

    // Assertion
    EXPECT_STREQ("\n\r\t hello world", string.c_string());
}

TEST(String, trim_trailing_ascii) {
    // Setup
    String string = String("ababhello worldabab");
    string.trimTrailing("ab");

    // Assertion
    EXPECT_STREQ("ababhello world", string.c_string());
}

TEST(String, trim_trailing_nothing) {
    // Setup
    String string = String("hello world");
    string.trim();

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

// Reverse

TEST(String, reverse) {
    // Setup
    String string = String("hello world");
    string.reverse();

    // Assertion
    EXPECT_STREQ("dlrow olleh", string.c_string());
}

// Pad

TEST(String, pad) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.pad(pad, 1);

    // Assertion
    EXPECT_STREQ(" hello world ", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

TEST(String, pad_zero) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.pad(pad, 0);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

// PadLeft

TEST(String, pad_left) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.padLeft(pad, 1);

    // Assertion
    EXPECT_STREQ(" hello world", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

TEST(String, pad_left_zero) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.padLeft(pad, 0);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

// PadRight

TEST(String, pad_right) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.padRight(pad, 1);

    // Assertion
    EXPECT_STREQ("hello world ", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

TEST(String, pad_right_zero) {
    // Setup
    String string = String("hello world");
    String pad = String(" ");
    string.padRight(pad, 0);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ(" ", pad.c_string());
}

// Replace

TEST(String, replace_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("world");
    String replacement = String("merica");
    string.replace(target, replacement);

    // Assertion
    EXPECT_STREQ("hello merica hello world", string.c_string());
    EXPECT_STREQ("world", target.c_string());
    EXPECT_STREQ("merica", replacement.c_string());
}

TEST(String, replace_invalid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("merica");
    String replacement = String("code");
    string.replace(target, replacement);

    // Assertion
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("merica", target.c_string());
    EXPECT_STREQ("code", replacement.c_string());
}

// ReplaceLast

TEST(String, replace_last_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("hello");
    String replacement = String("merica");
    string.replaceLast(target, replacement);

    // Assertion
    EXPECT_STREQ("hello world merica world", string.c_string());
    EXPECT_STREQ("hello", target.c_string());
    EXPECT_STREQ("merica", replacement.c_string());
}

TEST(String, replace_last_invalid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("merica");
    String replacement = String("code");
    string.replaceLast(target, replacement);

    // Assertion
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("merica", target.c_string());
    EXPECT_STREQ("code", replacement.c_string());
}

// ReplaceAll

TEST(String, replace_all_valid) {
    // Setup
    String string = String("hello world world");
    String target = String("world");
    String replacement = String("merica");
    string.replaceAll(target, replacement);

    // Assertion
    EXPECT_STREQ("hello merica merica", string.c_string());
    EXPECT_STREQ("world", target.c_string());
    EXPECT_STREQ("merica", replacement.c_string());
}

TEST(String, replace_all_invalid) {
    // Setup
    String string = String("hello world world");
    String target = String("alice");
    String replacement = String("merica");
    string.replaceAll(target, replacement);

    // Assertion
    EXPECT_STREQ("hello world world", string.c_string());
    EXPECT_STREQ("alice", target.c_string());
    EXPECT_STREQ("merica", replacement.c_string());
}

// Remove

TEST(String, remove_valid) {
    // Setup
    String string = String("hello world hello world");
    String remove_str = String("world ");
    string.remove(remove_str);

    // Assertion
    EXPECT_STREQ("hello hello world", string.c_string());
    EXPECT_STREQ("world ", remove_str.c_string());
}

TEST(String, remove_invalid) {
    // Setup
    String string = String("hello world hello world");
    String remove_str = String("merica");
    string.remove(remove_str);

    // Assertion
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("merica", remove_str.c_string());
}

// RemoveLast

TEST(String, remove_last_valid) {
    // Setup
    String string = String("hello world hello world");
    String remove_str = String(" world");
    string.removeLast(remove_str);

    // Assertion
    EXPECT_STREQ("hello world hello", string.c_string());
    EXPECT_STREQ(" world", remove_str.c_string());
}

TEST(String, remove_last_invalid) {
    // Setup
    String string = String("hello world hello world");
    String remove_str = String("merica");
    string.removeLast(remove_str);

    // Assertion
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("merica", remove_str.c_string());
}

// RemoveRange

TEST(String, remove_range) {
    // Setup
    String string = String("hello cruel world");
    string.removeRange(6, 12);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
}

// RemoveCharacters

TEST(String, remove_characters_valid) {
    // Setup
    String string = String("hello world");
    String characters = String("l ");
    string.removeCharacters(characters);

    // Assertion
    EXPECT_STREQ("heoword", string.c_string());
    EXPECT_STREQ("l ", characters.c_string());
}

TEST(String, remove_characters_invalid) {
    // Setup
    String string = String("hello world");
    String characters = String("abc");
    string.removeCharacters(characters);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("abc", characters.c_string());
}

// RemoveAll

TEST(String, remove_all_valid) {
    // Setup
    String string = String("hello world world");
    String remove_str = String("world");
    string.removeAll(remove_str);

    // Assertion
    EXPECT_STREQ("hello  ", string.c_string());
    EXPECT_STREQ("world", remove_str.c_string());
}

TEST(String, remove_all_invalid) {
    // Setup
    String string = String("hello world");
    String remove_str = String("merica");
    string.removeAll(remove_str);

    // Assertion
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("merica", remove_str.c_string());
}

// Contains

TEST(String, contains_valid) {
    // Setup
    String string = String("hello world");
    String search_str = String("world");
    bool contains = string.contains(search_str);

    // Assertion
    EXPECT_TRUE(contains == true);
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("world", search_str.c_string());
}

TEST(String, contains_invalid) {
    // Setup
    String string = String("hello world");
    String search_str = String("merica");
    bool contains = string.contains(search_str);

    // Assertion
    EXPECT_TRUE(contains == false);
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("merica", search_str.c_string());
}

// IndexOf

TEST(String, index_of_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("world");
    size_t index = string.indexOf(target);

    // Assertion
    EXPECT_EQ(6, index);
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("world", target.c_string());
}

TEST(String, index_of_invalid) {
    // Setup
    String string = String("hello world");
    String target = String("merica");
    size_t index = string.indexOf(target);

    // Assertion
    EXPECT_EQ(String::NO_INDEX, index);
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("merica", target.c_string());
}

TEST(String, index_of__index_limit_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("hello");
    size_t index = string.indexOf(target, 6);

    // Assertion
    EXPECT_EQ(12, index);
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("hello", target.c_string());
}

TEST(String, index_of_index_limit_invalid) {
    // Setup
    String string = String("hello world world");
    String target = String("hello");
    size_t index = string.indexOf(target, 6);

    // Assertion
    EXPECT_EQ(String::NO_INDEX, index);
    EXPECT_STREQ("hello world world", string.c_string());
    EXPECT_STREQ("hello", target.c_string());
}

// IndexOfLast

TEST(String, index_of_last_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("world");
    size_t index = string.indexOfLast(target);

    // Assertion
    EXPECT_EQ(18, index);
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("world", target.c_string());
}

TEST(String, index_of_last_invalid) {
    // Setup
    String string = String("hello world");
    String target = String("merica");
    size_t index = string.indexOfLast(target);

    // Assertion
    EXPECT_EQ(String::NO_INDEX, index);
    EXPECT_STREQ("hello world", string.c_string());
    EXPECT_STREQ("merica", target.c_string());
}

TEST(String, index_of_last_index_limit_valid) {
    // Setup
    String string = String("hello world hello world");
    String target = String("hello");
    size_t index = string.indexOfLast(target, 18);

    // Assertion
    EXPECT_EQ(12, index);
    EXPECT_STREQ("hello world hello world", string.c_string());
    EXPECT_STREQ("hello", target.c_string());
}

TEST(String, index_of_last_index_limit_invalid) {
    // Setup
    String string = String("world world hello");
    String target = String("hello");
    size_t index = string.indexOfLast(target, 11);

    // Assertion
    EXPECT_EQ(String::NO_INDEX, index);
    EXPECT_STREQ("world world hello", string.c_string());
    EXPECT_STREQ("hello", target.c_string());
}


// IsEqualTo

TEST(String, is_equal_to_string) {
    // Setup
    String string1 = String("test");
    String string2 = String("test");
    String string3 = String("TEST");

    // Assertion
    EXPECT_TRUE(string1.isEqualTo(string2));
    EXPECT_FALSE(string1.isEqualTo(string3));
}

// IsEqualToIgnoreCase

TEST(String, is_equal_ignore_case_string) {
    // Setup
    String string1 = String("test");
    String string2 = String("TeST");
    String string3 = String("code");

    // Assertion
    EXPECT_TRUE(string1.isEqualTo(string2, false));
    EXPECT_FALSE(string1.isEqualTo(string3, false));
}

// Compare

TEST(String, compare_less) {
    // Setup
    String string1 = String("aaron");
    String string2 = String("mark");

    // Assertion
    EXPECT_TRUE(string1.compare(string2) < 0);
}

TEST(String, compare_greater) {
    // Setup
    String string1 = String("mark");
    String string2 = String("aaron");

    // Assertion
    EXPECT_TRUE(string1.compare(string2) > 0);
}

TEST(String, compare_equal) {
    // Setup
    String string1 = String("test");
    String string2 = String("test");

    // Assertion
    EXPECT_TRUE(string1.compare(string2) == 0);
}

TEST(String, compare_equal_sub) {
    // Setup
    String string1 = String("hello");
    String string2 = String("helloworld");

    // Assertion
    EXPECT_TRUE(string1.compare(string2) < 0);
}

TEST(String, compare_case) {
    // Setup
    String string1 = String("mark");
    String string2 = String("AARON");

    // Assertion
    EXPECT_TRUE(string1.compare(string2) > 0);
}

// CompareIgnoreCase

TEST(String, compare_ignore_case_less) {
    // Setup
    String string1 = String("AARON");
    String string2 = String("mark");

    // Assertion
    EXPECT_TRUE(string1.compare(string2, false) < 0);
}

TEST(String, compare_ignore_case_greater) {
    // Setup
    String string1 = String("mark");
    String string2 = String("AARON");

    // Assertion
    EXPECT_TRUE(string1.compare(string2, false) > 0);
}

TEST(String, compare_ignore_case_equal) {
    // Setup
    String string1 = String("test");
    String string2 = String("TEST");

    // Assertion
    EXPECT_TRUE(string1.compare(string2, false) == 0);
}

TEST(String, compare_ignore_case_equal_sub) {
    // Setup
    String string1 = String("hello");
    String string2 = String("HELLOWORLD");

    // Assertion
    EXPECT_TRUE(string1.compare(string2, false) < 0);
}

// IntValue

TEST(String, int_value_valid) {
    // Setup
    String positive = String("10");
    String negative = String("-10");
    int pos = positive.intValue();
    int neg = negative.intValue();

    // Assertion
    EXPECT_EQ(10, pos);
    EXPECT_EQ(-10, neg);
    EXPECT_STREQ("10", positive.c_string());
    EXPECT_STREQ("-10", negative.c_string());
}

TEST(String, int_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.intValue(), InvalidValueException);
}

// LongValue

TEST(String, long_value_valid) {
    // Setup
    String positive = String("10");
    String negative = String("-10");
    long pos = positive.longValue();
    long neg = negative.longValue();

    // Assertion
    EXPECT_EQ(10, pos);
    EXPECT_EQ(-10, neg);
    EXPECT_STREQ("10", positive.c_string());
    EXPECT_STREQ("-10", negative.c_string());
}

TEST(String, long_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.longValue(), InvalidValueException);
}

// LongLongValue

TEST(String, long_long_value_valid) {
    // Setup
    String positive = String("10");
    String negative = String("-10");
    long long pos = positive.longLongValue();
    long long neg = negative.longLongValue();

    // Assertion
    EXPECT_EQ(10, pos);
    EXPECT_EQ(-10, neg);
    EXPECT_STREQ("10", positive.c_string());
    EXPECT_STREQ("-10", negative.c_string());
}

TEST(String, long_long_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.longLongValue(), InvalidValueException);
}

// UnsignedValue

TEST(String, unsigned_value_valid) {
    // Setup
    String string = String("10");
    unsigned n = string.unsignedValue();

    // Assertion
    EXPECT_EQ(10, n);
    EXPECT_STREQ("10", string.c_string());
}

TEST(String, unsigned_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.unsignedValue(), InvalidValueException);
}

// UnsignedLongValue

TEST(String, unsigned_long_value_valid) {
    // Setup
    String string = String("10");
    unsigned long n = string.unsignedLongValue();

    // Assertion
    EXPECT_EQ(10, n);
    EXPECT_STREQ("10", string.c_string());
}

TEST(String, unsigned_long_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.unsignedLongValue(), InvalidValueException);
}

// UnsignedLongLongValue

TEST(String, unsigned_long_long_value_valid) {
    // Setup
    String string = String("10");
    unsigned long long n = string.unsignedLongLongValue();

    // Assertion
    EXPECT_EQ(10, n);
    EXPECT_STREQ("10", string.c_string());
}

TEST(String, unsigned_long_long_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.unsignedLongLongValue(), InvalidValueException);
}

// DoubleValue

TEST(String, double_value_valid) {
    // Setup
    String positive = String("1.234");
    String negative = String("-1.234");
    double pos = positive.doubleValue();
    double neg = negative.doubleValue();

    // Assertion
    EXPECT_NEAR(pos, 1.234, 0.0001);
    EXPECT_NEAR(neg, -1.234, 0.0001);
    EXPECT_STREQ("1.234", positive.c_string());
    EXPECT_STREQ("-1.234", negative.c_string());

}

TEST(String, double_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.doubleValue(), InvalidValueException);
}

// LongDoubleValue

TEST(String, long_double_value_valid) {
    // Setup
    String positive = String("1.234");
    String negative = String("-1.234");
    long double pos = positive.longDoubleValue();
    long double neg = negative.longDoubleValue();

    // Assertion
    EXPECT_NEAR(pos, 1.234, 0.0001);
    EXPECT_NEAR(neg, -1.234, 0.0001);
    EXPECT_STREQ("1.234", positive.c_string());
    EXPECT_STREQ("-1.234", negative.c_string());
}

TEST(String, long_double_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.longDoubleValue(), InvalidValueException);
}

// FloatValue

TEST(String, float_value_valid) {
    // Setup
    String positive = String("1.234");
    String negative = String("-1.234");
    float pos = positive.floatValue();
    float neg = negative.floatValue();

    // Assertion
    EXPECT_NEAR(pos, 1.234, 0.0001);
    EXPECT_NEAR(neg, -1.234, 0.0001);
    EXPECT_STREQ("1.234", positive.c_string());
    EXPECT_STREQ("-1.234", negative.c_string());
}

TEST(String, float_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.floatValue(), InvalidValueException);
}

// BoolValue

TEST(String, bool_value_valid_upper_case) {
    // Setup
    String true_string = String("TRUE");
    String false_string = String("FALSE");
    String yes_string = String("YES");
    String no_string = String("NO");
    String y_string = String("Y");
    String n_string = String("N");
    String zero_string = String("0");
    String one_string = String("1");

    // Assertion
    EXPECT_TRUE(true_string.boolValue() == true);
    EXPECT_TRUE(false_string.boolValue() == false);
    EXPECT_TRUE(yes_string.boolValue() == true);
    EXPECT_TRUE(no_string.boolValue() == false);
    EXPECT_TRUE(y_string.boolValue() == true);
    EXPECT_TRUE(n_string.boolValue() == false);
    EXPECT_TRUE(one_string.boolValue() == true);
    EXPECT_TRUE(zero_string.boolValue() == false);
}

TEST(String, bool_value_valid_lower_case) {
    // Setup
    String true_string = String("true");
    String false_string = String("false");
    String yes_string = String("yes");
    String no_string = String("no");
    String y_string = String("y");
    String n_string = String("n");
    String zero_string = String("0");
    String one_string = String("1");

    // Assertion
    EXPECT_TRUE(true_string.boolValue() == true);
    EXPECT_TRUE(false_string.boolValue() == false);
    EXPECT_TRUE(yes_string.boolValue() == true);
    EXPECT_TRUE(no_string.boolValue() == false);
    EXPECT_TRUE(y_string.boolValue() == true);
    EXPECT_TRUE(n_string.boolValue() == false);
    EXPECT_TRUE(one_string.boolValue() == true);
    EXPECT_TRUE(zero_string.boolValue() == false);
}

TEST(String, bool_value_invalid) {
    // Setup
    String string = String("test");

    // Assertions
    EXPECT_THROW(string.boolValue(), InvalidValueException);
}

// Copy

TEST(String, string_copy) {
    // Setup
    String string = String("test");
    String copy = string.copy();

    // Assertion
    EXPECT_STREQ("test", string.c_string());
    EXPECT_STREQ("test", copy.c_string());
}

// C_String

TEST(String, c_string) {
    // Setup
    String string = String("test");
    const char* c_str = string.c_string();

    // Assertion
    EXPECT_STREQ("test", c_str);
}

// Std_String

TEST(String, std_string) {
    // Setup
    String string = String("test");
    std::string std_str = string.std_string();

    // Assertion
    EXPECT_STREQ("test", std_str.c_str());
}

