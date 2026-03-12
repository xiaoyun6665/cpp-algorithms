#include <gtest/gtest.h>

import LinkedList;

TEST(TestLinkedList, Test_getSize) {
    CA::LinkedList<int> list;
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_prepend_with_lvalue) {
    CA::LinkedList<int> list;
    int value = 42;
    list.prepend(value);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_prepend_with_rvalue) {
    CA::LinkedList<int> list;
    list.prepend(42);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_prepend_multiple) {
    CA::LinkedList<int> list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_append_with_lvalue) {
    CA::LinkedList<int> list;
    int value = 42;
    list.append(value);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_append_with_rvalue) {
    CA::LinkedList<int> list;
    list.append(42);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_append_multiple) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_copy_constructor) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(list1);

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestLinkedList, Test_copy_assignment) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2;
    list2 = list1;

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestLinkedList, Test_copy_assignment_self) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list = list;

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_move_constructor) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestLinkedList, Test_move_assignment) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2;
    list2 = std::move(list1);

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestLinkedList, Test_default_constructor) {
    CA::LinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_prepend_and_append_mixed) {
    CA::LinkedList<int> list;
    list.append(1);
    list.prepend(0);
    list.append(2);
    list.prepend(-1);

    EXPECT_EQ(list.getSize(), 4);
}

TEST(TestLinkedList, Test_copy_empty_list) {
    CA::LinkedList<int> list1;
    CA::LinkedList<int> list2(list1);

    EXPECT_EQ(list2.getSize(), 0);
}

TEST(TestLinkedList, Test_assign_empty_list) {
    CA::LinkedList<int> list1;
    list1.append(1);

    CA::LinkedList<int> list2;
    list2 = list1;

    EXPECT_EQ(list2.getSize(), 1);
}

TEST(TestLinkedList, Test_insert_at_beginning_with_lvalue) {
    CA::LinkedList<int> list;
    list.append(2);
    list.append(3);

    int value = 1;
    list.insert(value, 0);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_at_beginning_with_rvalue) {
    CA::LinkedList<int> list;
    list.append(2);
    list.append(3);

    list.insert(1, 0);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_at_end_with_lvalue) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    int value = 3;
    list.insert(value, 2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_at_end_with_rvalue) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.insert(3, 2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_in_middle_with_lvalue) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(3);

    int value = 2;
    list.insert(value, 1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_in_middle_with_rvalue) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(3);

    list.insert(2, 1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_in_middle_multiple_positions) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(5);

    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);

    EXPECT_EQ(list.getSize(), 5);
}

TEST(TestLinkedList, Test_insert_on_empty_list_at_zero) {
    CA::LinkedList<int> list;

    list.insert(42, 0);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_insert_index_out_of_range) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    EXPECT_THROW(list.insert(3, 5), std::out_of_range);
}

TEST(TestLinkedList, Test_insert_index_equal_to_size) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.insert(3, 2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_insert_index_one_before_size) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(4);

    list.insert(3, 2);

    EXPECT_EQ(list.getSize(), 4);
}

TEST(TestLinkedList, Test_insert_negative_index) {
    CA::LinkedList<int> list;
    list.append(1);

    // size_t is unsigned, so -1 becomes a very large number
    // This should throw out_of_range
    EXPECT_THROW(list.insert(2, -1), std::out_of_range);
}

TEST(TestLinkedList, Test_insert_large_index) {
    CA::LinkedList<int> list;
    list.append(1);

    // Insert at a very large index (should throw)
    EXPECT_THROW(list.insert(2, SIZE_MAX), std::out_of_range);
}
