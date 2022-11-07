/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });  // sort the intervals by the end time
    int n = intervals.size();
    int count = 0;
    int prev = intervals[0][1];
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] >= prev) {
        prev = intervals[i][1];
      } else {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
