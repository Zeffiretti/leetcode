/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return n * (n + 1) / 2 - sum;
  }
};
// @lc code=end
