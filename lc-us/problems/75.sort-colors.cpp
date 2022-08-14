/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include "utils.h"// @lc code=start
class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int i = 0;
    while (i <= right) {
      if (nums[i] == 0) {
        if (i != left)
          swap(nums[i], nums[left]);
        left++;
        i++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
      } else {
        i++;
      }
    }
  }
};
// @lc code=end

