#include <algorithm>

int flipBitToWin(unsigned int a) {
  if (~a == 0) return 32;

  int maxCount = 1;
  int currentCount = 0;
  int previousCount = 0;
  while (a != 0) {
    if ((a & 1) == 1) {
      currentCount++;
    } else {
      maxCount = std::max(currentCount + previousCount + 1, maxCount);
      previousCount = ((a & 2) == 0) ? 0 : currentCount;
      currentCount = 0;
    }
    a >>= 1;
  }
  maxCount = std::max(currentCount + previousCount + 1, maxCount);

  return maxCount;
}