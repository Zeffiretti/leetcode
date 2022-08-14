/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    int index = 0;
    for (int i = 0; i < g.size(); ++i) {
      while (index < s.size() && s[index] < g[i]) {
        index++;
      }
      if (index < s.size()) {
        res++;
        index++;
      }
    }
    return res;
  }
};
// @lc code=end

