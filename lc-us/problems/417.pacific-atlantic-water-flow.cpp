/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    queue<pair<int, int>> pacific_queue;
    queue<pair<int, int>> atlantic_queue;
    vector<vector<int>> res;
    int m = heights.size();
    int n = heights[0].size();
    for (int i = 0; i < n; ++i) {
      pacific_queue.push({0, i});
      atlantic_queue.push({m - 1, i});
    }
    for (int i = 0; i < m; ++i) {
      pacific_queue.push({i, 0});
      atlantic_queue.push({i, n - 1});
    }
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacific_visited(m, vector<int>(n, 0));
    while (!pacific_queue.empty() ) {
      pair<int, int> cur = pacific_queue.front();
      pacific_queue.pop();
      int x = cur.first, y = cur.second;
      pacific_visited[x][y] = 1;
      int height = heights[x][y];
      for (auto dir : directions) {
        int new_x = x + dir.first, new_y = y + dir.second;
        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && heights[new_x][new_y] >= height && pacific_visited[new_x][new_y] == 0) {
          // pacific_visited[new_x][new_y] = 1;
          pacific_queue.push({new_x, new_y});
        }
      }
    }
    vector<vector<int>> atlantic_visited(m, vector<int>(n, 0));
    while (!atlantic_queue.empty()) {
      pair<int, int> cur = atlantic_queue.front();
      atlantic_queue.pop();
      int x = cur.first, y = cur.second;
      atlantic_visited[x][y] = 1;
      int height = heights[x][y];
      for (auto dir : directions) {
        int new_x = x + dir.first, new_y = y + dir.second;
        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && heights[new_x][new_y] >= height && atlantic_visited[new_x][new_y] == 0) {
          // atlantic_visited[new_x][new_y] = 1;
          atlantic_queue.push({new_x, new_y});
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific_visited[i][j] && atlantic_visited[i][j]) {
          res.push_back({i, j});
        }
      }
    }
    return res;
  }
};
// @lc code=end

