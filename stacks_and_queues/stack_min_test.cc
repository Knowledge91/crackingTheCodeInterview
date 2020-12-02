#include "stack_min.h"

#include "gtest/gtest.h"

class MinStackTest : public ::testing::Test {};

TEST_F(MinStackTest, PushPopMin) {
  MinStack stack = MinStack();

  EXPECT_EQ(stack.min(), __INT_MAX__);
  stack.push(5);
  EXPECT_EQ(stack.min(), 5);
  stack.push(7);
  EXPECT_EQ(stack.min(), 5);
  stack.push(3);
  EXPECT_EQ(stack.min(), 3);
  stack.pop();
  EXPECT_EQ(stack.min(), 5);
  stack.pop();
  EXPECT_EQ(stack.min(), 5);
}