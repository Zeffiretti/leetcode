/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    map<char, string> forward_map;
    map<string, char> backward_map;
    string t;
    int pattern_index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        if (pattern_index >= pattern.size()) return false;
        if (forward_map.count(pattern[pattern_index]) == 0) {
          if (backward_map.count(t) == 0) {
            forward_map[pattern[pattern_index]] = t;
            backward_map[t] = pattern[pattern_index];
          } else {
            return false;
          }
        } else if (forward_map[pattern[pattern_index]] != t) {
          return false;
        } else if (backward_map[t] != pattern[pattern_index]) {
          return false;
        }
        pattern_index++;
        t.clear();
      } else {
        t += s[i];
      }
    }
    if (pattern_index >= pattern.size()) return false;
    if (forward_map.count(pattern[pattern_index]) == 0) {
      if (backward_map.count(t) == 0) {
        forward_map[pattern[pattern_index]] = t;
        backward_map[t] = pattern[pattern_index];
      } else {
        return false;
      }
    } else if (forward_map[pattern[pattern_index]] != t) {
      return false;
    } else if (backward_map[t] != pattern[pattern_index]) {
      return false;
    }
    pattern_index++;
    return pattern_index == pattern.size();
  }
};
// @lc code=end
