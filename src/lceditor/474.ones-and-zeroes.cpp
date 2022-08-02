/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const auto& str : strs) {
      int zeros = 0, ones = 0;
      for (const auto& c : str) {
        if (c == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }
      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
