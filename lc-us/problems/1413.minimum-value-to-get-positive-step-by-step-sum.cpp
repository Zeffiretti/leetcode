/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int m_min = 0;
    int integ = 0;
    for (auto& i : nums) {
      integ += i;
      m_min = min(m_min, integ);
    }
    return max(1, 1 - m_min);
  }
};
// @lc code=end
