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

TEST(TestLinkedList, Test_remove_from_empty_list) {
    CA::LinkedList<int> list;

    list.remove(42);

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_remove_head_element) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(1);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_tail_element) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(3);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_middle_element) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_single_element_list) {
    CA::LinkedList<int> list;
    list.append(42);

    list.remove(42);

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.getSize() == 0);
}

TEST(TestLinkedList, Test_remove_non_existent_element) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(99);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_remove_first_occurrence_duplicate_values) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(2);
    list.append(3);

    list.remove(2);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_remove_all_elements_one_by_one) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);
    list.remove(1);
    list.remove(3);

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_remove_with_method_chaining) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.remove(2).remove(4);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_after_prepend) {
    CA::LinkedList<int> list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    list.remove(2);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_preserves_tail_pointer) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(3);

    EXPECT_EQ(list.getSize(), 2);
    list.remove(2);
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_remove_from_copied_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2 = list1;
    list2.remove(2);

    EXPECT_EQ(list2.getSize(), 2);
    EXPECT_EQ(list1.getSize(), 3);
}

TEST(TestLinkedList, Test_remove_from_moved_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));
    list2.remove(2);

    EXPECT_EQ(list2.getSize(), 2);
}

TEST(TestLinkedList, Test_remove_consecutive_duplicates) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(1);
    list.append(1);
    list.append(2);

    list.remove(1);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_remove_only_element_then_append_again) {
    CA::LinkedList<int> list;
    list.append(10);
    list.remove(10);
    list.append(20);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteTail_from_empty_list) {
    CA::LinkedList<int> list;

    auto result = list.deleteTail();

    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteTail_single_element) {
    CA::LinkedList<int> list;
    list.append(42);

    auto result = list.deleteTail();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 42);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteTail_multiple_elements) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.deleteTail();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 3);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteTail_all_elements_one_by_one) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto node1 = list.deleteTail();
    EXPECT_EQ(node1->getData(), 3);
    EXPECT_EQ(list.getSize(), 2);

    auto node2 = list.deleteTail();
    EXPECT_EQ(node2->getData(), 2);
    EXPECT_EQ(list.getSize(), 1);

    auto node3 = list.deleteTail();
    EXPECT_EQ(node3->getData(), 1);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteTail_after_prepend_operations) {
    CA::LinkedList<int> list;
    list.prepend(1);
    list.prepend(2);
    list.prepend(3);

    auto result = list.deleteTail();

    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteTail_preserves_head_after_deletion) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.deleteTail();

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_NE(list.deleteTail(), nullptr);
}

TEST(TestLinkedList, Test_deleteTail_updates_tail_correctly) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.deleteTail();
    list.deleteTail();

    EXPECT_EQ(list.getSize(), 1);
    auto lastNode = list.deleteTail();
    EXPECT_EQ(lastNode->getData(), 1);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteTail_with_string_type) {
    CA::LinkedList<std::string> list;
    list.append("hello");
    list.append("world");

    auto result = list.deleteTail();

    EXPECT_EQ(result->getData(), "world");
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteTail_from_copied_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(list1);

    auto result = list2.deleteTail();

    EXPECT_EQ(result->getData(), 3);
    EXPECT_EQ(list2.getSize(), 2);
    EXPECT_EQ(list1.getSize(), 3);
}

TEST(TestLinkedList, Test_deleteTail_from_moved_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));

    auto result = list2.deleteTail();

    EXPECT_EQ(result->getData(), 3);
    EXPECT_EQ(list2.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteTail_interleaved_with_append) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.deleteTail()->getData(), 2);

    list.append(3);
    EXPECT_EQ(list.deleteTail()->getData(), 3);

    list.append(4);
    EXPECT_EQ(list.deleteTail()->getData(), 4);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteTail_empty_then_repopulate) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.deleteTail();
    list.deleteTail();

    EXPECT_EQ(list.getSize(), 0);

    list.append(10);
    EXPECT_EQ(list.getSize(), 1);
    auto result = list.deleteTail();
    EXPECT_EQ(result->getData(), 10);
}

TEST(TestLinkedList, Test_deleteTail_node_ownership_transfer) {
    CA::LinkedList<int> list;
    list.append(100);
    list.append(200);

    auto deletedNode = list.deleteTail();

    EXPECT_NE(deletedNode, nullptr);
    EXPECT_EQ(deletedNode->getData(), 200);

    deletedNode.reset();
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteTail_mixed_with_remove) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);
    auto tailNode = list.deleteTail();

    EXPECT_EQ(tailNode->getData(), 3);
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_from_empty_list) {
    CA::LinkedList<int> list;

    auto result = list.deleteHead();

    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteHead_single_element) {
    CA::LinkedList<int> list;
    list.append(42);

    auto result = list.deleteHead();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 42);
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.deleteHead(), nullptr);
}

TEST(TestLinkedList, Test_deleteHead_multiple_elements) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.deleteHead();

    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteHead_all_elements_one_by_one) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto node1 = list.deleteHead();
    EXPECT_EQ(node1->getData(), 1);
    EXPECT_EQ(list.getSize(), 2);

    auto node2 = list.deleteHead();
    EXPECT_EQ(node2->getData(), 2);
    EXPECT_EQ(list.getSize(), 1);

    auto node3 = list.deleteHead();
    EXPECT_EQ(node3->getData(), 3);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteHead_after_prepend_operations) {
    CA::LinkedList<int> list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    auto result = list.deleteHead();

    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteHead_preserves_tail_after_deletion) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.deleteHead();

    EXPECT_EQ(list.getSize(), 2);
    auto newHead = list.deleteHead();
    EXPECT_EQ(newHead->getData(), 2);
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_updates_head_correctly) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.deleteHead();
    list.deleteHead();

    EXPECT_EQ(list.getSize(), 1);
    auto lastNode = list.deleteHead();
    EXPECT_EQ(lastNode->getData(), 3);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteHead_with_string_type) {
    CA::LinkedList<std::string> list;
    list.append("first");
    list.append("second");

    auto result = list.deleteHead();

    EXPECT_EQ(result->getData(), "first");
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_from_copied_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(list1);

    auto result = list2.deleteHead();

    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list2.getSize(), 2);
    EXPECT_EQ(list1.getSize(), 3);
}

TEST(TestLinkedList, Test_deleteHead_from_moved_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));

    auto result = list2.deleteHead();

    EXPECT_EQ(result->getData(), 1);
    EXPECT_EQ(list2.getSize(), 2);
}

TEST(TestLinkedList, Test_deleteHead_interleaved_with_prepend) {
    CA::LinkedList<int> list;
    list.prepend(2);
    list.prepend(1);

    EXPECT_EQ(list.deleteHead()->getData(), 1);

    list.prepend(0);
    EXPECT_EQ(list.deleteHead()->getData(), 0);

    list.prepend(-1);
    EXPECT_EQ(list.deleteHead()->getData(), -1);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_empty_then_repopulate) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.deleteHead();
    list.deleteHead();

    EXPECT_EQ(list.getSize(), 0);

    list.append(10);
    EXPECT_EQ(list.getSize(), 1);
    auto result = list.deleteHead();
    EXPECT_EQ(result->getData(), 10);
}

TEST(TestLinkedList, Test_deleteHead_node_ownership_transfer) {
    CA::LinkedList<int> list;
    list.append(100);
    list.append(200);

    auto deletedNode = list.deleteHead();

    EXPECT_NE(deletedNode, nullptr);
    EXPECT_EQ(deletedNode->getData(), 100);

    deletedNode.reset();
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_mixed_with_remove) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);
    auto headNode = list.deleteHead();

    EXPECT_EQ(headNode->getData(), 1);
    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_deleteHead_and_deleteTail_mixed) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    auto head = list.deleteHead();
    EXPECT_EQ(head->getData(), 1);
    EXPECT_EQ(list.getSize(), 3);

    auto tail = list.deleteTail();
    EXPECT_EQ(tail->getData(), 4);
    EXPECT_EQ(list.getSize(), 2);

    auto head2 = list.deleteHead();
    EXPECT_EQ(head2->getData(), 2);

    auto tail2 = list.deleteTail();
    EXPECT_EQ(tail2->getData(), 3);
    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_deleteHead_single_then_add_more) {
    CA::LinkedList<int> list;
    list.append(1);

    list.deleteHead();
    EXPECT_EQ(list.getSize(), 0);

    list.append(2);
    list.append(3);
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.deleteHead()->getData(), 2);
}

TEST(TestLinkedList, Test_reverse_empty_list) {
    CA::LinkedList<int> list;

    list.reverse();

    EXPECT_EQ(list.getSize(), 0);
}

TEST(TestLinkedList, Test_reverse_single_element) {
    CA::LinkedList<int> list;
    list.append(42);

    list.reverse();

    EXPECT_EQ(list.getSize(), 1);
}

TEST(TestLinkedList, Test_reverse_two_elements) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.reverse();

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_reverse_multiple_elements) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.reverse();

    EXPECT_EQ(list.getSize(), 5);
}

TEST(TestLinkedList, Test_reverse_verifies_order) {
    CA::LinkedList<int> list;
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

TEST(TestLinkedList, Test_reverse_twice_returns_original) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.reverse();
    list.reverse();

    EXPECT_EQ(list.getSize(), 4);
}

TEST(TestLinkedList, Test_reverse_after_prepend_operations) {
    CA::LinkedList<int> list;
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    list.reverse();

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_reverse_updates_tail_correctly) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.reverse();

    auto tailNode = list.deleteTail();
    EXPECT_EQ(tailNode->getData(), 1);
}

TEST(TestLinkedList, Test_reverse_with_string_type) {
    CA::LinkedList<std::string> list;
    list.append("first");
    list.append("second");
    list.append("third");

    list.reverse();

    auto headNode = list.deleteHead();
    EXPECT_EQ(headNode->getData(), "third");
}

TEST(TestLinkedList, Test_reverse_from_copied_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(list1);
    list2.reverse();

    EXPECT_EQ(list2.getSize(), 3);
    EXPECT_EQ(list1.getSize(), 3);
}

TEST(TestLinkedList, Test_reverse_from_moved_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));
    list2.reverse();

    EXPECT_EQ(list2.getSize(), 3);
}

TEST(TestLinkedList, Test_reverse_interleaved_with_append) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    list.reverse();
    EXPECT_EQ(list.getSize(), 2);

    list.append(3);
    EXPECT_EQ(list.getSize(), 3);

    list.reverse();
    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_reverse_then_deleteHead_and_deleteTail) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.reverse();

    auto head = list.deleteHead();
    EXPECT_EQ(head->getData(), 4);

    auto tail = list.deleteTail();
    EXPECT_EQ(tail->getData(), 1);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(TestLinkedList, Test_reverse_method_chaining) {
    CA::LinkedList<int> list;
    list.append(1).append(2).append(3);

    list.reverse().reverse();

    EXPECT_EQ(list.getSize(), 3);
}

TEST(TestLinkedList, Test_reverse_large_list) {
    CA::LinkedList<int> list;
    for (int i = 1; i <= 100; ++i) {
        list.append(i);
    }

    list.reverse();

    EXPECT_EQ(list.getSize(), 100);
}

TEST(TestLinkedList, Test_reverse_preserves_all_elements) {
    CA::LinkedList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    size_t originalSize = list.getSize();
    list.reverse();

    EXPECT_EQ(list.getSize(), originalSize);

    std::vector<int> elements;
    while (list.getSize() > 0) {
        auto node = list.deleteHead();
        elements.push_back(node->getData());
    }

    EXPECT_EQ(elements.size(), 5);
    EXPECT_EQ(elements[0], 50);
    EXPECT_EQ(elements[4], 10);
}

TEST(TestLinkedList, Test_find_by_value_found) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    auto result = list.find(3);

    EXPECT_TRUE(result.has_value());
    if (result.has_value()) {
        EXPECT_EQ(result->get().getData(), 3);
    }
}

TEST(TestLinkedList, Test_find_by_value_not_found) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.find(99);

    EXPECT_FALSE(result.has_value());
    EXPECT_EQ(result, std::nullopt);
}

TEST(TestLinkedList, Test_find_by_value_first_occurrence) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(2);
    list.append(2);
    list.append(3);

    auto result = list.find(2);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestLinkedList, Test_find_by_value_empty_list) {
    CA::LinkedList<int> list;

    auto result = list.find(42);

    EXPECT_FALSE(result.has_value());
}

TEST(TestLinkedList, Test_find_by_value_single_element_found) {
    CA::LinkedList<int> list;
    list.append(42);

    auto result = list.find(42);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 42);
}

TEST(TestLinkedList, Test_find_by_value_single_element_not_found) {
    CA::LinkedList<int> list;
    list.append(42);

    auto result = list.find(99);

    EXPECT_FALSE(result.has_value());
}

TEST(TestLinkedList, Test_find_by_value_modify_node_data) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.find(2);

    EXPECT_TRUE(result.has_value());
    result->get().setData(20);
    EXPECT_EQ(list.find(20)->get().getData(), 20);
}

TEST(TestLinkedList, Test_find_by_predicate_lambda_found) {
    CA::LinkedList<int> list;
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

TEST(TestLinkedList, Test_find_by_predicate_lambda_not_found) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    auto result = list.find([](int value) {
        return value > 10;
    });

    EXPECT_FALSE(result.has_value());
}

TEST(TestLinkedList, Test_find_by_predicate_even_number) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(3);
    list.append(5);
    list.append(8);
    list.append(9);

    auto result = list.find([](int value) {
        return value % 2 == 0;
    });

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 8);
}

TEST(TestLinkedList, Test_find_by_predicate_string_length) {
    CA::LinkedList<std::string> list;
    list.append("hi");
    list.append("hello");
    list.append("world");
    list.append("cpp");

    auto result = list.find([](const std::string& str) {
        return str.length() == 5;
    });

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), "hello");
}

TEST(TestLinkedList, Test_find_by_predicate_custom_condition) {
    CA::LinkedList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    auto result = list.find([](int value) {
        return value >= 20 && value <= 30;
    });

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 20);
}

TEST(TestLinkedList, Test_find_const_version_with_value) {
    const CA::LinkedList<int> list{[](){
        CA::LinkedList<int> l;
        l.append(1).append(2).append(3);
        return l;
    }()};

    auto result = list.find(2);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestLinkedList, Test_find_const_version_not_found) {
    const CA::LinkedList<int> list{[](){
        CA::LinkedList<int> l;
        l.append(1).append(2).append(3);
        return l;
    }()};

    auto result = list.find(99);

    EXPECT_FALSE(result.has_value());
}

TEST(TestLinkedList, Test_find_mixed_with_other_operations) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);

    auto found1 = list.find(1);
    EXPECT_TRUE(found1.has_value());

    list.append(3);
    list.append(4);

    auto found2 = list.find(3);
    EXPECT_TRUE(found2.has_value());

    list.remove(2);

    auto found3 = list.find(2);
    EXPECT_FALSE(found3.has_value());
}

TEST(TestLinkedList, Test_find_after_reverse) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.reverse();

    auto result = list.find(3);
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 3);
}

TEST(TestLinkedList, Test_find_from_copied_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(list1);

    auto result1 = list1.find(2);
    auto result2 = list2.find(2);

    EXPECT_TRUE(result1.has_value());
    EXPECT_TRUE(result2.has_value());
    EXPECT_EQ(result1->get().getData(), 2);
    EXPECT_EQ(result2->get().getData(), 2);
}

TEST(TestLinkedList, Test_find_from_moved_list) {
    CA::LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    CA::LinkedList<int> list2(std::move(list1));

    auto result = list2.find(2);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestLinkedList, Test_find_multiple_times_different_values) {
    CA::LinkedList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    auto result1 = list.find(10);
    auto result2 = list.find(30);
    auto result3 = list.find(40);

    EXPECT_TRUE(result1.has_value());
    EXPECT_TRUE(result2.has_value());
    EXPECT_TRUE(result3.has_value());
    EXPECT_EQ(result1->get().getData(), 10);
    EXPECT_EQ(result2->get().getData(), 30);
    EXPECT_EQ(result3->get().getData(), 40);
}

TEST(TestLinkedList, Test_find_with_function_object) {
    CA::LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    struct IsEven {
        bool operator()(int value) const {
            return value % 2 == 0;
        }
    };

    auto result = list.find(IsEven{});

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 2);
}

TEST(TestLinkedList, Test_find_with_std_function) {
    CA::LinkedList<int> list;
    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);

    std::function<bool(int)> predicate = [](int value) {
        return value % 10 == 0;
    };

    auto result = list.find(predicate);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result->get().getData(), 10);
}
