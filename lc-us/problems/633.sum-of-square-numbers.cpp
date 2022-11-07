/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */
#include "utils.h"
// @lc code=start
#define ll long long
class Solution {
 public:
  bool judgeSquareSum(int c) {
    ll left = 0, right = sqrt(c);
    while (left <= right) {
      if (left * left + right * right == c) return true;
      if (left * left + right * right < c)
        left++;
      else
        right--;
    }
    return false;
  }
};
// @lc code=end
