#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validPartition(vector<int>& nums) {
    if (nums.size() == 2) return nums[0] == nums[1];
    if (nums.size() == 3) {
      if (nums[0] == nums[1]) {
        return nums[0] == nums[2];
      }
      if (nums[1] == nums[0] + 1) {
        return nums[2] == nums[1] + 1;
      }
      return false;
    }
    vector<bool> dp(nums.size(), false);
    dp[0] = false;
    if (nums[0] == nums[1]) {
      dp[1] = true;
    }
    if (nums[2] - nums[1] == 1 && nums[1] - nums[0] == 1) {
      dp[2] = true;
    }
    if (nums[2] == nums[1] && nums[1] == nums[0]) {
      dp[2] = true;
    }
    for (int i = 3; i < nums.size(); ++i) {
      if (dp[i] - dp[i - 1] > 1) {
        dp[i] = false;
      } else if (nums[i] == nums[i - 1]) {
        if (nums[i - 1] == nums[i - 2]) {
          dp[i] = dp[i - 3];
        }
        dp[i] = dp[i] || dp[i - 2];
      } else {
        if (nums[i - 1] - nums[i - 2] == 1) {
          dp[i] = dp[i - 3];
        } else {
          dp[i] = false;
        }
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      cout << dp[i] << " ";
    }
    return dp[nums.size() - 1];
  }
};
