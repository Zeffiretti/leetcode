/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      if (numbers[left] + numbers[right] == target) {
        return {left + 1, right + 1};
      }
      if (numbers[left] + numbers[right] < target) {
        int mid = left + (right - left) / 2;
        if (numbers[right] + numbers[mid] < target) {
          left = mid + 1;
        } else {
          ++left;
        }
      } else {
        int mid = left + (right - left) / 2;
        if (numbers[mid] + numbers[left] > target) {
          right = mid - 1;
        } else {
          --right;
        }
      }
    }
    return {};
  }
};
// @lc code=end

