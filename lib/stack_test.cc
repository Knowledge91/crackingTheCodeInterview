#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 protected:
  void SetUp() override { stack = new Stack<int>(); }

  Stack<int> *stack;
};

TEST_F(StackTest, PushPopAndPeek) {
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  EXPECT_TRUE(stack->isEmpty());
  stack->push(i1);
  EXPECT_FALSE(stack->isEmpty());
  stack->push(i2);
  stack->push(i3);
  EXPECT_EQ(stack->pop(), 3);
  EXPECT_EQ(stack->peek(), 2);
  EXPECT_EQ(stack->pop(), 2);
  EXPECT_EQ(stack->pop(), 1);
  EXPECT_TRUE(stack->isEmpty());
}
