/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
#define ll long long
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    if (nums.size() == 1) {
      return false;
    }
    if (k <= 0) {
      return false;
    }
    map<ll, ll> buckets;
    for (int i = 0; i < nums.size(); i++) {
      ll remapped = (ll)nums[i] - INT_MIN;
      ll bucket = remapped / ((ll)t + 1);
      if (buckets.find(bucket) != buckets.end()) {
        return true;
      }
      if (buckets.find(bucket - 1) != buckets.end() &&
          abs(nums[i] - buckets[bucket - 1]) <= t) {
        return true;
      }
      if (buckets.find(bucket + 1) != buckets.end() &&
          abs(nums[i] - buckets[bucket + 1]) <= t) {
        return true;
      }
      buckets[bucket] = nums[i];
      if (i >= k) {
        buckets.erase(buckets.find(((ll)nums[i - k] - INT_MIN) / ((ll)t + 1)));
      }
    }
    return false;
  }
};
// @lc code=end

