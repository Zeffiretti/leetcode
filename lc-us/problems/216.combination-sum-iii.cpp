/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    if (n < k || n >= 9 * k) return {};
    vector<vector<int>> res;
    vector<int> cur;
    dfs(res, cur, k, n, 1);
    return res;
  }
  void dfs(vector<vector<int>>& res, vector<int>& cur, int k, int n, int start) {
    if (cur.size() == k) {
      if (n == 0) {
        res.push_back(cur);
      }
      return;
    }
    for (int i = start; i <= 9; ++i) {
      if (n - i < 0) break;
      cur.push_back(i);
      dfs(res, cur, k, n - i, i + 1);
      cur.pop_back();
    }
  }
};
// @lc code=end
