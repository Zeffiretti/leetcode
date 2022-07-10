/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<int> v1, v2;
    stringstream ss1(version1), ss2(version2);
    string s;
    while (getline(ss1, s, '.')) {
      v1.push_back(stoi(s));
    }
    while (getline(ss2, s, '.')) {
      v2.push_back(stoi(s));
    }
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
      if (v1[i] > v2[j]) {
        return 1;
      } else if (v1[i] < v2[j]) {
        return -1;
      }
      i++;
      j++;
    }
    while (i < v1.size()) {
      if (v1[i] > 0) {
        return 1;
      }
      i++;
    }
    while (j < v2.size()) {
      if (v2[j] > 0) {
        return -1;
      }
      j++;
    }
    return 0;
  }
};
// @lc code=end

