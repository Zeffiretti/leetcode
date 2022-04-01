/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int left = 1;
    int right = x - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid > x / mid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left - 1;
  }
};
// @lc code=end

