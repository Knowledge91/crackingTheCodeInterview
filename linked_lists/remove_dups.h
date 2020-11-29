#include <forward_list>
#include <iostream>
#include <unordered_set>

void removeDupsHashtable(std::forward_list<int> &list) {
  std::unordered_set<int> hashtable = {};

  if (list.empty()) return;

  std::forward_list<int>::iterator pit;
  std::forward_list<int>::iterator it = list.begin();
  while (it != list.end()) {
    if (hashtable.contains(*it)) {
      list.erase_after(pit);
    }
    hashtable.insert(*it);
    pit = it;
    it = std::next(it);
  }
}

void removeDupsRunningPointer(std::forward_list<int> &list) {
  for (std::forward_list<int>::iterator it = list.begin(); it != list.end();
       ++it) {
    std::forward_list<int>::iterator pit;
    for (std::forward_list<int>::iterator nit = std::next(it);
         nit != list.end(); ++nit) {
      if (*nit == *it) {
        list.erase_after(pit);
      }
      pit = nit;
    }
  }
}