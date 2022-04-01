/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include "utils.h"
// @lc code=start

class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, tmp, nums);
    return res;
  }
  void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> remain) {
    if (remain.empty()) {
      res.push_back(nums);
      return;
    }
    int n = remain.size();
    for (int i = 0; i < n; i++) {
      int val = remain[i];
      remain.erase(remain.begin() + i);
      nums.push_back(val);
      dfs(res, nums, remain);
      nums.pop_back();
      remain.insert(remain.begin() + i, val);
    }
  }
};
// @lc code=end

