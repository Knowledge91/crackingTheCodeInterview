#include <list>
#include <stack>

class StackSet {
 public:
  StackSet(int capacity)
      : stacks(new std::list<std::stack<int> *>()), capacity(capacity) {}

  void push(int v) {
    std::stack<int> *last = stacks->back();
    if (last != nullptr && last->size() != capacity) {
      last->push(v);
    } else {
      std::stack<int> *stack = new std::stack<int>();
      stack->push(v);
      stacks->push_back(stack);
    }
  }

  int pop() {
    std::stack<int> *last = stacks->back();
    if (last == nullptr) throw "Empty stack";
    int v = last->top();
    last->pop();
    if (last->size() == 0) stacks->pop_back();
    return v;
  }

  bool isEmpty() { return stacks->empty(); }

  std::list<std::stack<int> *> *stacks;
  int capacity;
};