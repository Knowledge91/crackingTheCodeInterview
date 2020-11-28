#include <iostream>
#include <string>

bool checkPermutationSortString(std::string str1, std::string str2) {
  if (str1.length() != str2.length()) return false;
  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());
  return str1 == str2;
}

bool checkPermutationCountCharacters(std::string str1, std::string str2) {
  if (str1.length() != str2.length()) return false;
  int char_count[128] = {};  // Assume ASCII.
  for (auto c : str1) {
    char_count[c - 'a']++;
  }

  for (auto c : str2) {
    char_count[c - 'a']--;
    if (char_count[c - 'a'] < 0) return false;
  }

  return true;  // If no char count is negative all char counts are null as str1
                // has the same length as str2.
}