#include "first_common_ancestor.h"

#include "gtest/gtest.h"

TEST(firstCommonAncestor, example) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);

  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n5->left = n6;
  n5->right = n7;

  EXPECT_EQ(firstCommonAncestor(n1, n6, n7)->value, 5);
}