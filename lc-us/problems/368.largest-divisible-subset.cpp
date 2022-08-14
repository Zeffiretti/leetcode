/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  unordered_map<int, vector<int>> dp;
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      auto res = solve(nums, i);
      if (res.size() > ans.size()) ans = res;
    }
    return ans;
  }
  vector<int> solve(vector<int>& nums, int start) {
    if (start >= nums.size()) return {};
    if (dp.count(start)) return dp[start];
    for (int next = start + 1; next < nums.size(); next++) {
      if (nums[next] % nums[start]) continue;
      auto res = solve(nums, next);
      if (res.size() >= dp[start].size()) dp[start] = res;
    }
    dp[start].push_back(nums[start]);
    return dp[start];
  }
};
// @lc code=end
