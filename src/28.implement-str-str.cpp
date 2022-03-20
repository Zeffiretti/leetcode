/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> kmp_table(string s) {
    vector<int> table(s.size(), 0);
    int i = 0, j = -1;
    while (i < s.size()) {
      while (j >= 0 && s[i] != s[j]) j = table[j];
      i++;
      j++;
      table[i] = j;
    }
    return table;
  }
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> table = kmp_table(needle);
    int i = 0, j = 0;
    while (i < haystack.size()) {
      while (j >= 0 && haystack[i] != needle[j]) j = table[j];
      i++;
      j++;
      if (j == needle.size()) return i - j;
    }
    return -1;
  }
};
// @lc code=end

