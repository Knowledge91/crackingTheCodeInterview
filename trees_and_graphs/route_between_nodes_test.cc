#include "route_between_nodes.h"

#include <iostream>

#include "gtest/gtest.h"
#include "lib/graph.h"

TEST(routeBetweenNodes, singleNode) {
  Node* g = Graph::example();
  EXPECT_TRUE(routeBetweenNodes(g, g->nodes[1]));
}
TEST(routeBetweenNodes, singleNodeOpposite) {
  Node* g = Graph::example();
  EXPECT_FALSE(routeBetweenNodes(g->nodes[1], g));
}
TEST(routeBetweenNodes, threeNodes) {
  Node* g = Graph::example();
  EXPECT_TRUE(routeBetweenNodes(g, g->nodes[1]->nodes[0]));
}