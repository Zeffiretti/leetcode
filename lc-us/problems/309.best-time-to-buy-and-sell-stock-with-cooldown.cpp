/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    vector<int> dp(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i) {
      int maxProfit = 0;
      for (int j = 0; j < i; ++j) {
        maxProfit = max(maxProfit, prices[i] - prices[j] + (j >= 2 ? dp[j - 2] : 0));
      }
      dp[i] = max(dp[i - 1], maxProfit);
    }
    return dp.back();
  }
};
// @lc code=end
