/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    int ret = 0, max = 0x7fffffff, min = 0;
    long rs = 0;
    for (; x; rs = rs * 10 + x % 10, x /= 10)
      ;
    return ret = rs > max || rs < min ? 0 : rs;
  }
  bool isPalindrome(int x) { return x == reverse(x); }
};
// @lc code=end
