/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> map;
    int majority = nums.size() / 2;
    int res = nums[0];
    for (auto num : nums) {
      if (map.find(num) == map.end()) {
        map[num] = 1;
      } else {
        map[num]++;
        if (map[num] > majority) {
          res = num;
          break;
        }
      }
    }
    return res;
  }
};
// @lc code=end

