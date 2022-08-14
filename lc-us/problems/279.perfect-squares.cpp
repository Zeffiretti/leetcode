/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      dp[i] = i; // 1+1+1+1+...+1 = i
      for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};
// @lc code=end

