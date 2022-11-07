/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(candidates, target, 0, path, res);
    return res;
  }
  void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res) {
    if (target == 0) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
      path.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i, path, res);
      path.pop_back();
    }
  }
};
// @lc code=end
