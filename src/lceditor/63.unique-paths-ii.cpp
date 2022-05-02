/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else if (i > 0 && j > 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else if (i > 0) {
          dp[i][j] = dp[i - 1][j];
        } else if (j > 0) {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
// @lc code=end

