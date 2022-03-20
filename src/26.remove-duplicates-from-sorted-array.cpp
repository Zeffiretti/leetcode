/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] != nums[i + 1]) {
        nums[index] = nums[i];
        index++;
      }
    }
    nums[index] = nums[nums.size() - 1];
    index++;
    return index + 1;
  }
};
// @lc code=end

