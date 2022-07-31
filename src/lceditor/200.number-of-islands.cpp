/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          ++res;
          dfs(grid, i, j, visited);
        }
      }
    }
    return res;
  }
  void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) return;
    visited[i][j] = true;
    dfs(grid, i + 1, j, visited);
    dfs(grid, i - 1, j, visited);
    dfs(grid, i, j + 1, visited);
    dfs(grid, i, j - 1, visited);
  }
};
// @lc code=end
