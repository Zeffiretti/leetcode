#ifndef JOBS_SANGFOR_ARTHMEETIC
#define JOBS_SANGFOR_ARTHMEETIC

#include <iostream>
#include <string>
#include <vector>

// decimal: 0123456789
// quinary: oyeas

std::string decimalToQuinary(const std::string& decimals) {
  std::string res;
  int decimal_num = std::stoi(decimals);
  while (decimal_num > 0) {
    int remainder = decimal_num % 5;
    if (remainder == 0) {
      res = "o" + res;
    } else if (remainder == 1) {
      res = "y" + res;
    } else if (remainder == 2) {
      res = "e" + res;
    } else if (remainder == 3) {
      res = "a" + res;
    } else if (remainder == 4) {
      res = "s" + res;
    }
    decimal_num /= 5;
  }
  return res;
}

std::string quinaryToDecimal(const std::string& quinaries) {
  std::string res;
  int quinary_num = 0;
  for (int i = 0; i < quinaries.size(); ++i) {
    if (quinaries[i] == 'o') {
      quinary_num = quinary_num * 5 + 0;
    } else if (quinaries[i] == 'y') {
      quinary_num = quinary_num * 5 + 1;
    } else if (quinaries[i] == 'e') {
      quinary_num = quinary_num * 5 + 2;
    } else if (quinaries[i] == 'a') {
      quinary_num = quinary_num * 5 + 3;
    } else if (quinaries[i] == 's') {
      quinary_num = quinary_num * 5 + 4;
    }
  }
  res = std::to_string(quinary_num);
  return res;
}

#endif /* JOBS_SANGFOR_ARTHMEETIC */
