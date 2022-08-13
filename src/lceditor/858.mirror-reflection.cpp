/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int mirrorReflection(int p, int q) {
    while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
    return 1 - p % 2 + q % 2;
  }
};
// @lc code=end
