/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int f_min = nums[0];
    int f_max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int fn = f_min, fm = f_max;
      f_min = min(min(fn * nums[i], fm * nums[i]), nums[i]);
      f_max = max(max(fn * nums[i], fm * nums[i]), nums[i]);
      result = max(result, f_max);
    }
    return result;
  }
};
// @lc code=end
