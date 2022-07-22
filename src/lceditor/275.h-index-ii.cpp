/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (citations[mid] >= n - mid) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return n - l;
  }
};
// @lc code=end
