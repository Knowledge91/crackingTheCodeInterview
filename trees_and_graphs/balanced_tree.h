#include <stdlib.h>

#include <algorithm>
#include <limits>

struct Node {
  Node(int val) : val(val) {
    left = nullptr;
    right = nullptr;
  }
  int val;
  Node *left;
  Node *right;
};

// Method 1: O(n log(n))
int getHeight(Node *node) {
  if (node == nullptr) return -1;

  return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool isBalanced(Node *node) {
  if (node == nullptr) return true;

  if (std::abs(getHeight(node->left) - getHeight(node->right)) > 1) {
    return false;
  } else {
    return isBalanced(node->left) && isBalanced(node->right);
  }
}

// Method 2: O(n)
int checkHeight(Node *node) {
  if (node == nullptr) return -1;

  int leftHeight = checkHeight(node->left);
  if (leftHeight == std::numeric_limits<int>::min())
    return std::numeric_limits<int>::min();

  int rightHeight = checkHeight(node->right);
  if (rightHeight == std::numeric_limits<int>::min())
    return std::numeric_limits<int>::min();

  if (std::abs(leftHeight - rightHeight) > 1) {
    return std::numeric_limits<int>::min();
  } else {
    return std::max(leftHeight, rightHeight) + 1;
  }
}

bool isBalanced2(Node *node) {
  return checkHeight(node) != std::numeric_limits<int>::min();
}
