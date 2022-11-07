/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int res = 0;
    int n = s.size() - 1;
    while (n >= 0 && s[n] == ' ') n--;
    while (n >= 0 && s[n] != ' ') {
      res++;
      n--;
    }
    return res;
  }
};
// @lc code=end
