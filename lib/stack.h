template <typename T>
class Stack {
 public:
  Stack() { top = nullptr; }

  T pop() {
    if (top == nullptr) throw "Empty stack.";

    T data = top->data;
    StackNode *node = top;
    top = top->next;
    delete node;
    return data;
  }

  T peek() { return top->data; }

  void push(T data) {
    StackNode *node = new StackNode(data);
    node->next = top;
    top = node;
  }

  bool isEmpty() { return top == nullptr; }

  struct StackNode {
    StackNode(T data) : data(data) { next = nullptr; };
    T data;
    StackNode *next;
  };

  StackNode *top;
};