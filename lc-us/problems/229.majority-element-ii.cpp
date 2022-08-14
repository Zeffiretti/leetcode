/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int threshold = nums.size() / 3;
    vector<int> res;
    sort(nums.begin(), nums.end());
    int index = 0;
    int i = 1;
    for (; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        if (i - index > threshold) {
          res.push_back(nums[index]);
        }
        index = i;
      }
    }
    if (i - index > threshold) {
      res.push_back(nums[index]);
    }
    return res;
  }
};
// @lc code=end
