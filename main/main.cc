#include <iostream>
#include <string>

#include "arrays_and_strings/is_unique.h"

int main() {
  std::cout << isUniqueBooleanArray("helo") << std::endl;
  std::cout << isUniqueBitvector("helo") << std::endl;
  std::cout << isUniqueBitvector("heleo") << std::endl;

  return 1;
}