/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != 0) {
        if (slow != fast) swap(nums[slow], nums[fast]);
        slow++;
      }
    }
  }
};
// @lc code=end
