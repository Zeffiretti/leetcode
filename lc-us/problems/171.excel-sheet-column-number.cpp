/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int res = 0;
    for (char c : columnTitle) {
      res = res * 26 + (c - 'A' + 1);
    }
    return res;
  }
};
// @lc code=end
