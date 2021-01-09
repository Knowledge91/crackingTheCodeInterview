#include <limits>
#include <vector>

struct Node {
  Node(int value) : value(value) {
    left = nullptr;
    right = nullptr;
  }
  int value;
  Node* left;
  Node* right;
};

// Solution 1: In order traversal.
bool checkBST(Node* node, int& prev_seen) {
  if (node == nullptr) return true;

  if (!checkBST(node->left, prev_seen)) return false;
  if (prev_seen > node->value) return false;
  prev_seen = node->value;
  if (!checkBST(node->right, prev_seen)) return false;

  return true;
}

bool checkBST(Node* node) {
  int prev_seen = std::numeric_limits<int>::min();
  return checkBST(node, prev_seen);
}

// Solution 2: Min/ Max range.

bool checkBST2(Node* node, int min, int max) {
  if (node == nullptr) return true;

  if (node->value <= min || node->value > max) return false;

  if (!checkBST2(node->left, min, node->value) ||
      !checkBST2(node->right, node->value, max))
    return false;

  return true;
}

bool checkBST2(Node* node) {
  int min = std::numeric_limits<int>::min();
  int max = std::numeric_limits<int>::max();

  return checkBST2(node, min, max);
}
