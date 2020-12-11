#include <iostream>
#include <string>

std::string binaryToString(double num) {
  if (num > 1 || num < 0) {
    return "ERROR";
  }

  std::string binary = ".";

  while (num > 0) {
    if (binary.length() > 32) {
      return "ERROR";
    }

    double r = num * 2;
    if (r >= 1) {
      binary.append("1");
      num = r - 1;
    } else {
      binary.append("0");
      num = r;
    }
  }
  return binary;
}