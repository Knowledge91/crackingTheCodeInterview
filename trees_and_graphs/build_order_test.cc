#include "build_order.h"

#include <vector>

#include "gtest/gtest.h"

TEST(buildOrder, graph) {
  std::vector<std::string> projects = {"a", "b", "c", "d", "e", "f"};
  std::vector<std::vector<std::string>> dependencies = {
      {"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};

  Graph graph(projects, dependencies);
  ASSERT_EQ(graph.nodes.find("a")->second.dependencyCount, 1);
  ASSERT_EQ(graph.nodes.find("b")->second.dependencyCount, 1);
  ASSERT_EQ(graph.nodes.find("c")->second.dependencyCount, 1);
  ASSERT_EQ(graph.nodes.find("d")->second.dependencyCount, 2);
  ASSERT_EQ(graph.nodes.find("e")->second.dependencyCount, 0);
  ASSERT_EQ(graph.nodes.find("f")->second.dependencyCount, 0);

  ASSERT_EQ(graph.nodes.find("a")->second.children.size(), 1);
  ASSERT_EQ(graph.nodes.find("b")->second.children.size(), 1);
  ASSERT_EQ(graph.nodes.find("c")->second.children.size(), 0);
  ASSERT_EQ(graph.nodes.find("d")->second.children.size(), 1);
  ASSERT_EQ(graph.nodes.find("e")->second.children.size(), 0);
  ASSERT_EQ(graph.nodes.find("f")->second.children.size(), 2);
}

TEST(buildOrder, example) {
  std::vector<std::string> projects = {"a", "b", "c", "d", "e", "f"};
  std::vector<std::vector<std::string>> dependencies = {
      {"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};

  std::vector<std::string> buildOrder = getBuildOrder(projects, dependencies);
  ASSERT_EQ(buildOrder[0], "e");
  ASSERT_EQ(buildOrder[1], "f");
  ASSERT_EQ(buildOrder[2], "a");
  ASSERT_EQ(buildOrder[3], "b");
  ASSERT_EQ(buildOrder[4], "d");
  ASSERT_EQ(buildOrder[5], "c");
}

TEST(buildOrder, graphCreation2) {
  std::vector<std::string> projects = {"a", "b", "c", "d", "e", "f"};
  std::vector<std::vector<std::string>> dependencies = {
      {"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};

  Graph2 graph(projects, dependencies);

  ASSERT_EQ(graph.nodes.at("a").firstChild->name, "d");
  ASSERT_EQ(graph.nodes.at("b").firstChild->name, "d");
  ASSERT_EQ(graph.nodes.at("c").firstChild, nullptr);
  ASSERT_EQ(graph.nodes.at("d").firstChild->name, "c");
  ASSERT_EQ(graph.nodes.at("e").firstChild, nullptr);
  ASSERT_EQ(graph.nodes.at("f").firstChild->name, "a");
}

TEST(buildOrder, buildOrder2) {
  std::vector<std::string> projects = {"a", "b", "c", "d", "e", "f"};
  std::vector<std::vector<std::string>> dependencies = {
      {"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};

  std::vector<std::string> buildOrder = getBuildOrder2(projects, dependencies);

  ASSERT_EQ(buildOrder[0], "f");
  ASSERT_EQ(buildOrder[1], "e");
  ASSERT_EQ(buildOrder[2], "b");
  ASSERT_EQ(buildOrder[3], "a");
  ASSERT_EQ(buildOrder[4], "d");
  ASSERT_EQ(buildOrder[5], "c");
}
