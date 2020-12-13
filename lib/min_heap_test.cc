#include "min_heap.h"

#include <vector>

#include "gtest/gtest.h"

TEST(MinHeap, parent) {
  MinHeap heap(std::vector<int>{});
  EXPECT_EQ(heap.parent(0), -1);
  EXPECT_EQ(heap.parent(1), 0);
  EXPECT_EQ(heap.parent(2), 0);
  EXPECT_EQ(heap.parent(3), 1);
  EXPECT_EQ(heap.parent(4), 1);
}

TEST(MinHeap, creation) {
  std::vector<int> v = {2, 8, 5, 3, 9, 1};
  MinHeap heap(v);

  EXPECT_EQ(heap.q[0], 1);
  EXPECT_EQ(heap.q[1], 3);
  EXPECT_EQ(heap.q[2], 2);
}

TEST(MinHeap, exctractMin) {
  std::vector<int> v = {2, 8, 5, 3, 9, 1};
  MinHeap heap(v);

  EXPECT_EQ(heap.extractMin(), 1);
  EXPECT_EQ(heap.q[0], 2);
  EXPECT_EQ(heap.q[1], 3);
  EXPECT_EQ(heap.q[2], 5);
}

TEST(MinHeap, heapsort) {
  std::vector<int> v = {2, 8, 5, 3, 9, 1};
  MinHeap::heapsort(v);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 5);
  EXPECT_EQ(v[4], 8);
  EXPECT_EQ(v[5], 9);
}
