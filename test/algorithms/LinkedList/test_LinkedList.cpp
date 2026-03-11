#include <gtest/gtest.h>

import LinkedList;

TEST(Test1, TestLinkedList) {
    CA::LinkedList<int> list;
    EXPECT_EQ(list.getSize(), 0);

    // EXPECT_EQ(CA::add(1,2), 3);
}