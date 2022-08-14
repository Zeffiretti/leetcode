/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int singleNonDuplicate(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    for (int i = 0; i < nums.size(); i = i + 2) {
      if (nums[i] != nums[i + 1]) {
        return nums[i];
      }
    }
    return nums[nums.size() - 1];
  }
};
// @lc code=end

