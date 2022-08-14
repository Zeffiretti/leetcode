/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));  // insert every nums[i] in hashset
    vector<int> ans(nums.size() - s.size());
    for (int i = 1, j = 0; i <= nums.size(); i++)
      if (!s.count(i)) ans[j++] = i;  // add all elements not found in hashset to ans
    return ans;
  }
};
// @lc code=end
