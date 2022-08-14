/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int addDigits(int num) {
    if (num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
  }
};
// @lc code=end
