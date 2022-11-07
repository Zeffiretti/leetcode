/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    // ():0, []:1, {}:2
    stack<char> st;
    for (auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);
      } else {
        if (st.empty()) return false;
        char top = st.top();
        st.pop();
        if (top == '(' && ch != ')') return false;
        if (top == '[' && ch != ']') return false;
        if (top == '{' && ch != '}') return false;
      }
    }
    return st.empty();
  }
};
// @lc code=end
