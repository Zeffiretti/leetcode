/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (right > left && nums[left] == nums[right]) {
      right--;
    }
    if (left == right) {
      return nums[left];
    }
    if (nums[right] > nums[left]) {
      return nums[left];
    }
    while (left < right - 1) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right]) {
        left = mid;
      } else if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        right--;
      }
    }
    return nums[right];
  }
};
// @lc code=end

