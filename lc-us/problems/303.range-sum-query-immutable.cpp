/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include "utils.h"
// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    nums_sum.assign(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      nums_sum[i + 1] = nums_sum[i] + nums[i];
    }
  }

  int sumRange(int left, int right) { return nums_sum[right + 1] - nums_sum[left]; }

 private:
  vector<int> nums_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
