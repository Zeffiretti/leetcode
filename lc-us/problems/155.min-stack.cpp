/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include "utils.h"
// @lc code=start
class MinStack {
 public:
  MinStack() {
    data.clear();
    // fill min_vals with INT_MAX
    min_vals.clear();
  }

  void push(int val) {
    if (data.empty()) {
      min_vals.push_back(val);
    } else {
      min_vals.push_back(min(val, min_vals.back()));
    }
    data.push_back(val);
  }

  void pop() {
    if (data.empty()) {
      return;
    }
    int val = data.back();
    data.pop_back();
    min_vals.pop_back();
  }

  int top() {
    return data.back();
  }

  int getMin() {
    return min_vals.back();
  }
 private:
  vector<int> data;
  vector<int> min_vals;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

