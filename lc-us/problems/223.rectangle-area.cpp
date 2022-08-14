/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    int x = max(ax1, bx1);
    int y = max(ay1, by1);
    int x2 = min(ax2, bx2);
    int y2 = min(ay2, by2);
    int overlap = 0;
    if (x < x2 && y < y2) {
      overlap = (x2 - x) * (y2 - y);
    }
    return area1 + area2 - overlap;
  }
};
// @lc code=end
