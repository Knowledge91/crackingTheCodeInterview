#include <bitset>
#include <iostream>
long int insertion(long int n, long int m, int i, int j) {
  long int maskLeft = ~0 << i;
  long int maskRight = ((1 << j) - 1);
  long int mask = ~(maskLeft & maskRight);

  m = m << i;
  n = n & mask;
  n = n | m;

  return n;
}