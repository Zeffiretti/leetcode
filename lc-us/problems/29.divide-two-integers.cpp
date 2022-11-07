/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (divisor == 1) return dividend;
    if (divisor == -1) return -dividend;
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int res = 0;
    while (dvd >= dvs) {
      long long temp = dvs, multiple = 1;
      while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }
      dvd -= temp;
      res += multiple;
    }
    return sign == 1 ? res : -res;
  }
};
// @lc code=end
