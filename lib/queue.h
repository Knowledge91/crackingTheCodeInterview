template <typename T>
class Queue {
 public:
  struct QueueNode {
    QueueNode(T data) : data(data) { next = nullptr; };
    T data;
    QueueNode *next;
  };

  Queue() {
    first = nullptr;
    last = nullptr;
  }

  void add(T data) {
    QueueNode *node = new QueueNode(data);
    if (last != nullptr) {
      last->next = node;
    }
    last = node;
    if (first == nullptr) {
      first = last;
    }
  }

  T remove() {
    T data = first->data;
    QueueNode *node = first;
    first = first->next;
    delete node;
    if (first == nullptr) {
      last = nullptr;
    }
    return data;
  }

  T peek() { return first->data; }

  bool isEmpty() { return first == nullptr; }

  QueueNode *first;
  QueueNode *last;
};