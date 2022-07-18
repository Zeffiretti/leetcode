/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include "utils.h"
// @lc code=start
class MyQueue {
 public:
  MyQueue() {
    stack1 = new stack<int>();
    stack2 = new stack<int>();
  }

  void push(int x) { stack1->push(x); }

  int pop() {
    while (!stack1->empty()) {
      stack2->push(stack1->top());
      stack1->pop();
    }
    int res = stack2->top();
    stack2->pop();
    while (!stack2->empty()) {
      stack1->push(stack2->top());
      stack2->pop();
    }
    return res;
  }

  int peek() {
    while (!stack1->empty()) {
      stack2->push(stack1->top());
      stack1->pop();
    }
    int res = stack2->top();
    while (!stack2->empty()) {
      stack1->push(stack2->top());
      stack2->pop();
    }
    return res;
  }

  bool empty() { return stack1->empty() && stack2->empty(); }

 private:
  stack<int>* stack1;
  stack<int>* stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
