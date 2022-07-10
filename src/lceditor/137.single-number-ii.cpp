/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int res = nums[0];
    unordered_map<int, int> map;
    for (int num : nums) {
      map[num]++;
    }
    for (int num : nums) {
      if (map[num] == 1) {
        res = num;
        break;
      }
    }
    return res;
  }
};
// @lc code=end

