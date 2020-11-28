#include <iostream>
#include <string>

int countWhitespaces(std::string str) {
  int count = 0;
  for (auto c : str) {
    if (c == ' ') count++;
  }
  return count;
}

void urlify(std::string &str, int trueLength) {
  int whitespacesCount = countWhitespaces(str.substr(0, trueLength));
  int j = trueLength - 1 + whitespacesCount * 2;

  for (int i = trueLength - 1; i >= 0; i--) {
    std::cout << str << std::endl;
    if (str[i] == ' ') {
      str[j] = '0';
      str[j - 1] = '2';
      str[j - 2] = '%';
      j -= 3;
    } else {
      str[j] = str[i];
      j--;
    }
  }
}