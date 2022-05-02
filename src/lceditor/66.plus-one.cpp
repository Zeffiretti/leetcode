/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    int index = digits.size() - 1;
    while (carry && index >= 0) {
      digits[index] += carry;
      carry = digits[index] / 10;
      digits[index] %= 10;
      index--;
    }
    if (index < 0 && carry > 0) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};
// @lc code=end

