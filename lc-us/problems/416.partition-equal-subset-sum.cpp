/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include "utils.h"
// @lc code=start

class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2) return false;
    int target = sum / 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
    // dp[i][j] 表示从 nums[0] ~ nums[i-1] 的元素中，取出 j 的方案是否可行
    dp[0][0] = true;
    for (int i = 1; i <= nums.size(); ++i) {
      for (int j = 0; j <= target; ++j) {
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
      if (dp[i][target]) return true;
    }
    return dp[nums.size()][target];
  }
};
// @lc code=end

