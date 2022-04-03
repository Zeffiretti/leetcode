/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.empty()) return res;
    int size = 1;
    for (int pos = 0; pos < digits.size()  ; pos ++) {
      size *= map[digits[pos] - '0'].size();
    }
    res.resize(size);
    for (int i = 0; i < size; i++) {
      res[i].resize(digits.size());
    }
    int period = size;
    for (int pos = 0; pos < digits.size(); ++pos) {
      period /= map[digits[pos] - '0'].size();
      // int index = -1;
      for (int i = 0; i < size; i++) {
        int index = i / period % map[digits[pos] - '0'].size();
        res[i][pos] = map[digits[pos] - '0'][index];
      }
    }
    return res;
  }
};
// @lc code=end

