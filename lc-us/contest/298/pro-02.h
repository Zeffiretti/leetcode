#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

class Solution {
 public:
  int minimumNumbers(int num, int k) {
    if (num == 0) {
      return 0;
    }
    if (k == 0) {
      if (num % 10 == 0) {
        return 1;
      } else {
        return -1;
      }
    }
    int res = -1;
    // The units digit of a number is the rightmost digit of the number.
    int digit = num % 10;
    if (digit == k) {
      return 1;
    }
    while (digit != k) {
    }
  }
};