/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool canWinNim(int n) { return n % 4 != 0; }
};
// @lc code=end
