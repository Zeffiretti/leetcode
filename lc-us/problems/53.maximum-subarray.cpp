/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;
    int f_n = -1;
    for (int i = 0; i < nums.size(); ++i) {
      f_n = max(nums[i], f_n + nums[i]);
      res = max(f_n, res);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> nums = {0, 0, 0, 0, 0, -2, 1, -3, 4, -1, 0, 0, 0, 0, 2, 1, -5, 4, 0, 0, 0, 0};
  Solution ss;
  cout << ss.maxSubArray(nums);
  return 0;
}
