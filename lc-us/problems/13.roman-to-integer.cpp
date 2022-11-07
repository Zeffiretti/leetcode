/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int romanToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'I') {
        if (i + 1 < s.size() && s[i + 1] == 'V') {
          num += 4;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'X') {
          num += 9;
          i++;
        } else {
          num += 1;
        }
      } else if (s[i] == 'V') {
        num += 5;
      } else if (s[i] == 'X') {
        if (i + 1 < s.size() && s[i + 1] == 'L') {
          num += 40;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'C') {
          num += 90;
          i++;
        } else {
          num += 10;
        }
      } else if (s[i] == 'L') {
        num += 50;
      } else if (s[i] == 'C') {
        if (i + 1 < s.size() && s[i + 1] == 'D') {
          num += 400;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'M') {
          num += 900;
          i++;
        } else {
          num += 100;
        }
      } else if (s[i] == 'D') {
        num += 500;
      } else if (s[i] == 'M') {
        num += 1000;
      }
    }
    return num;
  }
};
// @lc code=end
