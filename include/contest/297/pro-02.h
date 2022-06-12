#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include <stdio.h>

class Solution {
 public:
  int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
    int res = INT_MAX;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    for (int i = 0; i < grid[0].size(); ++i) {
      dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        for (int k = 0; k < grid[0].size(); ++k) {
          dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
        }
      }
    }
    for (int i = 0; i < grid[0].size(); ++i) {
      res = min(res, dp[grid.size() - 1][i]);
    }
    return res;
  }
};