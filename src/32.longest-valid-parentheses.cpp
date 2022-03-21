/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    vector<int> dp(s.size(), 0);
    int left = 0, max_length = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        left++;
      } else if (left > 0) {
        left--;
        dp[i] = dp[i - 1] + 2;
        if (i - dp[i] >= 0) {
          dp[i] += dp[i - dp[i]];
        }
      }
      if (dp[i] > max_length) max_length = dp[i];
    }
    return max_length;
  }
  // dp[i] represents number of valid parentheses matches from s[j to i] (j<i)
  // dp[i] = dp[i-1] + 2 if s[i] == ')' and '(' count >0
};
// @lc code=end

