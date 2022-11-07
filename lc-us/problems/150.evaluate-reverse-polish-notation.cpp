/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto& token : tokens) {
      if (token == "+") {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a + b);
      } else if (token == "-") {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b - a);
      } else if (token == "*") {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a * b);
      } else if (token == "/") {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b / a);
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};
// @lc code=end
