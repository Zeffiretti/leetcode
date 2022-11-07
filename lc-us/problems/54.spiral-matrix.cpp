/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    if (m == 1) return matrix[0];
    int px[] = {0, 1, 0, -1};  // right, down, left, up
    int py[] = {1, 0, -1, 0};
    int direction_index = 0;
    int cnt = 0;
    int x = 0, y = 0;
    while (cnt < m * n) {
      res.push_back(matrix[x][y]);
      matrix[x][y] = INT_MIN;
      x += px[direction_index];
      y += py[direction_index];
      if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MIN) {
        x -= px[direction_index];
        y -= py[direction_index];
        direction_index = (direction_index + 1) % 4;
        x += px[direction_index];
        y += py[direction_index];
      }
      cnt++;
    }
    return res;
  }
};
// @lc code=end
