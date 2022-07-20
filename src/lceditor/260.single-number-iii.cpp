/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        i++;
      } else {
        res.push_back(nums[i]);
      }
      if (res.size() == 2) return res;
    }
    // cout << "res.size()=" << res.size() << endl;
    if (res.size() == 1) res.push_back(nums.back());
    return res;
  }
};
// @lc code=end
