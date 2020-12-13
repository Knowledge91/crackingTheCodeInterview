#include <vector>

struct MinHeap {
  MinHeap(std::vector<int> v) {
    for (int el : v) {
      insert(el);
    }
  }

  static void heapsort(std::vector<int> &v) {
    MinHeap heap(v);
    for (int i = 0; i < v.size(); i++) v[i] = heap.extractMin();
  }

  void insert(int el) {
    q.push_back(el);
    bubbleUp(q.size() - 1);
  }

  int parent(int k) {
    if (k == 0) return -1;
    return (int)(k - 1) / 2;
  }

  int child(int k) {
    int childK = k * 2 + 1;
    if (childK >= q.size()) return -1;
    return childK;
  }

  void swap(int k1, int k2) {
    int p = q[k1];
    q[k1] = q[k2];
    q[k2] = p;
  }

  void bubbleUp(int k) {
    if (parent(k) < 0) return;

    if (q[k] < q[parent(k)]) {
      swap(k, parent(k));
      bubbleUp(parent(k));
    }
  }

  int extractMin() {
    int min = q[0];
    q[0] = q[q.size() - 1];
    q.pop_back();
    bubbleDown(0);
    return min;
  }

  void bubbleDown(int k) {
    if (child(k) == -1) return;
    int minKey = k;
    // Check if left child smaller.
    if (q[child(k)] < q[minKey]) minKey = child(k);
    // Check if right child smaller.
    if (q[child(k) + 1] < q[minKey]) minKey = child(k) + 1;
    if (k != minKey) {
      swap(k, minKey);
      bubbleDown(minKey);
    }
  }

  std::vector<int> q{};
};
