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
    int n = nums.size();
    int left = 0;
    int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
    while (left <= right) { // 当left==right，区间[left, right]依然有效
      int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
      if (nums[middle] > target) {
        right = middle - 1; // target 在左区间，所以[left, middle - 1]
      } else if (nums[middle] < target) {
        left = middle + 1; // target 在右区间，所以[middle + 1, right]
      } else { // nums[middle] == target
        return middle;
      }
    }
    return right + 1;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution solution;
  vector<int> nums = {1, 3, 5, 6};
  cout << solution.searchInsert(nums, 4);
  return 0;
}

