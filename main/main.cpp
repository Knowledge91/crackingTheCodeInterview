#include <iostream>
#include <string>

#include "hashtable.cpp"

struct MyKeyHash {
  unsigned long operator()(const int& k) const { return k % 10; }
};

int main() {
  HashTable<int, std::string, MyKeyHash> htable;
  htable.put(1, "val1");
  htable.put(2, "val2");

  std::string value;
  htable.get(2, value);

  std::cout << "Hello world " << value << std::endl;
  return 1;
}