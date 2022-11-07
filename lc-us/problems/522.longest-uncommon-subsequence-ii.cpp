/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    string substr = strs.at(0);
    int max_len = substr.length();
    for (int i = 1; i < strs.size(); i++) {
      for (int j = 0, m = 0; j < max_len; ++j) {
        if (strs.at(i).at(j) == substr.at(m)) {
          ++m;
        }
      }
    }
  }
};
// @lc code=end
