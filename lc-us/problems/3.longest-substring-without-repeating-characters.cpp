/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    vector<int> index_map(128, -1);
    int slow = 0;
    int res = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (index_map[s[i]] == -1) {
        index_map[s[i]] = i;
      } else {
        res = max(res, i - slow);
        slow = max(slow, index_map[s[i]] + 1);
        index_map[s[i]] = i;
      }
    }
    res = max(res, int(s.size()) - slow);
    return res;
  }
};
// @lc code=end
