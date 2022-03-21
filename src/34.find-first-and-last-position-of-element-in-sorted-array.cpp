/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int idx = binarySearch(nums, target);
    if (idx == -1)
      return {-1, -1};
    int lo = idx, hi = idx;
    while (lo > 0 && nums[lo - 1] == target)
      lo--;
    while (hi < nums.size() - 1 && nums[hi + 1] == target)
      hi++;
    return {lo, hi};
  }
  int binarySearch(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target)
        lo = mid + 1;
      else
        hi = mid;
    }
    return -1;
  }
};
// @lc code=end

