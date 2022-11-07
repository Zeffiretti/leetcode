/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int Xor = x ^ y, ans = 0;
    while (Xor) ans++, Xor &= Xor - 1;
    return ans;
  }
};
// @lc code=end
