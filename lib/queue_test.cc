#include "queue.h"

#include "gtest/gtest.h"

class QueueTest : public ::testing::Test {
 protected:
  void SetUp() override { queue = new Queue<int>(); }
  Queue<int> *queue;
};

TEST_F(QueueTest, addRemovePeekIsEmpty) {
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;

  EXPECT_TRUE(queue->isEmpty());
  queue->add(i1);
  EXPECT_FALSE(queue->isEmpty());
  queue->add(i2);
  EXPECT_EQ(queue->peek(), 1);
  queue->add(i3);
  EXPECT_EQ(queue->remove(), 1);
  EXPECT_EQ(queue->remove(), 2);
  EXPECT_EQ(queue->remove(), 3);
  EXPECT_TRUE(queue->isEmpty());
}