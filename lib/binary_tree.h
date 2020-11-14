#include <iostream>

template <typename V>
struct Node {
 public:
  Node(V v) : value(v), left(nullptr), right(nullptr){};

  ~Node() {
    left = nullptr;
    right = nullptr;
  };

  V value;
  Node *left;
  Node *right;
};

template <typename V, typename Node = Node<V> >
class BinaryTree {
 public:
  BinaryTree() : root_(nullptr){};
  ~BinaryTree() { destroy(); };

  void destroy() { destroy(root_); }

  std::string preorderString() {
    std::string string = "";
    preorderString(string, root_);
    return string;
  }

  std::string postorderString() {
    std::string string = "";
    postorderString(string, root_);
    return string;
  }

  void logInorder() { std::cout << inorderString() << std::endl; }

  std::string inorderString() {
    std::string string = "";
    inorderString(string, root_);
    return string;
  }

  void insert(V value) {
    if (root_ != nullptr) {
      insert(value, root_);
    } else {
      root_ = new Node(value);
    }
  }

  Node *search(V value) { return search(value, root_); }

 private:
  void inorderString(std::string &string, Node *node) {
    if (node == nullptr) {
      return;
    }
    if (node->left != nullptr) {
      inorderString(string, node->left);
    }
    if (string != "") {
      string += ",";
    }
    string += std::to_string(node->value);
    if (node->right != nullptr) {
      inorderString(string, node->right);
    }
  };

  void preorderString(std::string &string, Node *node) {
    if (node == nullptr) {
      return;
    }
    if (string != "") {
      string += ",";
    }
    string += std::to_string(node->value);
    if (node->left != nullptr) {
      preorderString(string, node->left);
    }
    if (node->right != nullptr) {
      preorderString(string, node->right);
    }
  }

  void postorderString(std::string &string, Node *node) {
    if (node == nullptr) {
      return;
    }
    if (node->left != nullptr) {
      postorderString(string, node->left);
    }
    if (node->right != nullptr) {
      postorderString(string, node->right);
    }
    if (string != "") {
      string += ",";
    }
    string += std::to_string(node->value);
  }

  void insert(V value, Node *node) {
    if (value < node->value) {
      if (node->left != nullptr) {
        insert(value, node->left);
      } else {
        node->left = new Node(value);
      }
    } else {
      if (node->right != nullptr) {
        insert(value, node->right);
      } else {
        node->right = new Node(value);
      }
    }
  }

  Node *search(V value, Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->value == value) {
      return node;
    }

    if (value < node->value) {
      return search(value, node->left);
    } else {
      return search(value, node->right);
    }
  }

  void destroy(Node *node) {
    if (node != nullptr) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

  Node *root_;
};