#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *left;
  Node *right;
};

void insertNode(Node **node, std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  std::vector<int>::iterator mid = begin + std::distance(begin, end) / 2;
  (*node)->val = *mid;

  if (std::distance(begin, mid) > 0) {
    Node *newNode = new Node();
    Node **pN = &((*node)->left);
    *pN = newNode;
    insertNode(pN, begin, std::prev(mid));
  }
  if (std::distance(mid, end) > 0) {
    std::vector<int>::iterator mc = mid;
    Node *newNode = new Node{};
    Node **pN = &((*node)->right);
    *pN = newNode;
    insertNode(pN, std::next(mid), end);
  }
};

Node *minimalTree(std::vector<int> v) {
  Node *node = new Node();
  Node **pNode = &node;
  insertNode(pNode, v.begin(), v.end());
  return node;
};
