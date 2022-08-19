/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <vector>
#include "lc-us/problems/utils.h"
// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> cnt(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      if (cnt[s[i] - 'a'] == -1) {
        cnt[s[i] - 'a'] = i;
      } else if (cnt[s[i] - 'a'] >= 0) {
        cnt[s[i] - 'a'] = -2;
      }
    }
    int res = s.size();
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] >= 0) {
        res = min(res, cnt[i]);
      }
    }
    return res == s.size() ? -1 : res;
  }
};
// @lc code=end
