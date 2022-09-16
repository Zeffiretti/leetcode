#ifndef JOBS_PONYAI_PONYCOUNT
#define JOBS_PONYAI_PONYCOUNT
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using ll = long long;

ll ponyCount(const std::string& str) {
  //计算 "pony" 作为子串出现在 str 中的次数
  std::stack<int> p_stack, o_stack, n_stack, y_stack;
  ll res = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 'p') {
      p_stack.push(i);
    } else if (str[i] == 'o') {
      if (!p_stack.empty()) {
        o_stack.push(i);
      }
    } else if (str[i] == 'n') {
      if (!o_stack.empty()) {
        n_stack.push(i);
      }
    } else if (str[i] == 'y') {
      if (!n_stack.empty()) {
        y_stack.push(i);
      }
    }
  }
  if (y_stack.empty() || p_stack.empty() || o_stack.empty() || n_stack.empty()) {
    return 0;
  }
  while (!y_stack.empty()) {
    int y_pos = y_stack.top();
    y_stack.pop();
    while (!n_stack.empty() && n_stack.top() > y_pos) {
      n_stack.pop();
    }
    if (n_stack.empty()) {
      break;
    }
    int n_pos = n_stack.top();
    n_stack.pop();
    while (!o_stack.empty() && o_stack.top() > n_pos) {
      o_stack.pop();
    }
    if (o_stack.empty()) {
      break;
    }
    int o_pos = o_stack.top();
    o_stack.pop();
    while (!p_stack.empty() && p_stack.top() > o_pos) {
      p_stack.pop();
    }
    if (p_stack.empty()) {
      break;
    }
    int p_pos = p_stack.top();
    p_stack.pop();
    res++;
  }
  return res;
}

#endif /* JOBS_PONYAI_PONYCOUNT */
