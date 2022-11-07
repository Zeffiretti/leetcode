/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    int n = s.size();
    if (n < k) return s;
    stack<pair<char, int>> stk;
    for (int i = 0; i < n; ++i) {
      if (stk.empty() || stk.top().first != s[i])
        stk.push({s[i], 1});
      else {
        auto prev = stk.top();
        stk.pop();
        stk.push({s[i], prev.second + 1});
      }
      if (stk.top().second == k) stk.pop();
    }
    string ans = "";
    while (!stk.empty()) {
      auto cur = stk.top();
      stk.pop();
      while (cur.second--) {
        ans.push_back(cur.first);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
