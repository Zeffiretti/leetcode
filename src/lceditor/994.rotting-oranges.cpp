/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1 && n == 1) return grid[0][0] == 1 ? -1 : 0;
    queue<pair<int, int>> rotted;
    int health = 0;
    int rot = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          health++;
        } else if (grid[i][j] == 2) {
          rotted.push({i, j});
          rot++;
        }
      }
    }
    if (health == 0) return 0;
    if (rot == 0) return -1;
    int cnt = 0;
    int tmp_rot = 0;
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!rotted.empty()) {
      auto cur = rotted.front();
      rotted.pop();
      rot--;
      int curx = cur.first;
      int cury = cur.second;
      for (auto dir : dirs) {
        int x = curx + dir.first;
        int y = cury + dir.second;
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
          if (grid[x][y] == 1) {
            grid[x][y] = 2;
            rotted.push({x, y});
            tmp_rot++;
            health--;
          }
        }
      }
      if (rot == 0) {
        cnt++;
        rot = tmp_rot;
        tmp_rot = 0;
      }
    }
    vector<int> row(m, 0);
    // iterate through the row
    return health == 0 ? cnt - 1 : -1;
  }
};
// @lc code=end

