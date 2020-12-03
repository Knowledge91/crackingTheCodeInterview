#include "stack_of_plates.h"

#include <iostream>

#include "gtest/gtest.h"

TEST(StackSetTest, pushPop) {
  StackSet stackSet = StackSet(2);
  EXPECT_TRUE(stackSet.isEmpty());
  stackSet.push(1);
  EXPECT_FALSE(stackSet.isEmpty());
  stackSet.push(2);
  stackSet.push(3);
  std::cout << "jo3" << std::endl;
  EXPECT_EQ(stackSet.pop(), 3);
  std::cout << "jo5" << std::endl;
  EXPECT_EQ(stackSet.pop(), 2);
  EXPECT_EQ(stackSet.pop(), 1);
  EXPECT_TRUE(stackSet.isEmpty());
}