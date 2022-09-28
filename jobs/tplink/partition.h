#ifndef JOBS_TPLINK_PARTITION
#define JOBS_TPLINK_PARTITION
#include <vector>

bool canPartitionNumsToKPieces(const std::vector<int>& nums, int k) {
  // to determine whether nums can be partitioned into k pieces, with each piece
  // has the same sum
  int n = nums.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
  }
  if (sum % k != 0) {
    return false;
  }
  int target = sum / k;
  std::vector<int> dp(1 << n, 0);
  dp[0] = 1;
  for (int i = 0; i < (1 << n); ++i) {
    if (dp[i] == 0) {
      continue;
    }
    int curSum = 0;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        curSum += nums[j];
      }
    }
    curSum %= target;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        int next = i | (1 << j);
        if (dp[next] == 0) {
          dp[next] = curSum + nums[j] == target ? 1 : -1;
        } else if (dp[next] == 1) {
          continue;
        } else {
          dp[next] = curSum + nums[j] == target ? 1 : -1;
        }
      }
    }
  }
  return dp[(1 << n) - 1] == 1;
}

#endif /* JOBS_TPLINK_PARTITION */
