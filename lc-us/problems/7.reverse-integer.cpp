/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include "utils.h"
// @lc code=start

class Solution {
 public:
  int reverse(int x) {
    if (x == INT_MAX || x == INT_MIN)  {
      return 0;
    }
    bool isNegative = x < 0;
    if (isNegative) {
      x *= -1;
    }
    int reverse = 0;
    while (x > 0) {
      if (reverse > INT_MAX / 10) {
        return 0;
      }
      reverse *= 10;
      reverse += x % 10;
      x /= 10;
    }
    return isNegative ? -reverse : reverse;
  }
};

// @lc code=end

