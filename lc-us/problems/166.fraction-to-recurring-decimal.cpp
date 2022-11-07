/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    if (denominator == 1) return to_string(numerator);
    if (denominator == -1) {
      if (numerator == INT_MIN) return "2147483648";
      return to_string(-numerator);
    }
    string res;
    bool is_negative = (numerator < 0) ^ (denominator < 0);
    if (is_negative) res += "-";
    long int round = numerator / denominator;
    res += to_string(abs(round));
    long int remainder = abs(numerator) % abs(denominator);
    if (remainder == 0) return res;
    res += ".";
    unordered_map<int, int> map;
    while (remainder) {
      if (map.find(remainder) != map.end()) {
        res.insert(map[remainder], "(");
        res += ")";
        break;
      }
      map[remainder] = res.size();
      remainder *= 10;
      res += to_string(remainder / abs(denominator));
      remainder %= abs(denominator);
    }
    return res;
  }
};
// @lc code=end
