#include "three_in_one.h"

#include <iostream>

#include "gtest/gtest.h"

class FixedMultiStackTest : public ::testing::Test {
 protected:
  void SetUp() override { stack = new FixedMultiStack(3); }
  FixedMultiStack *stack;
};

TEST_F(FixedMultiStackTest, pushPopPeekIsEmpty) {
  EXPECT_TRUE(stack->isEmpty(0));
  stack->push(0, 1);
  EXPECT_FALSE(stack->isEmpty(0));
  stack->push(0, 2);
  stack->push(2, 1);
  stack->push(2, 2);
  stack->push(2, 3);
  EXPECT_EQ(stack->peek(0), 2);
  EXPECT_EQ(stack->peek(1), 0);
  EXPECT_EQ(stack->peek(2), 3);
  EXPECT_EQ(stack->pop(2), 3);
  EXPECT_EQ(stack->pop(0), 2);
  EXPECT_EQ(stack->pop(0), 0);
  EXPECT_TRUE(stack->isEmpty(0));
}