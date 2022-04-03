/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
    int n = firstList.size(), m = secondList.size(), i = 0, j = 0;
    vector<vector<int>> ans;
    while (i < n && j < m) {
      //simple way to see if they overlap or not
      int front = max(firstList[i][0], secondList[j][0]);
      int back = min(firstList[i][1], secondList[j][1]);
      if (back - front >= 0) {
        ans.push_back({front, back});         //if they do, then just push it into the ans
      }
      //Now increment the pointer corresponding to the interval that ends first because it won't have any overlapping later
      if (firstList[i][1] < secondList[j][1]) i++;
      else  j++;
    }
    return ans;
  }
};
// @lc code=end

