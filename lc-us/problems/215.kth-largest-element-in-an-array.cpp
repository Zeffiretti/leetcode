/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1, target = nums.size() - (k);
    while (left < right) {
      int mid = partition(nums, left, right);
      if (mid == target) {
        return nums[mid];
      }
      if (mid > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return nums[left];
  }
  int partition(vector<int>& nums, int left, int right) {
    int i = left + 1, j = right;
    while (true) {
      while (i < right && nums[i] <= nums[left]) {
        ++i;
      }
      while (j > left && nums[j] >= nums[left]) {
        --j;
      }
      if (j <= i) {
        break;
      }
      swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[left]);
    return j;
  }
};
// @lc code=end
