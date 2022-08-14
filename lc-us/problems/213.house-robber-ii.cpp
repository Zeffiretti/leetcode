/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int robUtil(vector<int> &nums, int start, int end) {
    if (end - start <= 0) return nums[start];
    if (end - start == 1) return max(nums[start], nums[end]);
    vector<int> dp(end - start + 1, 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; ++i) {
      dp[i - start] = max(dp[i - start - 1], dp[i - start - 2] + nums[i]);
    }
    return dp[end - start];
  }
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    // avoid rob the first house and the last house at the same time
    return max(robUtil(nums, 1, n - 1), robUtil(nums, 0, n - 2));
  }
};
// @lc code=end

