#include "minimal_tree.h"

#include <iostream>
#include <iterator>
#include <vector>

#include "gtest/gtest.h"

TEST(minimalTreeTest, test) {
  std::vector<int> v = {1, 2, 3, 4, 5};

  Node* node = minimalTree(v);
  EXPECT_EQ(node->val, 3);
  EXPECT_EQ(node->left->val, 1);
  EXPECT_EQ(node->left->right->val, 2);
  EXPECT_EQ(node->right->val, 5);
  EXPECT_EQ(node->right->left->val, 4);
}