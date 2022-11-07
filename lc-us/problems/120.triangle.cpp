/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0] + triangle[i][0];
      dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
      for (int j = 1; j < i; ++j) {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
    }
    int res = dp[n - 1][0];
    for (int i = 1; i < n; ++i) {
      res = min(res, dp[n - 1][i]);
    }
    return res;
  }
};
// @lc code=end
