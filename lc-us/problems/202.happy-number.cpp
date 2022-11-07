/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (n != 1) {
      if (s.count(n)) {
        return false;
      }
      s.insert(n);
      int sum = 0;
      while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      n = sum;
    }
    return true;
  }
};
// @lc code=end
