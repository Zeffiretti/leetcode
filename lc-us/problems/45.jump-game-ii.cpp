/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int steps = 0;
    int depature = n - 1;
    while (depature > 0) {
      depature = reach(nums, depature);
      steps++;
    }
    return steps;
  }

  // look for the far depature index that can reach the dest
  int reach(vector<int>& nums, int dest) {
    int n = nums.size();
    int depature = 0;
    for (int i = 0; i < dest; ++i) {
      if (i + nums[i] >= dest) {
        depature = i;
        break;
      }
    }
    return depature;
  }
};
// @lc code=end
