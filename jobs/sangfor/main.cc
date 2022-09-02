#include <iostream>
#include <string>
#include <vector>

#include "jobs/sangfor/arthmeetic.h"
#include "jobs/sangfor/attacknum.h"
#include "jobs/sangfor/maxoverlap.h"

int main(int argc, char** argv) {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::string s;
    if (s[0] >= '0' && s[0] <= '9') {
      std::cout << decimalToQuinary(s) << std::endl;
    } else {
      std::cout << quinaryToDecimal(s) << std::endl;
    }
  }
  return 0;
}