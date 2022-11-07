/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    subset(res, cur, nums, 0);
    return res;
  }
  void subset(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int start) {
    res.push_back(cur);
    for (int i = start; i < nums.size(); i++) {
      cur.push_back(nums[i]);
      subset(res, cur, nums, i + 1);
      cur.pop_back();
    }
  }
};
// @lc code=end
