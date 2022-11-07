/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int max_area = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int area = dfs(grid, i, j);
          max_area = max(max_area, area);
        }
      }
    }
    return max_area;
  }
  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
    if (grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
  }
};
// @lc code=end
