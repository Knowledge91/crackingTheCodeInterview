#include <queue>

#include "lib/graph.h"

bool routeBetweenNodes(Node* node1, Node* node2) {
  if (node1->data == node2->data) return true;

  std::queue<Node*> queue;
  queue.push(node1);

  while (!queue.empty()) {
    Node* n = queue.front();
    queue.pop();

    if (!n->visited) {
      for (auto node : n->nodes) {
        if (!node->visited) {
          if (node->data == node2->data) {
            return true;
          } else {
            n->visited = true;
            queue.push(node);
          }
        }
      }
      n->visited = true;
    }
  }

  return false;
}
