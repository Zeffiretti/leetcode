/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() < 10) return {};
    unordered_set<string> seen;
    unordered_set<string> repeated;
    vector<string> res;
    for (int i = 0; i < s.size() - 9; ++i) {
      string sub = s.substr(i, 10);
      if (seen.count(sub)) {
        repeated.insert(sub);
      } else {
        seen.insert(sub);
      }
    }
    for (auto str : repeated) {
      res.push_back(str);
    }
    return res;
  }
};
// @lc code=end
