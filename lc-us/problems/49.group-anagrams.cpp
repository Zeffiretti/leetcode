/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> m;
    vector<vector<string>> res;
    int index = 0;
    for (auto& s : strs) {
      string t = s;
      std::sort(t.begin(), t.end());
      if (m.find(t) == m.end()) {
        m[t] = index++;
        res.push_back({s});
      } else {
        res[m[t]].push_back(s);
      }
    }
    return res;
  }
};
// @lc code=end
