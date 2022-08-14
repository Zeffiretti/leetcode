/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int m = isConnected.size();
    int n = isConnected[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j] == 1) {
          res++;
          bfs(isConnected, i, j);
        }
      }
    }
    return res;
  }
  void bfs(vector<vector<int>> &isConnected, int i, int j) {
    if (i < 0 || i >= isConnected.size() || j < 0 || j >= isConnected[0].size()) return;
    if (isConnected[i][j] == 0) return;
    isConnected[i][j] = 0;
    for (int m = 0; m < isConnected[j].size(); ++m) {
      bfs(isConnected, j, m);
    }
  }
};
// @lc code=end

