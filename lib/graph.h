#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

struct Node {
  Node(int data) : data(data), nodes{}, visited{false} {}
  Node(int data, std::vector<Node*> nodes)
      : data(data), nodes(nodes), visited{false} {}

  void printAdjacentNodes() {
    for (auto node : nodes) {
      std::cout << node->data << ", ";
    }
    std::cout << std::endl;
  }

  int data;
  std::vector<Node*> nodes;
  bool visited;
};

class Graph {
 public:
  static Node* example() {
    Node* n8 = new Node{8};
    Node* n6 = new Node{6, {n8}};
    Node* n7 = new Node{7};
    Node* n5 = new Node{5, {n7}};
    Node* n3 = new Node{3, {n5, n6, n7}};
    Node* n2 = new Node{2};
    Node* n4 = new Node{4};
    n4->nodes.push_back(n4);
    Node* n1 = new Node{1, {n2, n3, n4}};
    n2->nodes.push_back(n1);
    return n1;
  }
};

#endif