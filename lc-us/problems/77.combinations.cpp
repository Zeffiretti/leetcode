/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    combine(res, cur, n, k, 1);
    return res;
  }
  void combine(vector<vector<int>>& res, vector<int>& cur, int n, int k, int start) {
    if (k == 0) {
      res.push_back(cur);
      return;
    }
    for (int i = start; i <= n - k + 1; i++) {
      cur.push_back(i);
      combine(res, cur, n, k - 1, i + 1);
      cur.pop_back();
    }
  }
};
// @lc code=end
