#include <forward_list>
#include <vector>

struct Node {
  Node(int val) : val(val) {
    left = nullptr;
    right = nullptr;
  }
  int val;
  Node *left;
  Node *right;
};

void preOrder(Node node, int depth,
              std::vector<std::forward_list<Node>> &list) {
  if (list.size() < depth) {
    list.push_back(std::forward_list<Node>{node});
  } else {
    list[depth - 1].push_front(node);
  }
  if (node.left != nullptr) preOrder(*(node.left), depth + 1, list);
  if (node.right != nullptr) preOrder(*(node.right), depth + 1, list);
}

std::vector<std::forward_list<Node>> listOfDepths(Node root) {
  std::vector<std::forward_list<Node>> list{};
  preOrder(root, 1, list);
  return list;
}
