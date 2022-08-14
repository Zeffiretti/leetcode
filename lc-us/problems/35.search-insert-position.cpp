/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return left;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution solution;
  vector<int> nums = {1, 3, 5, 6};
  cout << solution.searchInsert(nums, 4);
  return 0;
}

