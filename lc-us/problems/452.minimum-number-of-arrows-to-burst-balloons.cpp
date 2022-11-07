/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });  // sort the intervals by the end time
    int count = 1;
    int pre = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > pre) {
        count++;
        pre = points[i][1];
      }
    }
    return count;
  }
};
// @lc code=end
