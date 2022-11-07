/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    if (n == 2) {
      return nums[0] > nums[1] ? 0 : 1;
    }
    if (nums[0] > nums[1]) {
      return 0;
    }
    if (nums[n - 1] > nums[n - 2]) {
      return n - 1;
    }
    int left = 0, right = n - 1;
    return findPeakElementBetween(nums, left, right);
  }

  int findPeakElementBetween(vector<int>& nums, int start, int end) {
    int mid = start + (end - start) / 2;
    if (mid == 0 || mid == nums.size() - 1) {
      return mid;
    }
    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
      return mid;
    }
    if (nums[mid] < nums[mid - 1]) {
      return findPeakElementBetween(nums, start, mid);
    }
    return findPeakElementBetween(nums, mid, end);
  }
};
// @lc code=end
