#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class MinStack {
 public:
  MinStack() { data.clear(); }
  void push(int x) {}
  void pop() {}
  int top() {}
  int min() {}

 private:
  std::vector<int> data;
  int min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */