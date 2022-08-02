/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <stack>
#include <string>
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> s;
    string dir;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        if (dir == "..") {
          if (!s.empty()) s.pop();
        } else if (dir != "." && dir != "") {
          s.push(dir);
        }
        dir = "";
      } else {
        dir += path[i];
      }
    }
    if (dir == "..") {
      if (!s.empty()) s.pop();
    } else if (dir != "." && dir != "") {
      s.push(dir);
    }
    string res;
    while (!s.empty()) {
      res = "/" + s.top() + res;
      s.pop();
    }
    return res.empty() ? "/" : res;
  }
};
// @lc code=end
