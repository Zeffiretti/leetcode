/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      double num = 0;
      if (target < nums[0]) {
        if (nums[mid] < nums[0]) {
          num = nums[mid];
        } else {
          num = -INFINITY;
        }
      } else {
        if (nums[mid] >= nums[0]) {
          num = nums[mid];
        } else {
          num = INFINITY;
        }
      }
      // num = (nums[mid] < nums[0]) == (target < nums[0])
      //       ? nums[mid]
      //       : target < nums[0] ? -INFINITY : INFINITY;
      if (num < target)
        lo = mid + 1;
      else if (num > target)
        hi = mid;
      else
        return mid;
    }
    return -1;
  }
};
// @lc code=end

