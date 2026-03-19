# 可执行文件名称建议包含路径以避免冲突，但这里模块名称唯一，直接使用 test_algo1 亦可
add_executable(test_DoublyLinkedList test_DoublyLinkedList.cpp)

# 链接对应的模块库和 Google Test main
target_link_libraries(test_DoublyLinkedList PRIVATE cpp_algorithm_lib gtest_main)

# 自动发现测试用例并注册到 CTest
gtest_discover_tests(test_DoublyLinkedList)