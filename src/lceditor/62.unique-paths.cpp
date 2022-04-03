/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1) {
      return 1;
    }
    if (n == 1) {
      return 1;
    }
    int step = m + n - 2;
    int turn = min(m, n) - 1;
    double res = 1;

    // compute nCr
    for (int i = 1; i <= turn; ++i, step--) {
      res = res * (step) / i;
    }
    return (int)res;
  }
};
// @lc code=end

