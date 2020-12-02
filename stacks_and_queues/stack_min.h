#include "lib/stack.h"

class MinStack : public Stack<int> {
 public:
  void push(int data) {
    Stack::push(data);
    if (data <= min()) minStack.push(data);
  }

  int pop() {
    int xData = Stack::pop();
    if (xData == min()) minStack.pop();
    return xData;
  }

  int min() {
    if (minStack.isEmpty()) return __INT_MAX__;
    return minStack.peek();
  }

  Stack minStack = Stack();
};