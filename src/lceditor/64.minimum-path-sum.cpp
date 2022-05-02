/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 2e6));
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = grid[i][j];
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
  }
};
// @lc code=end

