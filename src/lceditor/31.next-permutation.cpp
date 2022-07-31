/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int index = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int j = nums.size() - 1;
    while (nums[j] <= nums[index]) {
      --j;
    }
    swap(nums[index], nums[j]);
    reverse(nums.begin() + index + 1, nums.end());
  }
};
// @lc code=end
