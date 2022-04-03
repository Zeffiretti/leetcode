/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    std::string res;
    int _k = num / 1000;
    for (int i = 0; i < _k; i++) {
      res += "M";
    }
    int _h = num % 1000 / 100;
    if (_h == 9) {
      res += "CM";
    } else if (_h >= 5) {
      res += "D";
      _h -= 5;
      for (int i = 0; i < _h; i++) {
        res += "C";
      }
    } else if (_h == 4) {
      res += "CD";
    } else {
      for (int i = 0; i < _h; i++) {
        res += "C";
      }
    }
    int _t = num % 100 / 10;
    if (_t == 9) {
      res += "XC";
    } else if (_t >= 5) {
      res += "L";
      _t -= 5;
      for (int i = 0; i < _t; i++) {
        res += "X";
      }
    } else if (_t == 4) {
      res += "XL";
    } else {
      for (int i = 0; i < _t; i++) {
        res += "X";
      }
    }
    int _o = num % 10;
    if (_o == 9) {
      res += "IX";
    } else if (_o >= 5) {
      res += "V";
      _o -= 5;
      for (int i = 0; i < _o; i++) {
        res += "I";
      }
    } else if (_o == 4) {
      res += "IV";
    } else {
      for (int i = 0; i < _o; i++) {
        res += "I";
      }
    }
    return res;
  }
};
// @lc code=end

