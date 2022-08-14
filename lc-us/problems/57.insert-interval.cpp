/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> res;
    int n = intervals.size();
    if (n == 0) {
      res.push_back(newInterval);
      return res;
    }
    int i = 0;
    // process the intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
      res.push_back(intervals[i]);
      i++;
    }
    // process the intervals overlapped with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    // push the newInterval
    res.push_back(newInterval);
    // process the intervals after newInterval
    while (i < n) {
      res.push_back(intervals[i]);
      i++;
    }
    return res;
  }
};
// @lc code=end

