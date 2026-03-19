#include <gtest/gtest.h>

import DoublyLinkedList;

TEST(TestDoublyLinkedList, Test_getSize) {
    CA::DoublyLinkedList<int> list;
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_isEmpty) {
    CA::DoublyLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    
    list.append(1);
    EXPECT_FALSE(list.isEmpty());
}

TEST(TestDoublyLinkedList, Test_prepend_with_lvalue) {
    CA::DoublyLinkedList<int> list;
    int value = 42;
    list.prepend(value);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_prepend_with_rvalue) {
    CA::DoublyLinkedList<int> list;
    list.prepend(42);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_prepend_multiple) {
    CA::DoublyLinkedList<int> list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_append_with_lvalue) {
    CA::DoublyLinkedList<int> list;
    int value = 42;
    list.append(value);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_append_with_rvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_append_multiple) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_copy_constructor) {
    CA::DoublyLinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::DoublyLinkedList<int> list2(list1);

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_copy_assignment) {
    CA::DoublyLinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::DoublyLinkedList<int> list2;
    list2 = list1;

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_copy_assignment_self) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    list = list;

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_move_constructor) {
    CA::DoublyLinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::DoublyLinkedList<int> list2(std::move(list1));

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_move_assignment) {
    CA::DoublyLinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::DoublyLinkedList<int> list2;
    list2 = std::move(list1);

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_default_constructor) {
    CA::DoublyLinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_prepend_and_append_mixed) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.prepend(0);
    list.append(2);
    list.prepend(-1);

    EXPECT_EQ(list.getSize(), 4);
}

TEST(TestDoublyLinkedList, Test_copy_empty_list) {
    CA::DoublyLinkedList<int> list1;
    CA::DoublyLinkedList<int> list2(list1);

    EXPECT_EQ(list2.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_assign_empty_list) {
    CA::DoublyLinkedList<int> list1;
    list1.append(1);

    CA::DoublyLinkedList<int> list2;
    list2 = list1;

    EXPECT_EQ(list2.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_insert_at_beginning_with_lvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(2);
    list.append(3);

    int value = 1;
    list.insert(value, 0);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_at_beginning_with_rvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(2);
    list.append(3);

    list.insert(1, 0);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_at_end_with_lvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    int value = 3;
    list.insert(value, 2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_at_end_with_rvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    list.insert(3, 2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_in_middle_with_lvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(3);

    int value = 2;
    list.insert(value, 1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_in_middle_with_rvalue) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(3);

    list.insert(2, 1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_insert_index_out_of_range) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    EXPECT_THROW(list.insert(3, 5), std::out_of_range);
}

TEST(TestDoublyLinkedList, Test_remove_from_empty_list) {
    CA::DoublyLinkedList<int> list;

    list.remove(42);

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_remove_head_element) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(1);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_remove_tail_element) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(3);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_remove_middle_element) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_remove_single_element_list) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    list.remove(42);

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_remove_non_existent_element) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(99);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestDoublyLinkedList, Test_deleteTail_from_empty_list) {
    CA::DoublyLinkedList<int> list;

    auto result = list.deleteTail();

    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_deleteTail_single_element) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    auto result = list.deleteTail();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 42);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_deleteTail_multiple_elements) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.deleteTail();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 3);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_deleteHead_from_empty_list) {
    CA::DoublyLinkedList<int> list;

    auto result = list.deleteHead();

    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_deleteHead_single_element) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    auto result = list.deleteHead();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 42);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_deleteHead_multiple_elements) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.deleteHead();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_reverse_empty_list) {
    CA::DoublyLinkedList<int> list;

    list.reverse();

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestDoublyLinkedList, Test_reverse_single_element) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    list.reverse();

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestDoublyLinkedList, Test_reverse_two_elements) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    list.reverse();

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_reverse_multiple_elements) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.reverse();

    EXPECT_EQ(list.getSize(), 5);
}

TEST(TestDoublyLinkedList, Test_reverse_verifies_order) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.reverse();

    auto headNode = list.deleteHead();
    EXPECT_EQ(headNode->getData(), 3);

    auto middleNode = list.deleteHead();
    EXPECT_EQ(middleNode->getData(), 2);

    auto tailNode = list.deleteHead();
    EXPECT_EQ(tailNode->getData(), 1);
}

TEST(TestDoublyLinkedList, Test_reverse_twice_returns_original) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.reverse();
    list.reverse();

    EXPECT_EQ(list.getSize(), 4);
}

TEST(TestDoublyLinkedList, Test_find_by_value_first_occurrence) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(2);
    list.append(2);
    list.append(3);

    auto result = list.find(2);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestDoublyLinkedList, Test_find_by_value_empty_list) {
    CA::DoublyLinkedList<int> list;

    auto result = list.find(42);

    EXPECT_FALSE(result.has_value());
}

TEST(TestDoublyLinkedList, Test_find_by_value_single_element_found) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    auto result = list.find(42);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 42);
}

TEST(TestDoublyLinkedList, Test_find_by_value_single_element_not_found) {
    CA::DoublyLinkedList<int> list;
    list.append(42);

    auto result = list.find(99);

    EXPECT_FALSE(result.has_value());
}

TEST(TestDoublyLinkedList, Test_find_by_predicate_lambda_found) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    auto result = list.find([](int value) {
        return value > 3;
    });

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 4);
}

TEST(TestDoublyLinkedList, Test_find_by_predicate_lambda_not_found) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.find([](int value) {
        return value > 10;
    });

    EXPECT_FALSE(result.has_value());
}

TEST(TestDoublyLinkedList, Test_find_const_version_with_value) {
    const CA::DoublyLinkedList<int> list{[](){
        CA::DoublyLinkedList<int> l;
        l.append(1).append(2).append(3);
        return l;
    }()};

    auto result = list.find(2);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestDoublyLinkedList, Test_find_const_version_not_found) {
    const CA::DoublyLinkedList<int> list{[](){
        CA::DoublyLinkedList<int> l;
        l.append(1).append(2).append(3);
        return l;
    }()};

    auto result = list.find(99);

    EXPECT_FALSE(result.has_value());
}

TEST(TestDoublyLinkedList, Test_clear_empty_list) {
    CA::DoublyLinkedList<int> list;
    list.clear();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(TestDoublyLinkedList, Test_clear_with_elements) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.clear();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(TestDoublyLinkedList, Test_clear_and_repopulate) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);

    list.clear();
    list.append(10);
    list.append(20);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestDoublyLinkedList, Test_bidirectional_links) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto node2Ref = list.find(2);
    ASSERT_TRUE(node2Ref.has_value());
    
    auto& node2 = node2Ref->get();
    auto& prev = node2.getPrevious();
    auto& next = node2.getNext();
    
    EXPECT_TRUE(prev != nullptr);
    EXPECT_TRUE(next != nullptr);
    EXPECT_EQ(prev->getData(), 1);
    EXPECT_EQ(next->getData(), 3);
}

TEST(TestDoublyLinkedList, Test_previous_pointer_head) {
    CA::DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto headNode = list.deleteHead();
    EXPECT_EQ(headNode->getData(), 1);
    
    auto newHeadNode = list.deleteHead();
    EXPECT_EQ(newHeadNode->getData(), 2);
}

TEST(TestDoublyLinkedList, Test_string_type) {
    CA::DoublyLinkedList<std::string> list;
    list.append("hello");
    list.append("world");

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.find("hello")->get().getData(), "hello");
    EXPECT_EQ(list.find("world")->get().getData(), "world");
}

TEST(TestDoublyLinkedList, Test_chain_operations) {
    CA::DoublyLinkedList<int> list;
    list.append(1).append(2).prepend(0).insert(3, 3);

    EXPECT_EQ(list.getSize(), 4);
    EXPECT_EQ(list.find(0)->get().getData(), 0);
    EXPECT_EQ(list.find(3)->get().getData(), 3);
}
