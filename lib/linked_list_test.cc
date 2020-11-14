#include "linked_list.h"

#include "gtest/gtest.h"

class DoublyLinkedListTest : public ::testing::Test {
 protected:
  void SetUp() override {
    list0_ = new DoublyLinkedList<int>();

    list1_ = new DoublyLinkedList<int>();
    list1_->add(node0_);
    list1_->add(node1_);
    list1_->add(node2_);

    list2_ = new DoublyLinkedList<int>();
    list2_->add(node3_);
  }

  void TearDown() override {
    delete list0_;
    delete list1_;
    delete list2_;
  }

  DoublyLinkedList<int> *list0_;

  DoublyLinkedList<int> *list1_;
  Node<int> *node0_ = new Node<int>(0);
  Node<int> *node1_ = new Node<int>(1);
  Node<int> *node2_ = new Node<int>(2);

  DoublyLinkedList<int> *list2_;
  Node<int> *node3_ = new Node<int>(3);
};

TEST_F(DoublyLinkedListTest, addNodeToEmptyList) {
  Node<int> *node = new Node<int>(0);
  list0_->add(node);
  EXPECT_EQ(list0_->get(0), node);
};

TEST_F(DoublyLinkedListTest, addNodeAtIndex) {
  Node<int> *node = new Node<int>(3);
  list1_->add(1, node);

  EXPECT_EQ(list1_->get(0), node0_);
  EXPECT_EQ(list1_->get(1), node);
  EXPECT_EQ(list1_->get(2), node1_);
  EXPECT_EQ(list1_->get(3), node2_);
};

TEST_F(DoublyLinkedListTest, addNodeToSingleNodeList) {
  Node<int> *node = new Node<int>(3);
  list2_->add(0, node);

  EXPECT_EQ(list2_->get(0), node);
  EXPECT_EQ(list2_->get(1), node3_);
}

TEST_F(DoublyLinkedListTest, removeNodeAtIndex) {
  list1_->remove(1);

  EXPECT_EQ(list1_->get(0), node0_);
  EXPECT_EQ(list1_->get(1), node2_);
}

TEST_F(DoublyLinkedListTest, removeFirstNode) {
  list1_->remove(0);
  list1_->log();

  EXPECT_EQ(list1_->get(0), node1_);
}
