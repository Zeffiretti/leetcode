/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int px[] = {0, 1, 0, -1};  // right, down, left, up
    int py[] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    int num = 1;
    while (num <= n * n) {
      res[x][y] = num++;
      x += px[d];
      y += py[d];
      if (x < 0 || x >= n || y < 0 || y >= n || res[x][y]) {
        x -= px[d];
        y -= py[d];
        d = (d + 1) % 4;
        x += px[d];
        y += py[d];
      }
    }
    return res;
  }
};
// @lc code=end
