#include "binary_tree.h"

#include <gtest/gtest.h>

#include <iostream>

class BinaryTreeTest : public ::testing::Test {
 protected:
  void SetUp() override {
    binaryTree1_ = new BinaryTree<int>();
    binaryTree1_->insert(10);
    binaryTree1_->insert(7);
    binaryTree1_->insert(8);
    binaryTree1_->insert(2);
    binaryTree1_->insert(13);
  }

  void TearDown() override {}

  BinaryTree<int> *binaryTree1_;
};

TEST_F(BinaryTreeTest, insertNodes) {
  EXPECT_EQ(binaryTree1_->inorderString(), "2,7,8,10,13");
}

TEST_F(BinaryTreeTest, searchNode) {
  Node<int> *node = binaryTree1_->search(7);

  EXPECT_EQ(node->value, 7);
  EXPECT_EQ(node->left->value, 2);
  EXPECT_EQ(node->right->value, 8);
}

TEST_F(BinaryTreeTest, preorder) {
  EXPECT_EQ(binaryTree1_->preorderString(), "10,7,2,8,13");
}

TEST_F(BinaryTreeTest, postorder) {
  EXPECT_EQ(binaryTree1_->postorderString(), "2,8,7,13,10");
}

TEST_F(BinaryTreeTest, deleteTree) {
  Node<int> *node = binaryTree1_->search(7);
  binaryTree1_->destroy();

  // binaryTree1_.root still points to the first node.
  EXPECT_EQ(binaryTree1_->postorderString(), "10");
  EXPECT_EQ(node->value, 0);
}
