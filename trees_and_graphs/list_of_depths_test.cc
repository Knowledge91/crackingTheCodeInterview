#include "list_of_depths.h"

#include <forward_list>
#include <vector>

#include "gtest/gtest.h"

int forwardListSize(std::forward_list<Node> list) {
  int counter = 0;
  for (std::forward_list<Node>::iterator it = list.begin(); it != list.end();
       ++it) {
    counter++;
  }
  return counter;
}

TEST(listOfDephts, example) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  n1->left = n2;
  n1->right = n3;
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  n2->left = n4;
  n2->right = n5;
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  n3->left = n6;
  n3->right = n7;

  std::vector<std::forward_list<Node>> list = listOfDepths(*n1);
  EXPECT_EQ(forwardListSize(list[0]), 1);
  EXPECT_EQ(list[0].front().val, 1);
  EXPECT_EQ(forwardListSize(list[1]), 2);
  EXPECT_EQ(list[1].front().val, 3);
  EXPECT_EQ(forwardListSize(list[2]), 4);
  EXPECT_EQ(list[2].front().val, 7);
}