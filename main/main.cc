#include <forward_list>
#include <iostream>
#include <string>

#include "arrays_and_strings/check_permutation.h"
#include "arrays_and_strings/is_unique.h"
#include "arrays_and_strings/urlify.h"
#include "linked_lists/remove_dups.h"

int main() {
  // std::cout << isUniqueBooleanArray("helo") << std::endl;
  // std::cout << isUniqueBitvector("helo") << std::endl;
  // std::cout << isUniqueBitvector("heleo") << std::endl;

  // std::cout << checkPermutationSortString("abc", "cab") << std::endl;
  // std::cout << checkPermutationSortString("abc", "ceb") << std::endl;
  // std::cout << checkPermutationCountCharacters("abc", "cab") << std::endl;
  // std::cout << checkPermutationCountCharacters("abc", "ceb") << std::endl;

  // std::string url = "Mr John Smith       ";
  // urlify(url, 13);
  // std::cout << url << std::endl;

  std::forward_list<int> list = {1, 3, 5, 3, 4};
  // removeDupsHashtable(list);
  removeDupsRunningPointer(list);
  for (auto v : list) {
    std::cout << v << " ";
  }
  // std::forward_list<int>::iterator pit;
  // for (auto it = list.begin(); it != list.end(); it++) {
  //   if (*it == 3) {
  //     std::cout << "before " << *pit << std::endl;
  //   }
  //   pit = it;
  // }
  std::cout << std::endl;

  return 1;
}