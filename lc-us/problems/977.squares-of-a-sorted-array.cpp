/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    vector<int> res(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (abs(nums[left]) > abs(nums[right])) {
        res[i] = nums[left] * nums[left];
        left++;
      } else {
        res[i] = nums[right] * nums[right];
        right--;
      }
    }
    return res;
  }
};
// @lc code=end

