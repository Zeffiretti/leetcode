/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) return n;
    int i = 2;
    for (int j = 2; j < n; j++) {
      if (nums[j] != nums[i - 2]) {
        nums[i++] = nums[j];
      }
    }
    return i;
  }
};
// @lc code=end

