/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    int i = 0;
    long long num = 0;
    while (s[i] == ' ') {
      i++;
    }
    bool isNegative = s[i] == '-';
    if (isNegative || s[i] == '+') {
      i++;
    }
    while ((s[i] - '0') >= 0 && (s[i] - '0') <= 9) {
      if (((num * 10) + (s[i] - '0')) > INT_MAX) return isNegative ? INT_MIN : INT_MAX;
      num = num * 10 + (s[i] - '0');
      i++;
    }
    return isNegative ? -num : num;
  }
};
// @lc code=end
