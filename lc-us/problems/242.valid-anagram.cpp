/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int i : count)
      if (i != 0) return false;
    return true;
  }
};
// @lc code=end
