/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = tmp;
      }
    }
  }
  // swap 4 items in a loop
  void swap(vector<vector<int>>& matrix, int i, int j, int k, int l) {
    int tmp = matrix[i][j];
    matrix[i][j] = matrix[k][l];
    matrix[k][l] = tmp;
  }
};
// @lc code=end
