/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != i + 1) {
        if (nums[i] == nums[nums[i] - 1]) {
          i++;
          continue;
        }
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        i++;
      }
    }
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};
// @lc code=end
