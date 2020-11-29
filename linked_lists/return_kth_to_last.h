#include <forward_list>
#include <iostream>

std::forward_list<int>::iterator returnKthToLastRecursive(
    std::forward_list<int> list, int k, std::forward_list<int>::iterator it,
    int &i) {
  if (it == list.end()) return it;
  std::forward_list<int>::iterator xit =
      returnKthToLastRecursive(list, k, std::next(it), i);
  i++;
  if (i == k) {
    return it;
  }
  return xit;
}

std::forward_list<int>::iterator returnKthToLastRecursive(
    std::forward_list<int> list, int k) {
  int i = 0;
  return returnKthToLastRecursive(list, k, list.begin(), i);
}

std::forward_list<int>::iterator returnKthToLastIterative(
    std::forward_list<int> list, int k) {
  std::forward_list<int>::iterator it1 = list.begin();
  for (int i = 1; i <= k; i++) {
    it1 = std::next(it1);
  }
  std::forward_list<int>::iterator it2 = list.begin();
  while (it1 != list.end()) {
    it1 = std::next(it1);
    it2 = std::next(it2);
  }
  return it2;
}
