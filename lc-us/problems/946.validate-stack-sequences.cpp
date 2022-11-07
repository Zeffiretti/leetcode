/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    for (int i = 0, j = 0; i < pushed.size(); ++i) {
      s.push(pushed[i]);
      while (j < popped.size() && !s.empty() && s.top() == popped[j]) {
        s.pop();
        j++;
      }
    }
    return s.empty();
  }
};
// @lc code=end
