/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26, 0);
    vector<bool> visited(26, false);
    for (const auto& c : s) {
      ++cnt[c - 'a'];
    }
    string res;
    for (const auto& c : s) {
      --cnt[c - 'a'];
      if (visited[c - 'a']) continue;
      while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
        visited[res.back() - 'a'] = false;
        res.pop_back();
      }
      res.push_back(c);
      visited[c - 'a'] = true;
    }
    return res;
  }
};
// @lc code=end
