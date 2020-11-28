#include <iostream>
#include <string>

#include "arrays_and_strings/check_permutation.h"
#include "arrays_and_strings/is_unique.h"

int main() {
  // std::cout << isUniqueBooleanArray("helo") << std::endl;
  // std::cout << isUniqueBitvector("helo") << std::endl;
  // std::cout << isUniqueBitvector("heleo") << std::endl;

  std::cout << checkPermutationSortString("abc", "cab") << std::endl;
  std::cout << checkPermutationSortString("abc", "ceb") << std::endl;
  std::cout << checkPermutationCountCharacters("abc", "cab") << std::endl;
  std::cout << checkPermutationCountCharacters("abc", "ceb") << std::endl;

  return 1;
}