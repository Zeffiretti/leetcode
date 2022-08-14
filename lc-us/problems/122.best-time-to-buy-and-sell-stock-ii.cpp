/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      profit += max(prices[i + 1] - prices[i], 0);
    }
    return profit;
  }
};
// @lc code=end
int main(int argc, char **argv) {
  vector<int> prices{1, 2, 3, 4, 5};
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}
