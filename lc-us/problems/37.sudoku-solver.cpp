/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> boxes;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int box_index = (i / 3) * 3 + j / 3;
          if (rows[i].find(board[i][j]) != rows[i].end() || cols[j].find(board[i][j]) != cols[j].end() ||
              boxes[box_index].find(board[i][j]) != boxes[box_index].end()) {
            return false;
          }
          rows[i].insert(board[i][j]);
          cols[j].insert(board[i][j]);
          boxes[box_index].insert(board[i][j]);
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>>& board) {}
};
// @lc code=end
