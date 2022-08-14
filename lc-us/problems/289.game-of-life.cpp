/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int count = 0;
        for (int x = max(0, i - 1); x <= min(m - 1, i + 1); x++) {
          for (int y = max(0, j - 1); y <= min(n - 1, j + 1); y++) {
            if (x == i && y == j) continue;
            count += board[x][y] & 1;
          }
        }
        if (board[i][j] & 1) {
          if (count == 2 || count == 3) board[i][j] |= 2;
        } else {
          if (count == 3) board[i][j] |= 2;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] >>= 1;
      }
    }
  }
};
// @lc code=end
