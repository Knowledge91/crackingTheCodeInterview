#include <iostream>

template <typename D>
struct Node {
 public:
  Node(D data) : data_(data), prev_(nullptr), next_(nullptr) {}

  D getData() const { return data_; };
  Node *getPrev() const { return prev_; };
  void setPrev(Node *prev) { prev_ = prev; };
  Node *getNext() const { return next_; };
  void setNext(Node *next) { next_ = next; };

  bool operator==(const Node *node) const { return data_ == node->getData(); };

 private:
  D data_;
  Node *prev_;
  Node *next_;
};

template <typename D, typename Node = Node<D> >
class DoublyLinkedList {
 public:
  DoublyLinkedList() : firstNode_(nullptr){};
  ~DoublyLinkedList(){};

  void log() {
    int i = 0;
    Node *node = firstNode_;
    while (node) {
      std::cout << "Node " << i << ": " << node->getData() << std::endl;
      i++;
      node = node->getNext();
    }
  }

  Node *get(int index) {
    Node *node = firstNode_;
    for (int i = 0; i < index; ++i) {
      node = node->getNext();
    };
    return node;
  };

  void add(Node *node) {
    if (firstNode_ == nullptr) {
      addFirst(node);
    } else {
      addLast(node);
    }
  }

  void add(int index, Node *newNode) {
    // If empty list add first node.
    if (firstNode_ == nullptr) {
      addFirst(newNode);
      return;
    }

    Node *oldNode = get(index);
    // If index node does not exist add as last node.
    if (oldNode == nullptr) {
      addLast(newNode);
      return;
    }

    // Link prev node if exists.
    if (oldNode->getPrev() != nullptr) {
      Node *prevNode = oldNode->getPrev();
      prevNode->setNext(newNode);
      newNode->setPrev(prevNode);
    } else {
      firstNode_ = newNode;
    }

    // Link newNode to oldNode.
    newNode->setNext(oldNode);
    oldNode->setPrev(newNode);
  };

  void remove(int index) {
    Node *node = get(index);
    Node *prevNode = node->getPrev();
    Node *nextNode = node->getNext();

    if (prevNode != nullptr) {
      prevNode->setNext(nextNode);
    }
    if (nextNode != nullptr) {
      nextNode->setPrev(prevNode);
    }
    delete node;

    if (prevNode == nullptr && nextNode == nullptr) {
      firstNode_ = nullptr;
    } else if (prevNode == nullptr && nextNode != nullptr) {
      firstNode_ = nextNode;
    }
  };

  void addFirst(Node *newNode) { firstNode_ = newNode; };

  void addLast(Node *newNode) {
    Node *node = firstNode_;
    while (node->getNext() != nullptr) {
      node = node->getNext();
    };
    node->setNext(newNode);
    newNode->setPrev(node);
  };
  void clear(){};

 private:
  Node *firstNode_;
};