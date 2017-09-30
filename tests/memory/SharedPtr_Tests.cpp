//
// Created by Matthew Remmel on 9/29/17.
//

#include "gtest/gtest.h"
#include "SharedPtr.hpp"

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

TEST(SharedPtr, default_constructor) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>();

    // Assertion
    EXPECT_TRUE(ptr.isEmpty());
}

TEST(SharedPtr, pointer_constructor) {
    // Setup
    SharedPtr<int> empty = SharedPtr<int>(nullptr);
    SharedPtr<int> ptr = SharedPtr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

TEST(SharedPtr, std_constructor) {
    // Setup
    SharedPtr<int> empty = std::shared_ptr<int>();
    SharedPtr<int> ptr = std::shared_ptr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

// Destructor

TEST(SharedPtr, resource_release) {
    // Setup
    int i = 0;
    {
        SharedPtr<RunAtDelete> ptr = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    }

    // Assertion
    EXPECT_EQ(10, i);
}

TEST(SharedPtr, no_resource_release) {
    // Setup
    int i = 0;
    SharedPtr<RunAtDelete> ptr1 = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    {
        SharedPtr<RunAtDelete> ptr2 = ptr1;
    }

    // Assertion
    EXPECT_EQ(0, i);
}

// Operator=

TEST(SharedPtr, null_assignment) {
    // Setup
    int i = 0;
    SharedPtr<RunAtDelete> ptr = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr = nullptr;

    // Assertion
    EXPECT_EQ(10, i);
}

// Operator==

TEST(SharedPtr, operator_equality) {
    // Setup
    SharedPtr<int> ptr1 = SharedPtr<int>(new int());
    SharedPtr<int> ptr2 = ptr1;
    SharedPtr<int> ptr3 = SharedPtr<int>();

    // Assertion
    EXPECT_TRUE(ptr1 == ptr2);
    EXPECT_FALSE(ptr1 == ptr3);
}

// Operator!=

TEST(SharedPtr, operator_inequality) {
    // Setup
    SharedPtr<int> ptr1 = SharedPtr<int>(new int());
    SharedPtr<int> ptr2 = SharedPtr<int>();

    // Assertion
    EXPECT_TRUE(ptr1 != ptr2);
    EXPECT_FALSE(ptr1 != ptr1);
}

// Operator Bool

TEST(SharedPtr, operator_bool) {
    // Setup
    SharedPtr<int> ptr1 = SharedPtr<int>();
    SharedPtr<int> ptr2 = SharedPtr<int>(new int());
    int n1 = 0;
    int n2 = 0;

    if (ptr1) n1 = 10;
    if (ptr2) n2 = 10;

    // Assertion
    EXPECT_EQ(0, n1);
    EXPECT_EQ(10, n2);
}

// Operator*

TEST(SharedPtr, operator_deref_star) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>(new int(10));

    // Assertion
    EXPECT_EQ(10, *ptr);
}

// Operator->

TEST(SharedPtr, operator_deref_arrow) {
    // Setup
    SharedPtr<std::shared_ptr<int>> ptr = SharedPtr<std::shared_ptr<int>>(new std::shared_ptr<int>(new int(10)));

    // Assertion
    EXPECT_EQ(10, *(ptr->get()));
}

// Make Default

TEST(SharedPtr, make_default) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>::make();

    // Assertion
    EXPECT_FALSE(ptr.isEmpty());
}

TEST(SharedPtr, make_args) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>::make(10);

    // Assertion
    EXPECT_FALSE(ptr.isEmpty());
    EXPECT_EQ(10, *ptr);
}

// Get

TEST(SharedPtr, get) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>(new int(10));

    // Assertion
    EXPECT_EQ(10, *(ptr.get()));
}

// Set

TEST(SharedPtr, set_pointer) {
    // Setup
    int i = 0;
    SharedPtr<RunAtDelete> ptr = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    RunAtDelete* rad = new RunAtDelete([](){});
    ptr.set(rad);

    // Assertion
    EXPECT_EQ(rad, ptr.get());
    EXPECT_EQ(10, i);
}

TEST(SharedPtr, set_null) {
    // Setup
    int i = 0;
    SharedPtr<RunAtDelete> ptr = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr.set(nullptr);

    // Assertion
    EXPECT_EQ(nullptr, ptr.get());
    EXPECT_EQ(10, i);
}

// Reset

TEST(SharedPtr, reset) {
    // Setup
    int i = 0;
    SharedPtr<RunAtDelete> ptr = SharedPtr<RunAtDelete>(new RunAtDelete([&i]() {i = 10;}));
    ptr.reset();

    // Assertion
    EXPECT_EQ(nullptr, ptr.get());
    EXPECT_EQ(10, i);
}

// IsEmpty

TEST(SharedPtr, is_empty) {
    // Setup
    SharedPtr<int> empty = SharedPtr<int>(nullptr);
    SharedPtr<int> ptr = SharedPtr<int>(new int());

    // Assertion
    EXPECT_TRUE(empty.isEmpty());
    EXPECT_FALSE(ptr.isEmpty());
}

// StdSharedPtr

TEST(SharedPtr, std_shared_ptr) {
    // Setup
    SharedPtr<int> ptr = SharedPtr<int>(new int(10));
    std::shared_ptr<int> std = ptr.std_shared_ptr();

    // Assertion
    EXPECT_EQ(10, *std);
    EXPECT_EQ(10, *ptr);
}