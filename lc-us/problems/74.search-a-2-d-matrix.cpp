/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = row * col - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int mid_value = matrix[mid / col][mid % col];
      if (mid_value == target) {
        return true;
      } else if (mid_value < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
// @lc code=end
