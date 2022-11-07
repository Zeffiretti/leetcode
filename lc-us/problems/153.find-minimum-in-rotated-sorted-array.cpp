/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    // Find Minimum in Rotated Sorted Array
    int start = 0;
    int end = nums.size() - 1;
    return findMinBetween(nums, start, end);
  }
  int findMinBetween(vector<int>& nums, int start, int end) {
    if (start == end) {
      return nums[start];
    }
    int mid = start + (end - start) / 2;
    if (nums[mid] > nums[end]) {
      return findMinBetween(nums, mid + 1, end);
    } else {
      return findMinBetween(nums, start, mid);
    }
  }
};
// @lc code=end
