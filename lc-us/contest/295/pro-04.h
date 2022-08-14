#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <list>
#include <map>
#include <set>
using namespace std;

class Solution {
 public:
  int minimumObstacles(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    dp[0][0] = grid[0][0];
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    dfs(grid, 0, 0, visited, dp[0][0], dp);
    return dp[grid.size() - 1][grid[0].size() - 1];
  }

  void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited, int obstacle, vector<vector<int>> &dp) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    }
    if (visited[i][j] == 1) {
      return;
    }
    visited[i][j] = 1;
    dp[i][j] = min(dp[i][j], obstacle + grid[i][j]);
    dfs(grid, i - 1, j, visited, dp[i][j], dp);
    dfs(grid, i + 1, j, visited, dp[i][j], dp);
    dfs(grid, i, j - 1, visited, dp[i][j], dp);
    dfs(grid, i, j + 1, visited, dp[i][j], dp);
    visited[i][j] = 0;
  }
};