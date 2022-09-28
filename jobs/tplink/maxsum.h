#ifndef JOBS_TPLINK_MAXSUM
#define JOBS_TPLINK_MAXSUM

#include <vector>

int maxSum(const std::vector<int>& nums) {
  int n = nums.size();
  std::vector<int> dp1(n, 0);
  // 0 to n-2
  dp1[0] = nums[0];
  dp1[1] = nums[1];
  for (int i = 2; i < n - 1; ++i) {
    dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i]);
  }
  std::vector<int> dp2(n, 0);
  dp2[1] = nums[1];
  dp2[2] = nums[2];
  for (int i = 3; i < n; ++i) {
    dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i]);
  }
  return std::max(dp1[n - 2], dp2[n - 1]);
}

#endif /* JOBS_TPLINK_MAXSUM */
