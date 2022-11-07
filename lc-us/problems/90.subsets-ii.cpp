/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    dfs(res, nums, 0, cur);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& nums, int index, vector<int>& cur) {
    res.push_back(cur);
    for (int i = index; i < nums.size(); i++) {
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }
      cur.push_back(nums[i]);
      dfs(res, nums, i + 1, cur);
      cur.pop_back();
    }
  }
};
// @lc code=end
