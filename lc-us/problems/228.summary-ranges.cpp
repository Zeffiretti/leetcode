/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.size() == 0) return res;
    int start = nums[0], end = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1] + 1) {
        // found a range
        end = nums[i - 1];
        if (start == end) {
          res.push_back(to_string(start));
        } else {
          res.push_back(to_string(start) + "->" + to_string(end));
        }
        start = nums[i];
      }
    }
    if (start == nums[nums.size() - 1]) {
      res.push_back(to_string(start));
    } else {
      res.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));
    }
    return res;
  }
};
// @lc code=end
