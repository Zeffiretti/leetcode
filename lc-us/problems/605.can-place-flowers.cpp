/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int pre = -2;
    for (int i = 0; i < flowerbed.size(); ++i) {
      if (flowerbed[i] == 1) {
        if (i - pre >= 3) {
          n -= (i - pre - 2) / 2;
        }
        if (n <= 0) return true;
        pre = i;
      }
    }
    int i = flowerbed.size() + 1;
    if (i - pre >= 3) {
      n -= (i - pre - 2) / 2;
    }
    return n <= 0;
  }
};
// @lc code=end

