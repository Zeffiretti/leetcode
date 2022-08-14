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
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size()) {
      std::string v1 = "0", v2 = "0";
      while (i < version1.size() && version1[i] != '.') {
        v1 += version1[i++];
      }
      while (v1.size() > 1 && v1[0] == '0') v1.erase(0, 1);
      while (j < version2.size() && version2[j] != '.') {
        v2 += version2[j++];
      }
      while (v2.size() > 1 && v2[0] == '0') v2.erase(0, 1);
      if (v1.size() > v2.size()) return 1;
      if (v1.size() < v2.size()) return -1;
      if (v1 > v2) return 1;
      if (v1 < v2) return -1;
      ++i;
      ++j;
    }
    return 0;
  }
};
// @lc code=end
