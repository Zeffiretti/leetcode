/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    unordered_set<int> un_surrounded{int(board.size() * board[0].size())};
    for (int i = 0; i < board.size(); i++) {  // the left border
      if (board[i][0] == 'O') {
        dfs(board, i, 0, un_surrounded);
      }
    }
    for (int j = 1; j < board[0].size(); j++) {  // the upper border
      if (board[0][j] == 'O') {
        dfs(board, 0, j, un_surrounded);
      }
    }
    for (int i = 1; i < board.size(); i++) {  // the right border
      if (board[i][board[0].size() - 1] == 'O') {
        dfs(board, i, board[0].size() - 1, un_surrounded);
      }
    }
    for (int j = board[0].size() - 2; j >= 0; j--) {  // the bottom border
      if (board[board.size() - 1][j] == 'O') {
        dfs(board, board.size() - 1, j, un_surrounded);
      }
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'O' && !un_surrounded.count(i * board[0].size() + j)) {
          board[i][j] = 'X';
        }
      }
    }
  }
  void dfs(vector<vector<char>>& board, int i, int j, unordered_set<int>& un_surrounded) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    if (board[i][j] == 'X') return;
    int num = i * board[0].size() + j;
    if (un_surrounded.count(num)) return;
    un_surrounded.insert(num);
    dfs(board, i + 1, j, un_surrounded);
    dfs(board, i - 1, j, un_surrounded);
    dfs(board, i, j + 1, un_surrounded);
    dfs(board, i, j - 1, un_surrounded);
  }
};
// @lc code=end
