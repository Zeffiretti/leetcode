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
    bitset<20001> bits(1);
    for (auto &num : nums) bits |= bits << num;
    return bits[sum / 2];
  }
};
// @lc code=end

