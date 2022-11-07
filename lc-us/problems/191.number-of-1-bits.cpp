/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t bit = 1;
    int res = 0;
    while (n) {
      if (n & bit) {
        res++;
      }
      n >>= 1;
    }
    return res;
  }
};
// @lc code=end
