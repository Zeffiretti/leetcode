/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    string curr;
    vector<string> res;
    wordBreakUtil(s, dict, res, curr, 0);
    return res;
  }
  void wordBreakUtil(string s,
                     unordered_set<string> &dict,
                     vector<string> &res,
                     string curr,
                     int idx) {
    if (s.size() == idx) {
      // erase the last space
      curr.pop_back();
      res.push_back(curr);
      return;
    }
    for (int i = idx; i < s.size(); i++) {
      string tmp = s.substr(idx, i - idx + 1);
      if (dict.find(tmp) != dict.end()) {
        wordBreakUtil(s, dict, res, curr + tmp + " ", i + 1);
      }
    }
  }
};
// @lc code=end

