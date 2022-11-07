/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) {
      return 0;
    }
    vector<int> subs;
    int gap = nums[1] - nums[0];
    int m_start = 0;
    int end = 2;
    while (end < nums.size()) {
      if (nums[end] - nums[end - 1] == gap) {
        end++;
      } else {
        subs.push_back(end - m_start);
        m_start = end - 1;
        gap = nums[end] - nums[end - 1];
      }
    }
    subs.push_back(end - m_start);
    int res = 0;
    for (int i = 0; i < subs.size(); ++i) {
      int n = subs[i];
      if (n >= 3) {
        res += (n - 2) * (n - 1) / 2;
      }
    }
    return res;
  }
};
// @lc code=end
