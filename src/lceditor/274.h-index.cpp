/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
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
