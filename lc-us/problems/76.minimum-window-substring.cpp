/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> chars(128, 0);
    vector<bool> flags(128, false);
    // 统计t中的字符
    for (auto c : t) {
      chars[c]++;
      flags[c] = true;
    }
    int cnt = 0, l = 0, r = 0, minLen = INT_MAX, minL = 0;
    while (r < s.size()) {
      if (flags[s[r]]) {
        chars[s[r]]--;
        if (chars[s[r]] >= 0) cnt++;
      }
      r++;
      while (cnt == t.size()) {
        if (r - l < minLen) {
          minLen = r - l;
          minL = l;
        }
        if (flags[s[l]]) {
          chars[s[l]]++;
          if (chars[s[l]] > 0) cnt--;
        }
        l++;
      }
    }
    return minLen == INT_MAX ? "" : s.substr(minL, minLen);
  }
};
// @lc code=end
