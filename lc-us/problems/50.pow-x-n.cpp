/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 1) return 1;
    if (n == 0) return 1;
    if (x == -1) return n % 2 ? -1 : 1;
    // if n is negative enough, the return 0.0
    if (n < -30) return 0.0;
    if (n < 0) {
      return myPow(1 / x, -n);
    }
    double ans = 1;
    while (n) {
      if (n % 2 == 1) {
        ans *= x;
      }
      x *= x;
      n >>= 1;
    }
    return ans;
  }
};
// @lc code=end
