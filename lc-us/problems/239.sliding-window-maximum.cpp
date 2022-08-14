/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.empty()) return res;
    deque<int> dq;
    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
  }
};
// @lc code=end
