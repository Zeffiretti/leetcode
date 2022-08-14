/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    // int len = nums.size();//[1234]
    vector<int> res(nums.size(), 1);
    int left = 1;
    int right = 1;
    for (int i = 0; i < nums.size(); ++i) {
      res[i] *= left;
      left *= nums[i];
      res[nums.size() - i - 1] *= right;
      right *= nums[nums.size() - i - 1];
    }
    return res;
  }
};
// @lc code=end
