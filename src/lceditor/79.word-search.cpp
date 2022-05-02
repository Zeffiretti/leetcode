/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    if (m == 0) {
      return false;
    }
    int n = board[0].size();
    if (n == 0) {
      return false;
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, word, 0, i, j, visited)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>> &board, string &word, int index, int i,
           int j, vector<vector<bool>> &visited) {
    if (index == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        visited[i][j] || board[i][j] != word[index]) {
      return false;
    }
    visited[i][j] = true;
    if (dfs(board, word, index + 1, i + 1, j, visited) ||
        dfs(board, word, index + 1, i - 1, j, visited) ||
        dfs(board, word, index + 1, i, j + 1, visited) ||
        dfs(board, word, index + 1, i, j - 1, visited)) {
      return true;
    }
    visited[i][j] = false;

    return false;
  }
};
// @lc code=end

