/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> m;
    unordered_set<char> used;
    for (int i = 0; i < s.size(); ++i) {
      if (m.find(s[i]) == m.end()) {
        if (used.find(t[i]) != used.end()) {
          return false;
        }
        m[s[i]] = t[i];
        used.insert(t[i]);
      } else {
        if (m[s[i]] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
