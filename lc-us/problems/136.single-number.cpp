/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    unordered_set<int> set;
    int res = 0;
    for (auto num : nums) {
      if (set.find(num) == set.end()) {
        set.insert(num);
        res += num;
      } else {
        set.erase(num);
        res -= num;
      }
    }
    return res;
  }
};
// @lc code=end

