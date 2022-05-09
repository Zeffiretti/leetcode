/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int res = 0;
    for (int num : nums) {
      if (!s.count(num - 1)) { // the consecutive number starts from num
        int cur = num;
        while (s.count(cur)) {
          s.erase(cur);
          cur++;
        }
        res = max(res, cur - num);
      }
    }
    return res;
  }
};
// @lc code=end

