/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> stk;
    stringstream ss(path);
    string s;
    while (getline(ss, s, '/')) {
      if (s == "..") {
        if (!stk.empty()) stk.pop_back();
      } else if (s != "." && !s.empty()) stk.push_back(s);
    }
    string res;
    for (auto s : stk) {
      res += "/" + s;
    }
    return res.empty() ? "/" : res;
  }
};
// @lc code=end

