/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0;
    int min_len = INT_MAX;
    while (right < n) {
      sum += nums[right];
      while (sum >= target) {
        min_len = min(min_len, right - left + 1);
        sum -= nums[left++];
      }
      ++right;
    }
    return min_len == INT_MAX ? 0 : min_len;
  }
};
// @lc code=end
