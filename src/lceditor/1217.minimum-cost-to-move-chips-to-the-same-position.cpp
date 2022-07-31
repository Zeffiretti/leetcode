/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int c[2] = {0};
    for (auto pos : position) {
      ++c[pos % 2];
    }
    return min(c[0], c[1]);
  }
};
// @lc code=end
