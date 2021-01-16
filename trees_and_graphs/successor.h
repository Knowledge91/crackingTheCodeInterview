struct Node {
  Node(int value) : value(value) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }

  Node *left;
  Node *right;
  Node *parent;
  int value;
};

Node *leftmostChild(Node *node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
};

Node *successor(Node *node) {
  if (node->right != nullptr) {
    return leftmostChild(node->right);
  } else {
    Node *x = node;
    Node *q = node->parent;
    while (q != nullptr && q->left->value != x->value) {
      x = q;
      q = q->parent;
    }
    return q;
  }
};