import CAAdd;
#include <gtest/gtest.h>

TEST(CAAddTest, Add) {
    EXPECT_EQ(CA::add(2, 3), 5);
}