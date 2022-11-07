/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    int min_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < n; ++i) {
      if (prices[i] < min_price) {
        min_price = prices[i];
      } else {
        max_profit = max(max_profit, prices[i] - min_price);
      }
    }
    return max_profit;
  }
};
// @lc code=end
