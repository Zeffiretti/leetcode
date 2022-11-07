/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    std::stack<int> left_par_stack;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        left_par_stack.push(i);
      }
      if (s[i] == ')') {
        if (left_par_stack.empty()) {
          s[i] = '#';
        } else {
          left_par_stack.pop();
        }
      }
    }
    while (!left_par_stack.empty()) {
      s[left_par_stack.top()] = '#';
      left_par_stack.pop();
    }
    std::string res;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '#') {
        res.push_back(s[i]);
      }
    }
    return res;
  }
};
// @lc code=end
