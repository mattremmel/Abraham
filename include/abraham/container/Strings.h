//
// Created by Matthew Remmel on 9/1/17.
//

#ifndef ABRAHAM_STRING_H
#define ABRAHAM_STRING_H

#include <string>
#include <vector>


namespace abraham {

    /**
     * A wrapper around std::string that provides more convenient and higher level functions.
     */
    class String {
    protected:
        /**
         * The internal std::string object that this Class wraps.
         */
        std::string _data;

    public:
        /**
         * Default constructor that creates an empty String object.
         */
        String();

        /**
         * Constructor that creates a String object with a character value.
         * @param character - The character that the String object is constructed from.
         */
        String(char character);

        /**
         * Constructor that creates a String object from a C style string.
         * @param cstring - The C string that the String object is constructed from.
         */
        String(const char *cstring);

        /**
         * Constructor that creates a String object from a std::string.
         * @param string - The std::string that the String object is constructed from.
         */
        String(const std::string &string);

        /**
         * Constructor that creates a String object from another String object.
         * @param string - The String object that the String object is constructed from.
         */
        String(const String &string);

        /**
         * Operator overload to access String characters using the '[ ]' operator.
         * @param index - The 0-based index of the character in the String.
         * @return - A char reference of the character at the provided index.
         */
        char &operator[](size_t index);

        /**
         * Operator overload to set a new String value using the '=' operator.
         * @param string - The String that the new value will be set to.
         * @return A self reference.
         */
        String &operator=(const String &string);

        /**
         * Operator overload to concatenate two String objects using the '+' operator.
         * @param string - The value to concatenate this String with.
         * @return A new String with the value with the concatenated value.
         */
        const String operator+(const String &string) const;

        /**
         * Operator overload to concatenate this String with another one in place using the '+=' operator.
         * @param string - The value to concatenate this String with.
         * @return A self reference.
         */
        String &operator+=(const String &string);

        /**
         * Operator overload to check the equality of two String objects using the '==' operator.
         * @param string - The value to compare this String to.
         * @return true if the two String objects are equal in value; false otherwise.
         */
        bool operator==(const String &string) const;

        /**
         * Operator overload to check the inequality of two String objects using the '!=' operator.
         * @param string - The value to compare this String to.
         * @return true if the two String objects are not equal in value; false otherwise.
         */
        bool operator!=(const String &string) const;

        /**
         * Operator overload to check the lexicographical order of two String objects using the '<' operator.
         * @param string - The value to compare this String to.
         * @return true if this String is lexicographically less than the provided String; false otherwise.
         */
        bool operator<(const String &string) const;

        /**
         * Operator overload to check the lexicographical order of two String objects using the '>' operator.
         * @param string - The value to compare this String to.
         * @return true if this String is lexicographically greater than the provided String; false otherwise.
         */
        bool operator>(const String &string) const;

        /**
         * Operator overload to check the lexicographical order of two String objects using the '<=' operator.
         * @param string - The value to compare this String to.
         * @return true if this String is lexicographically less than or equal to the provided String; false otherwise.
         */
        bool operator<=(const String &string) const;

        /**
         * Operator overload to check the lexicographical order of two String objects using the '>= operator.
         * @param string - The value to compare this String to.
         * @return true if this String is lexicographically greather than or equal to the provided String; false otherwise.
         */
        bool operator>=(const String &string) const;

        /**
         * @return The number of ASCII characters contained in the String.
         */
        size_t length() const;

        /**
         * @param index - The 0-based index of a character in the String.
         * @return A char references of the character at the provided index.
         */
        char characterAtIndex(size_t index) const;

        /**
         * Sets a character value at the provided index.
         * @param c - The new character value that will be set.
         * @param index - The index to set the character value at.
         * @return A self reference.
         */
        String &setCharacterAtIndex(const char c, size_t index);

        /**
         * Sets all upper case characters in the String to their lower case counterparts.
         * @return A self reference.
         */
        String &toLowerCase();

        /**
         * Sets all lower case characters in the String to their upper case counterparts.
         * @return A self reference.
         */
        String &toUpperCase();

        /**
         * Sets the first letter of each word to its upper case form, if it isn't already.
         * @return A self reference.
         */
        String &toCapitalCase();

        /**
         * Sets all characters to their respective lower or upper case counter part.
         * @return A self reference.
         */
        String &swapCase();

        /**
         * Appends a String to the end of this String.
         * @param string - The String whose value with be appended.
         * @return A self reference.
         */
        String &append(const String &string);

        /**
         * Retrieve a subsection of this String.
         * @param from_index - The starting index of the desired substring.
         * @param to_index - The ending index of the desired substring.
         * @return A new String whose value is that of the substring.
         */
        String substring(size_t from_index, size_t to_index) const;

        /**
         * Retrieve a subsection of this String, from the provided index to the end.
         * @param index - The starting index of the desired substring.
         * @return A new String whose value is that of the substring.
         */
        String substringFromIndex(size_t index) const;

        /**
         * Retrieve a subsection of this String, from the beginning to the provided index.
         * @param index - The index of the end of the desired substring.
         * @return A new String whose value is that of the substring.
         */
        String substringToIndex(size_t index) const;

        /**
         * Splits the String into components at each provided delimeter.
         * @param delimiter - The value the String should be split on.
         * @return A vector of String components.
         */
        std::vector<String> split(const String &delimiter) const;

        /**
         * Inserts a String at the provided index.
         * @param string - The value to be inserted.
         * @param index - The index where the value should be inserted.
         * @return A self reference.
         */
        String &insert(const String &string, size_t index);

        /**
         * Trims the provided characters from both ends of the String.
         * @param characters - The characters that should be trimmed.
         * @return A self reference.
         */
        String &trim(const String &characters = ASCII_WHITESPACE);

        /**
         * Trims the provided characters from the beginning of the String.
         * @param characters - The characters that should be trimmed.
         * @return A self reference.
         */
        String &trimLeading(const String &characters = ASCII_WHITESPACE);

        /**
         * Trims the provided characters from the end of the String.
         * @param characters - The characters that should be trimmed.
         * @return A self reference.
         */
        String &trimTrailing(const String &characters = ASCII_WHITESPACE);

        /**
         * Reverses the order of the characters in the String.
         * @return A self reference.
         */
        String &reverse();

        /**
         * Pads both ends of the String with the provided value, the provided number of times.
         * @param string - The value to pad the String with.
         * @param count - The number of times the value should added to each end.
         * @return A self reference.
         */
        String &pad(const String &string, size_t count);

        /**
         * Pads the beginning of the String with the provided value, the provided number of times.
         * @param string - The value to pad the String with.
         * @param count - The number of times the value should be added to the beginning.
         * @return A self reference.
         */
        String &padLeft(const String &string, size_t count);

        /**
         * Pads the end of the String with the provided value, the provided number of times.
         * @param string - The value to pad the String with.
         * @param count- The number of times that value should be added to the beginning.
         * @return A self reference.
         */
        String &padRight(const String &string, size_t count);

        /**
         * Replaces the first occurrence of a value, with another value.
         * @param old_string - The current value that should be replaced.
         * @param new_string - The new value that should be set.
         * @return A self reference.
         */
        String &replace(const String &old_string, const String &new_string);
        /**
         * Replaces the last occurrence of a value, with another value.
         * @param old_string - The current value that should be replaced.
         * @param new_string - The new value that should be set.
         * @return A self reference.
         */
        String &replaceLast(const String &old_string, const String &new_string);

        /**
         * Replaces all occurrences of a value, with another value.
         * @param old_string - The current value that should be replaced.
         * @param new_string - The new value that should be set.
         * @return
         */
        String &replaceAll(const String &old_string, const String &new_string);

        /**
         * Removes the first occurrence of a value from the String.
         * @param string - The value that should be removed.
         * @return A self reference.
         */
        String &remove(const String &string);

        /**
         * Removes that last occurrence of a value from the String.
         * @param string - The value that should be removed.
         * @return A self reference.
         */
        String &removeLast(const String &string);

        /**
         * Removes all occurrences of a value from the String.
         * @param string - The value that should be removed.
         * @return A self reference.
         */
        String &removeAll(const String &string);

        /**
         * Removes a range of characters from the String.
         * @param from_index - The beginning index of the range that should be removed.
         * @param to_index - The end index of the range that should be removed.
         * @return A self reference.
         */
        String &removeRange(size_t from_index, size_t to_index);

        /**
         * Removes the provided characters from the String.
         * @param characters - The characters that should be removed.
         * @return A self reference.
         */
        String &removeCharacters(const String &characters);

        /**
         * Determines if the provided value is present in the String.
         * @param string - The value to be found.
         * @return true if the value is present in the String; false otherwise.
         */
        bool contains(const String &string) const;

        /**
         * Returns the index of the first occurrence of the provided value.
         * @param string - The value to be found.
         * @return The index of the value. -1 if not found.
         */
        size_t indexOf(const String &string) const;

        /**
         * Returns the index of the first occurrence of the provided value found after the provided index.
         * @param string - The value to be found.
         * @param min_index - The index to start search from.
         * @return The index of the value. -1 if not found.
         */
        size_t indexOf(const String &string, size_t min_index) const;

        /**
         * Returns the index of the last occurrence of the provided value.
         * @param string - The value to be found.
         * @return The index of the value. -1 if not found.
         */
        size_t indexOfLast(const String &string) const;

        /**
         * Returns the index of the last occurrence of the provided value found before the provided index.
         * @param string - The value to be found.
         * @param max_index - The index where the search should stop.
         * @return The index of the value. -1 if not found.
         */
        size_t indexOfLast(const String &string, size_t max_index) const;

        /**
         * Checks the equality of the two String objects.
         * @param string - The other String to compare this String to.
         * @param case_sensitive - Whether the compare should be case sensitive. Default = true.
         * @return true if the two String objects are equal in value; false otherwise.
         */
        bool isEqualTo(const String &string, bool case_sensitive = true) const;

        /**
         * Returns a value representing the lexicographical order of the String relative to another.
         * @param string - The value this String should be compared to.
         * @param case_sensitive - Whether the compare should be case sensitive. Default = true.
         * @return -1 if this String is lexicographically less than the other; 0 if they are equal; and 1 if
         * this String is lexicographically greater than the other.
         */
        int compare(const String &string, bool case_sensitive = true) const;

        /**
         * Returns a value representing the lexicographical order of the String relative to another.
         * @param string The value this String should be compared to.
         * @param from_index - The start index of the compare.
         * @param to_index - The end index of the compare.
         * @return -1 if this String is lexicographically less than the other; 0 if they are equal; and 1 if
         * this String is lexicographically greater than the other.
         */
        int compareOverRange(const String &string, size_t from_index, size_t to_index);

        /**
         * Get the integer value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The integer value represented in the String.
         */
        int intValue() const;

        /**
         * Get the long value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The long value represented in the String.
         */
        long longValue() const;

        /**
         * Get the long long value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The long long value represented in the String.
         */
        long long longLongValue() const;

        /**
         * Get the unsigned value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The unsigned value represented in the String.
         */
        unsigned unsignedValue() const;

        /**
         * Get the unsigned long value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The unsigned long value represented in the String.
         */
        unsigned long unsignedLongValue() const;

        /**
         * Get the unsigned long long value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The unsigned long long value represented in the String.
         */
        unsigned long long unsignedLongLongValue() const;

        /**
         * Get the float value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The float value represented in the String.
         */
        float floatValue() const;

        /**
         * Get the double value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The double value represented in the String.
         */
        double doubleValue() const;

        /**
         * Get the long double value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The long double value represented in the String.
         */
        long double longDoubleValue() const;

        /**
         * Get the bool value of the number represented in the String. An exception is thrown if the String value isn't valid.
         * @return The bool value represented in the String.
         */
        bool boolValue() const;

        /**
         * @return A new String object with the same value.
         */
        String copy() const;

        /**
         * @return The String value as a C style string.
         */
        const char *c_string() const;

        /**
         * @return The String value as a std::string.
         */
        std::string std_string() const;

        /**
         * The ASCII upper case letters: ABCDEFGHIJKLMNOPQRSTUVWXYZ
         */
        static const std::string ASCII_UPPERCASE;

        /**
         * The ASCII lower case letter: abcdefghijklmnopqrstuvwxyz
         */
        static const std::string ASCII_LOWERCASE;

        /**
         * The ASCII alphabetic letters: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
         */
        static const std::string ASCII_LETTERS;

        /**
         * The ASCII whitespace characters.
         */
        static const std::string ASCII_WHITESPACE;

        /**
         * The ASCII punctuation characters: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
         */
        static const std::string ASCII_PUNCTUATION;

        /**
         * The ASCII numeric digits: 0123456789
         */
        static const std::string ASCII_DIGITS;

        /**
         * The ASCII alphabetic letters and digits: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
         */
        static const std::string ASCII_ALPHANUMERIC;

        /**
         * The ASCII hexadecimal letters and digits: 0123456789abcdefABCDEF
         */
        static const std::string ASCII_HEX_DIGITS;

        /**
         * The ASCII octal digits: 01234567
         */
        static const std::string ASCII_OCT_DIGITS;

        /**
         * The ASCII printable characters, including whitespace: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
         */
        static const std::string ASCII_PRINTABLE;
    };
}

#endif //ABRAHAM_STRING_H
