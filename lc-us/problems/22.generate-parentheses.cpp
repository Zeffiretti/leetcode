/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s;
    generateParenthesisUtil(n, n, s, res);
    return res;
  }

 private:
  void generateParenthesisUtil(int left, int right, string s, vector<string>& res) {
    if (left == 0 && right == 0) {
      res.push_back(s);
      return;
    }
    if (left > 0) {
      generateParenthesisUtil(left - 1, right, s + '(', res);
    }
    if (right > left) {
      generateParenthesisUtil(left, right - 1, s + ')', res);
    }
    return;
  }
};
// @lc code=end
