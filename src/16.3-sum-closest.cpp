/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    int res = 1e5;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == target) {
          return sum;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
        if (abs(sum - target) < abs(res - target)) {
          res = sum;
        }
      }
    }
    return res;
  }
};
// @lc code=end

