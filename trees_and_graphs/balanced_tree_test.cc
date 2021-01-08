#include "balanced_tree.h"

#include "gtest/gtest.h"

TEST(balancedTree, perfectBalancedTree) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  n1->left = n2;
  n1->right = n3;

  EXPECT_TRUE(isBalanced(n1));
  EXPECT_TRUE(isBalanced2(n1));
}

TEST(balancedTree, balancedTree) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);

  n1->left = n2;
  n1->right = n3;
  n2->left = n4;

  EXPECT_TRUE(isBalanced(n1));
  EXPECT_TRUE(isBalanced2(n1));
}

TEST(balancedTree, imbalancedTree) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  n1->left = n2;
  n2->left = n3;

  EXPECT_FALSE(isBalanced(n1));
  EXPECT_FALSE(isBalanced2(n1));
}