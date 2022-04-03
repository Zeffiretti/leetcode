/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      string tmp = strs[i];
      int j = 0;
      for (; j < res.size() && j < tmp.size(); j++) {
        if (res[j] != tmp[j]) {
          break;
        }
      }
      res = res.substr(0, j);
      if (res == "") {
        return res;
      }
    }
    return res;
  }
};
// @lc code=end

