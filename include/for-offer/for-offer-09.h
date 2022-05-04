#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

// implement Queue using two stacks
class CQueue {
 public:
  CQueue() {
    s1 = new stack<int>();
    s2 = new stack<int>();
  }

  void appendTail(int value) {
    s1->push(value);
  }

  int deleteHead() {
    if (s2->empty()) {
      while (!s1->empty()) {
        s2->push(s1->top());
        s1->pop();
      }
    }
    if (s2->empty()) {
      return -1;
    }
    int res = s2->top();
    s2->pop();
    return res;
  }
 private:
  stack<int> *s1;
  stack<int> *s2;
};