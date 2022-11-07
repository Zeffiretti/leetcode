/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(ans, board, n, 0);
    return ans;
  }

 private:
  void solveNQueensUtil(vector<vector<string>>& ans, vector<string>& cur, int n, int row) {
    if (row == n) {
      ans.push_back(cur);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isValid(cur, row, col)) {
        cur[row][col] = 'Q';
        solveNQueensUtil(ans, cur, n, row + 1);
        cur[row][col] = '.';
      }
    }
  }
  bool isValid(vector<string>& cur, int row, int col) {
    for (int i = 0; i < row; i++) {
      if (cur[i][col] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (cur[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j < cur.size(); i--, j++) {
      if (cur[i][j] == 'Q') return false;
    }
    return true;
  }
};
// @lc code=end
