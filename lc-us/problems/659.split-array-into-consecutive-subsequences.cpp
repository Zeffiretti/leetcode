/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    if (nums.size() < 3) {
      return false;
    }
    unordered_map<int, int> count;
    unordered_map<int, int> tails;
    for (int val : nums) {
      count[val]++;
    }
    for (int val : nums) {
      if (count[val] == 0) {
        continue;
      }
      if (tails[val] > 0) {
        tails[val]--;
        tails[val + 1]++;
      } else if (count[val + 1] > 0 && count[val + 2] > 0) {
        count[val + 1]--;
        count[val + 2]--;
        tails[val + 3]++;
      } else {
        return false;
      }
      count[val]--;
    }
    return true;
  }
};
// @lc code=end
