/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    res.push_back(1);
    if (rowIndex == 0) return res;
    res.push_back(1);
    if (rowIndex == 1) return res;
    for (int i = 2; i <= rowIndex; ++i) {
      vector<int> row;
      row.push_back(1);
      for (int j = 1; j < i; ++j) {
        row.push_back(res[j - 1] + res[j]);
      }
      row.push_back(1);
      res = row;
    }
    return res;
  }
};
// @lc code=end

