#include <iostream>

class Node {
 public:
  Node(int value) : value(value), left(nullptr), right(nullptr){};
  int value;
  Node* left;
  Node* right;
};

bool covers(Node* node, Node* p) {
  if (node == nullptr) return false;
  if (node->value == p->value) return true;
  return covers(node->left, p) || covers(node->right, p);
}

Node* firstCommonAncestor(Node* node, Node* p, Node* q) {
  if (node == nullptr || node->value == p->value || node->value == q->value) {
    return node;
  }

  bool pIsInLeftSubTree = covers(node->left, p);
  bool qIsInLeftSubTree = covers(node->left, q);

  if (pIsInLeftSubTree && qIsInLeftSubTree) {
    return firstCommonAncestor(node->left, p, q);
  }
  if (!pIsInLeftSubTree && !qIsInLeftSubTree) {
    return firstCommonAncestor(node->right, p, q);
  }
  if (pIsInLeftSubTree && !qIsInLeftSubTree) {
    return node;
  }
  return node;
}