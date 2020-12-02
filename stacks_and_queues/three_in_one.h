class FixedMultiStack {
 public:
  FixedMultiStack(int capacity)
      : capacity(capacity),
        size(new int[3]{}),
        array(new int[3 * capacity]{}) {}
  ~FixedMultiStack() {
    delete[] array;
    delete[] size;
  }

  void push(int stackNum, int value) {
    if (size[stackNum] == capacity) throw "Full stack.";

    size[stackNum]++;
    array[index(stackNum)] = value;
  }

  int pop(int stackNum) {
    if (size[stackNum] == 0) return 0;
    int value = array[index(stackNum)];
    size[stackNum]--;
    array[index(stackNum)] = 0;
    return value;
  }

  int peek(int stackNum) { return array[index(stackNum)]; }

  bool isEmpty(int stackNum) { return size[stackNum] == 0; }

  int index(int stackNum) { return stackNum * capacity + size[stackNum]; }

  int capacity;
  int *size;
  int *array;
};