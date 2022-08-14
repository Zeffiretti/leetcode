/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    vector<int> prev;
    prev.push_back(0);
    for (int i = 0; i < s.size(); i++) {
      for (int start : prev) {
        string sub_str = s.substr(start, i - start + 1);
        if (dp[start] && dict.count(sub_str)) {
          dp[i + 1] = true;
          prev.push_back(i + 1);
          break;
        }
      }
    }
    return dp[s.size()];
  }
};
// @lc code=end

