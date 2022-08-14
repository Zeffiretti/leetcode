/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) {
      return 0;
    }
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // dp[1] = s[0] == '0' ? 0 : 1;
    if (s[0] == '0') {
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      // 1: the new digit is not 0, then it can be decoded itself
      if (s[i - 1] != '0') {
        dp[i] = dp[i - 1];
      }
      // 2: the new dogit can be decoded by being combined with the previous digit
      if (i >= 2) {
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
          dp[i] += dp[i - 2];
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end
