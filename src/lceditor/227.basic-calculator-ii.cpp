/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    int res = 0;
    string tmp_st = "";
    int tmp_res = 1;
    char plus_minus_ope = '+';
    char mul_div_ope = '*';
    int tmp_tmp = 1;  // temp varible in multiple process
    for (auto& ch : s) {
      if (ch == ' ') {
        continue;
      }
      if (ch >= '0' && ch <= '9') {
        tmp_st += ch;
      } else if (ch == '+' || ch == '-') {
        // first step: process the multiply/division
        if (tmp_st.size() > 0) {
          if (mul_div_ope == '*') {
            tmp_res *= stoi(tmp_st);
          } else if (mul_div_ope == '/') {
            tmp_res /= stoi(tmp_st);
          }
        }
        // second step: add/minus
        if (plus_minus_ope == '+') {
          res += tmp_res;
        } else if (plus_minus_ope == '-') {
          res -= tmp_res;
        }
        tmp_st = "";
        mul_div_ope = '*';
        tmp_res = 1;
        plus_minus_ope = ch;
      } else {  // * and /
        if (mul_div_ope == '*') {
          tmp_res *= stoi(tmp_st);
        } else {
          tmp_res /= stoi(tmp_st);
        }
        mul_div_ope = ch;
        tmp_st = "";
      }
    }
    // first step: process the multiply/division
    if (tmp_st.size() > 0) {
      if (mul_div_ope == '*') {
        tmp_res *= stoi(tmp_st);
      } else if (mul_div_ope == '/') {
        tmp_res /= stoi(tmp_st);
      }
    }
    // second step: add/minus
    if (plus_minus_ope == '+') {
      res += tmp_res;
    } else if (plus_minus_ope == '-') {
      res -= tmp_res;
    }
    return res;
  }
};
// @lc code=end
