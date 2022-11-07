/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    // Integer Break
    if (n == 2) {
      return 1;
    }
    if (n == 3) {
      return 2;
    }
    int res = 1;
    while (n > 4) {
      res *= 3;
      n -= 3;
    }
    return res * n;
  }
};
// @lc code=end
