//
// Created by Matthew Remmel on 9/1/17.
//

#include "abraham/container/Strings.h"
#include "abraham/core/Exception.h"

using namespace abraham;


String::String() {
    this->_data = "";
}

String::String(char character) {
    this->_data = character;
}

String::String(const char *cstring) {
    this->_data = cstring;
}

String::String(const std::string &string) {
    this->_data = string;
}

String::String(const String &string) {
    this->_data = string._data;
}

char &String::operator[](size_t index) {
    if (index < this->_data.length()) {
        return this->_data[index];
    } else {
        throw OutOfBoundsException(index);
    }
}

String &String::operator=(const String &string) {
    if (this == &string) return *this;
    this->_data = string._data;
    return *this;
}

const String String::operator+(const String &string) const {
    return String(this->_data + string._data);
}

String &String::operator+=(const String &string) {
    this->_data += string._data;
    return *this;
}

bool String::operator==(const String &string) const {
    if (this == &string) return true;
    return this->_data == string._data;
}

bool String::operator!=(const String &string) const {
    if (this == &string) return false;
    return this->_data != string._data;
}

bool String::operator<(const String &string) const {
    if (this == &string) return false;
    return this->_data < string._data;
}

bool String::operator>(const String &string) const {
    if (this == &string) return false;
    return this->_data > string._data;
}

bool String::operator<=(const String &string) const {
    if (this == &string) return true;
    return this->_data <= string._data;
}

bool String::operator>=(const String &string) const {
    if (this == &string) return true;
    return this->_data >= string._data;
}

size_t String::length() const {
    return this->_data.length();
}

char String::characterAtIndex(size_t index) const {
    if (index < this->_data.length()) {
        return this->_data[index];
    } else {
        throw OutOfBoundsException(index);
    }
}

String &String::setCharacterAtIndex(const char c, size_t index) {
    if (index < this->_data.length()) {
        this->_data[index] = c;
    } else {
        throw OutOfBoundsException(index);
    }
}

String &String::setValue(const String &string) {
    this->_data = string._data;
    return *this;
}

String &String::toLowerCase() {
    for (char &c : this->_data) {
        c = (char) tolower(c);
    }
    return *this;
}

String &String::toUpperCase() {
    for (char &c : this->_data) {
        c = (char) toupper(c);
    }
    return *this;
}

String &String::toCapitalCase() {
    this->_data[0] = (char) toupper(this->_data[0]);
    for (size_t i = 1; i < this->_data.length(); ++i) {
        if (this->_data[i - 1] == ' ') {
            this->_data[i] = (char) toupper(this->_data[i]);
        }
    }
    return *this;
}

String &String::swapCase() {
    for (char &c : this->_data) {
        if (islower(c)) {
            c = (char) toupper(c);
        } else if (isupper(c)) {
            c = (char) tolower(c);
        }
    }
    return *this;
}

String &String::append(const String &string) {
    this->_data.append(string._data);
    return *this;
}

String String::substring(size_t from_index, size_t to_index) const {
    if (from_index > to_index) throw InvalidArgumentException("from_index must be less than to_index");
    if (to_index < this->_data.length()) {
        return this->_data.substr(from_index, to_index - from_index);
    }
    else {
        throw OutOfBoundsException(to_index);
    }
}

String String::substringFromIndex(size_t index) const {
    if (index < this->_data.length()) {
        return this->_data.substr(index);
    }
    else {
        throw OutOfBoundsException(index);
    }
}

String String::substringToIndex(size_t index) const {
    if (index < this->_data.length()) {
        return this->_data.substr(0, index);
    }
    else {
        throw OutOfBoundsException(index);
    }
}

std::vector<String> String::split(const String &delimiter) const {
    std::vector<String> output;
    size_t delim_length = delimiter._data.length();

    if (delim_length == 0) {
        for (const char c : this->_data) {
            output.emplace_back(c);
        }

        return output;
    }

    size_t element_begin = 0;
    size_t element_end = 0;

    while ((element_end = this->_data.find(delimiter.std_string(), element_end)) != NO_INDEX) {
        output.emplace_back(this->_data.substr(element_begin, element_end - element_begin));
        element_end += delim_length;
        element_begin = element_end;
    }

    output.emplace_back(this->_data.substr(element_begin, this->_data.length() - element_begin));

    return output;
}

String &String::insert(const String &string, size_t index) {
    if (index < this->_data.length()) {
        this->_data.insert(index, string.std_string());
        return *this;
    }
    else {
        throw OutOfBoundsException(index);
    }
}

String &String::trim(const String &characters) {
    this->trimLeading(characters);
    this->trimTrailing(characters);
    return *this;
}

String &String::trimLeading(const String &characters) {
    this->_data.erase(0, this->_data.find_first_not_of(characters.c_string()));
    return *this;
}

String &String::trimTrailing(const String &characters) {
    size_t last_not_of = this->_data.find_last_not_of(characters.c_string()) + 1;
    this->_data.erase(last_not_of, this->_data.length() - last_not_of);
    return *this;
}

String &String::reverse() {
    std::string buffer = "";

    for (size_t i = this->_data.length(); i > 0; --i) {
        buffer += this->_data[i - 1];
    }
    this->_data = buffer;

    return *this;
}

String &String::pad(const String &string, size_t count) {
    this->padLeft(string, count);
    this->padRight(string, count);
    return *this;
}

String &String::padLeft(const String &string, size_t count) {
    std::string pad_string = "";

    for (size_t i = 0; i < count; ++i) {
        pad_string += string._data;
    }
    this->_data.insert(0, pad_string);

    return *this;
}

String &String::padRight(const String &string, size_t count) {
    std::string pad_string = "";

    for (size_t i = 0; i < count; ++i) {
        pad_string += string._data;
    }
    this->_data.insert(this->_data.length(), pad_string);

    return *this;
}

String &String::replace(const String &old_string, const String &new_string) {
    size_t target_length = old_string._data.length();
    size_t target_index = this->_data.find(old_string._data);

    if (target_index != NO_INDEX) {
        this->_data.replace(target_index, target_length, new_string._data);
    }

    return *this;
}

String &String::replaceLast(const String &old_string, const String &new_string) {
    size_t target_length = old_string._data.length();
    size_t target_index = this->_data.rfind(old_string._data);

    if (target_index != NO_INDEX) {
        this->_data.replace(target_index, target_length, new_string._data);
    }

    return *this;
}

String &String::replaceAll(const String &old_string, const String &new_string) {
    size_t target_length = old_string._data.length();
    size_t target_index = 0;

    while ((target_index = this->_data.find(old_string._data, target_index)) != NO_INDEX) {
        this->_data.replace(target_index, target_length, new_string._data);
    }

    return *this;
}

String &String::remove(const String &string) {
    size_t target_length = string._data.length();
    size_t target_index = this->_data.find(string._data);

    if (target_index != NO_INDEX) {
        this->_data.erase(target_index, target_length);
    }

    return *this;
}

String &String::removeLast(const String &string) {
    size_t target_length = string._data.length();
    size_t target_index = this->_data.rfind(string._data);

    if (target_index != NO_INDEX) {
        this->_data.erase(target_index, target_length);
    }

    return *this;
}

String &String::removeAll(const String &string) {
    size_t target_length = string._data.length();
    size_t target_index = 0;

    while ((target_index = this->_data.find(string._data, target_index)) != NO_INDEX) {
        this->_data.erase(target_index, target_length);
    }

    return *this;
}

String &String::removeRange(size_t from_index, size_t to_index) {
    if (from_index > to_index) throw InvalidArgumentException("from_index must be less than to_index");
    if (from_index < this->_data.length() && to_index < this->_data.length()) {
        this->_data.erase(from_index, to_index - from_index);
        return *this;
    }
    else {
        throw OutOfBoundsException(to_index);
    }
}

String &String::removeCharacters(const String &characters) {
    std::string buffer = "";

    for (size_t i = 0; i < this->_data.length(); ++i) {
        if (!characters.contains(this->_data[i])) {
            buffer += this->_data[i];
        }
    }
    this->_data = buffer;

    return *this;
}

bool String::contains(const String &string) const {
    size_t index = this->_data.find(string.std_string());
    return index != NO_INDEX;
}

size_t String::indexOf(const String &string) const {
    return this->_data.find(string._data);
}

size_t String::indexOf(const String &string, size_t min_index) const {
    return this->_data.find(string._data, min_index);
}

size_t String::indexOfLast(const String &string) const {
    return this->_data.rfind(string._data);
}

size_t String::indexOfLast(const String &string, size_t max_index) const {
    return this->_data.rfind(string._data, max_index);
}

bool String::isEqualTo(const String &string, bool case_sensitive) const {
    if (case_sensitive) {
        return this->_data == string._data;
    }

    size_t length = this->_data.length();

    if (string._data.length() != length) {
        return false;
    }

    for (size_t i = 0; i < length; ++i) {
        if (tolower(this->_data[i]) != tolower(string._data[i])) {
            return false;
        }
    }

    return true;
}

int String::compare(const String &string, bool case_sensitive) const {
    if (case_sensitive) {
        return this->_data.compare(string._data);
    }

    // This could be broken out and optimized a little
    return this->copy().toLowerCase()._data.compare(string.copy().toLowerCase()._data);
}

int String::compareOverRange(const String &string, size_t from_index, size_t to_index, bool case_sensitive) {
    // Check that both are valid ranges
    if (to_index >= this->_data.length() || to_index >= string._data.length()) {
        throw OutOfBoundsException(to_index);
    }

    String s1 = this->_data.substr(from_index, to_index);
    String s2 = string._data.substr(from_index, to_index);

    if (case_sensitive) {
        return s1.compare(s2);
    }
    else {
        s1.toLowerCase().compare(s2.toLowerCase());
    }
}

int String::intValue() const {
    try {
        return std::stoi(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to int: " + this->_data);
    }
}

long String::longValue() const {
    try {
        return std::stol(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to long: " + this->_data);
    }
}

long long String::longLongValue() const {
    try {
        return std::stoll(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to long long: " + this->_data);
    }
}

unsigned String::unsignedValue() const {
    try {
        return std::stoul(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to unsigned: " + this->_data);
    }
}

unsigned long String::unsignedLongValue() const {
    try {
        return std::stoul(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to unsigned long: " + this->_data);
    }
}

unsigned long long String::unsignedLongLongValue() const {
    try {
        return std::stoull(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to unsigned long long: " + this->_data);
    }
}

float String::floatValue() const {
    try {
        return std::stof(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to float: " + this->_data);
    }
}

double String::doubleValue() const {
    try {
        return std::stod(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to double: " + this->_data);
    }
}

long double String::longDoubleValue() const {
    try {
        return std::stold(this->_data);
    }
    catch (std::exception &e) {
        throw InvalidValueException("Value could not be converted to long double: " + this->_data);
    }
}

bool String::boolValue() const {
    String value = this->copy().toLowerCase();

    if (value == "false") return false;
    if (value == "true")  return true;
    if (value == "no")    return false;
    if (value == "yes")   return true;
    if (value == "n")     return false;
    if (value == "y")     return true;
    if (value == "0")     return false;
    if (value == "1")     return true;

    throw InvalidValueException("Value could not be converted to bool: " + this->_data);
}

String String::copy() const {
    return String(this->_data);
}

const char *String::c_string() const {
    return this->_data.c_str();
}

std::string String::std_string() const {
    return this->_data;
}

const size_t String::NO_INDEX = -1;
const std::string String::ASCII_UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string String::ASCII_LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const std::string String::ASCII_LETTERS = ASCII_UPPERCASE + ASCII_LOWERCASE;
const std::string String::ASCII_WHITESPACE = " \t\r\n\v\f";
const std::string String::ASCII_PUNCTUATION = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const std::string String::ASCII_DIGITS = "0123456789";
const std::string String::ASCII_ALPHANUMERIC = ASCII_UPPERCASE + ASCII_LOWERCASE + ASCII_DIGITS;
const std::string String::ASCII_HEX_DIGITS = "0123456789abcdefABCDEF";
const std::string String::ASCII_OCT_DIGITS = "01234567";
const std::string String::ASCII_PRINTABLE = ASCII_LETTERS + ASCII_DIGITS + ASCII_PUNCTUATION + ASCII_WHITESPACE;
