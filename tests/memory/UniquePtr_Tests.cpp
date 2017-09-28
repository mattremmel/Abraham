//
// Created by Matthew Remmel on 9/26/17.
//

#include "gtest/gtest.h"
#include "UniquePtr.hpp"

using namespace abraham;


// Helper class for checking if an object was deallocated
class RunAtDelete {
private:
    std::function<void(void)> _target;

public:
    explicit RunAtDelete(std::function<void(void)> target) { _target = target; };
    ~RunAtDelete() {_target();};
};


// Constructor

TEST(UniquePtr, default_constructor) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>();

    // Assertion
    EXPECT_TRUE(ptr.isEmpty());
}

TEST(UniquePtr, pointer_constructor) {
    // Setup
    UniquePtr<int> empty = UniquePtr<int>(nullptr);
    UniquePtr<int> ptr = UniquePtr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

TEST(UniquePtr, std_constructor) {
    // Setup
    UniquePtr<int> empty = std::unique_ptr<int>();
    UniquePtr<int> ptr = std::unique_ptr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

// Destructor

TEST(UniquePtr, resource_release) {
    // Setup
    int i = 0;
    {
        UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    }

    // Assertion
    EXPECT_EQ(10, i);
}

// Operator=

TEST(UniquePtr, null_assignment) {
    // Setup
    int i = 0;
    UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr = nullptr;

    // Assertion
    EXPECT_EQ(10, i);
}

// Operator==

TEST(UniquePtr, operator_equality) {
    // Setup
    int* i = new int();
    UniquePtr<int> ptr1 = UniquePtr<int>(i);
    UniquePtr<int> ptr2 = UniquePtr<int>(i);
    UniquePtr<int> ptr3 = UniquePtr<int>(new int());

    // Assertion
    EXPECT_TRUE(ptr1 == ptr2);
    EXPECT_FALSE(ptr1 == ptr3);

    // Cleanup
    ptr1.release();
    ptr2 = nullptr;
}

// Operator!=

TEST(UniquePtr, operator_inequality) {
    // Setup
    UniquePtr<int> ptr1 = UniquePtr<int>(new int());
    UniquePtr<int> ptr2 = UniquePtr<int>(new int());

    // Assertion
    EXPECT_TRUE(ptr1 != ptr2);
    EXPECT_FALSE(ptr1 != ptr1);
}

// Operator Bool

TEST(UniquePtr, operator_bool) {
    // Setup
    UniquePtr<int> ptr1 = UniquePtr<int>();
    UniquePtr<int> ptr2 = UniquePtr<int>(new int());
    int n1 = 0;
    int n2 = 0;

    if (ptr1) n1 = 10;
    if (ptr2) n2 = 10;

    // Assertion
    EXPECT_EQ(0, n1);
    EXPECT_EQ(10, n2);
}

// Operator*

TEST(UniquePtr, operator_deref_star) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>(new int(10));

    // Assertion
    EXPECT_EQ(10, *ptr);
}

// Operator->

TEST(UniquePtr, operator_deref_arrow) {
    // Setup
    UniquePtr<std::unique_ptr<int>> ptr = UniquePtr<std::unique_ptr<int>>(new std::unique_ptr<int>(new int(10)));

    // Assertion
    EXPECT_EQ(10, *(ptr->get()));
}

// Make Default

TEST(UniquePtr, make_default) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>::make();

    // Assertion
    EXPECT_FALSE(ptr.isEmpty());
}

// Make Args

TEST(UniquePtr, make_args) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>::make(10);

    // Assertion
    EXPECT_FALSE(ptr.isEmpty());
    EXPECT_EQ(10, *ptr);
}

// Get

TEST(UniquePtr, get) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>(new int(10));

    // Assertion
    EXPECT_EQ(10, *(ptr.get()));
}

// Set

TEST(UniquePtr, set_pointer) {
    // Setup
    int i = 0;
    UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    RunAtDelete* rad = new RunAtDelete([](){});
    ptr.set(rad);

    // Assertion
    EXPECT_EQ(rad, ptr.get());
    EXPECT_EQ(10, i);
}

TEST(UniquePtr, set_null) {
    // Setup
    int i = 0;
    UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr.set(nullptr);

    // Assertion
    EXPECT_EQ(nullptr, ptr.get());
    EXPECT_EQ(10, i);
}

// Reset

TEST(UniquePtr, reset) {
    // Setup
    int i = 0;
    UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr.reset();

    // Assertion
    EXPECT_EQ(nullptr, ptr.get());
    EXPECT_EQ(10, i);
}

// Release

TEST(UniquePtr, release) {
    // Setup
    int i = 0;
    UniquePtr<RunAtDelete> ptr = UniquePtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    RunAtDelete* raw = ptr.release();

    // Assertion
    EXPECT_EQ(nullptr, ptr.get());
    EXPECT_EQ(0, i);

    // Cleanup
    delete(raw);
}

// IsEmpty

TEST(UniquePtr, is_empty) {
    // Setup
    UniquePtr<int> empty = UniquePtr<int>(nullptr);
    UniquePtr<int> ptr = UniquePtr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

// StdUniquePtr

TEST(UniquePtr, std_unique_ptr) {
    // Setup
    UniquePtr<int> ptr = UniquePtr<int>(new int(10));
    std::unique_ptr<int> std = ptr.std_unique_ptr();

    // Assertion
    EXPECT_EQ(10, *std);
    EXPECT_EQ(nullptr, ptr.get());
}
