#include "validate_bst.h"

#include "gtest/gtest.h"

TEST(validateBST, validBST) {
  Node *n1 = new Node(5);
  Node *n2 = new Node(3);
  Node *n3 = new Node(6);

  n1->left = n2;
  n1->right = n3;

  EXPECT_TRUE(checkBST(n1));
  EXPECT_TRUE(checkBST2(n1));
}

TEST(validateBST, notValidBST) {
  Node *n1 = new Node(5);
  Node *n2 = new Node(3);
  Node *n3 = new Node(6);
  Node *n4 = new Node(1);

  n1->left = n2;
  n1->right = n3;
  n3->right = n4;

  EXPECT_FALSE(checkBST(n1));
  EXPECT_FALSE(checkBST2(n1));
}