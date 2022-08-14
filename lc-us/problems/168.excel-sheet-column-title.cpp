/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber) {
      res.push_back('A' + (columnNumber - 1) % 26);
      columnNumber = (columnNumber - 1) / 26;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

