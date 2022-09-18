#ifndef JOBS_WERIDE_MAXVALUE
#define JOBS_WERIDE_MAXVALUE
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
bool isConflict(const std::vector<std::vector<ll>>& nums, int i, int j) {
  // assure i<j
  return nums[i][1] > nums[j][0];
}

ll maxValue(std::vector<std::vector<ll>>& nums) {
  // nums[i]: {t_start, t_end, value}
  std::sort(nums.begin(), nums.end(), [](const std::vector<ll>& a, const std::vector<ll>& b) { return a[0] < b[0]; });
  ll res = 0;
  std::vector<ll> dp(nums.size(), 0);
  for (int i = 0; i < nums.size(); i++) {
    dp[i] = nums[i][2];
    for (int j = i - 1; j >= 0; j--) {
      if (!isConflict(nums, j, i)) {
        dp[i] = std::max(dp[i], dp[j] + nums[i][2]);
        break;
      } else {
        dp[i] = std::max(dp[i], nums[i][2]);
      }
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    res = std::max(res, dp[i]);
  }
  return res;
}

#endif /* JOBS_WERIDE_MAXVALUE */
