#include <memory>
#include <vector>

class Vertex {
 public:
  std::unique_ptr<Vertex> next;
};

class Graph {
 public:
  void addVertex(const Vertex& x) { adjacent_list_.push_back(x); }
  void addEdge(const Vertex& x, const Vertex& y) {
    while()
  }

 private:
  std::vector<Vertex> adjacent_list_;
};