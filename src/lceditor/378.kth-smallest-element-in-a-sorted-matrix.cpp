/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
      }
      if (cnt < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};
// @lc code=end
