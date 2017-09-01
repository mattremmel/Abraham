//
// Created by Matthew Remmel on 9/1/17.
//

#include "Strings.h"
#include "Exception.h"

using namespace abraham;

String::String() {
    throw NotImplementedException();
}

String::String(char character) {
    throw NotImplementedException();
}

String::String(const char *cstring) {
    throw NotImplementedException();
}

String::String(const std::string &string) {
    throw NotImplementedException();
}

String::String(const String &string) {
    throw NotImplementedException();
}

char &String::operator[](size_t index) {
    throw NotImplementedException();
}

String &String::operator=(const String &string) {
    throw NotImplementedException();
}

const String String::operator+(const String &string) const {
    throw NotImplementedException();
}

String &String::operator+=(const String &string) {
    throw NotImplementedException();
}

bool String::operator==(const String &string) const {
    throw NotImplementedException();
}

bool String::operator!=(const String &string) const {
    throw NotImplementedException();
}

bool String::operator<(const String &string) const {
    throw NotImplementedException();
}

bool String::operator>(const String &string) const {
    throw NotImplementedException();
}

bool String::operator<=(const String &string) const {
    throw NotImplementedException();
}

bool String::operator>=(const String &string) const {
    throw NotImplementedException();
}

size_t String::length() const {
    throw NotImplementedException();
}

char String::characterAtIndex(size_t index) const {
    throw NotImplementedException();
}

String &String::setCharacterAtIndex(const char c, size_t index) {
    throw NotImplementedException();
}

String &String::toLowerCase() {
    throw NotImplementedException();
}

String &String::toUpperCase() {
    throw NotImplementedException();
}

String &String::toCapitalCase() {
    throw NotImplementedException();
}

String &String::swapCase() {
    throw NotImplementedException();
}

String &String::append(const String &string) {
    throw NotImplementedException();
}

String String::substring(size_t from_index, size_t to_index) const {
    throw NotImplementedException();
}

String String::substringFromIndex(size_t index) const {
    throw NotImplementedException();
}

String String::substringToIndex(size_t index) const {
    throw NotImplementedException();
}

std::vector<String> String::split(const String &delimiter) const {
    throw NotImplementedException();
}

String &String::insert(const String &string, size_t index) {
    throw NotImplementedException();
}

String &String::trim(const String &characters) {
    throw NotImplementedException();
}

String &String::trimLeading(const String &characters) {
    throw NotImplementedException();
}

String &String::trimTrailing(const String &characters) {
    throw NotImplementedException();
}

String &String::reverse() {
    throw NotImplementedException();
}

String &String::pad(const String &string, size_t count) {
    throw NotImplementedException();
}

String &String::padLeft(const String &string, size_t count) {
    throw NotImplementedException();
}

String &String::padRight(const String &string, size_t count) {
    throw NotImplementedException();
}

String &String::replace(const String &old_string, const String &new_string) {
    throw NotImplementedException();
}

String &String::replaceLast(const String &old_string, const String &new_string) {
    throw NotImplementedException();
}

String &String::replaceAll(const String &old_string, const String &new_string) {
    throw NotImplementedException();
}

String &String::remove(const String &string) {
    throw NotImplementedException();
}

String &String::removeLast(const String &string) {
    throw NotImplementedException();
}

String &String::removeAll(const String &string) {
    throw NotImplementedException();
}

String &String::removeRange(size_t from_index, size_t to_index) {
    throw NotImplementedException();
}

String &String::removeCharacters(const String &characters) {
    throw NotImplementedException();
}

bool String::contains(const String &string) const {
    throw NotImplementedException();
}

size_t String::indexOf(const String &string) const {
    throw NotImplementedException();
}

size_t String::indexOf(const String &string, size_t min_index) const {
    throw NotImplementedException();
}

size_t String::indexOfLast(const String &string) const {
    throw NotImplementedException();
}

size_t String::indexOfLast(const String &string, size_t max_index) const {
    throw NotImplementedException();
}

bool String::isEqualTo(const String &string, bool case_sensitive) const {
    throw NotImplementedException();
}

int String::compare(const String &string, bool case_sensitive) const {
    throw NotImplementedException();
}

int String::compareOverRange(const String &string, size_t from_index, size_t to_index) {
    throw NotImplementedException();
}

int String::intValue() const {
    throw NotImplementedException();
}

long String::longValue() const {
    throw NotImplementedException();
}

long long String::longLongValue() const {
    throw NotImplementedException();
}

unsigned String::unsignedValue() const {
    throw NotImplementedException();
}

unsigned long String::unsignedLongValue() const {
    throw NotImplementedException();
}

unsigned long long String::unsignedLongLongValue() const {
    throw NotImplementedException();
}

float String::floatValue() const {
    throw NotImplementedException();
}

double String::doubleValue() const {
    throw NotImplementedException();
}

long double String::longDoubleValue() const {
    throw NotImplementedException();
}

bool String::boolValue() const {
    throw NotImplementedException();
}

String String::copy() const {
    throw NotImplementedException();
}

const char *String::c_string() const {
    throw NotImplementedException();
}

std::string String::std_string() const {
    throw NotImplementedException();
}