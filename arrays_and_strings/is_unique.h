#include <iostream>
#include <string>

bool isUniqueBooleanArray(std::string str) {
  if (str.length() > 128) return false;

  bool char_set[128];
  for (int i = 0; i < str.length(); i++) {
    int val = str[i] - 'a';
    if (char_set[val]) {
      return false;
    }
    char_set[val] = true;
  }
  return true;
};

bool isUniqueBitvector(std::string str) {
  // Assume only characters a-z.

  int checker = 0;
  for (int i = 0; i < str.length(); i++) {
    int val = str[i] - 'a';
    if (checker & (1 << val)) return false;
    checker |= 1 << val;
  }
  return true;
}