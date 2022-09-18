#ifndef JOBS_WERIDE_REACHEND
#define JOBS_WERIDE_REACHEND
#include <vector>

using ll = long long;

int jumpToEnd(const std::vector<ll>& nums) {
  int n = nums.size();
  if (n == 1) {
    return 0;
  }
  ll ans = 0, end = 0, max_pos = 0;
  for (int i = 0; i < nums.size(); ++i) {
    max_pos = std::max(nums[i] + 1, max_pos);
    if (i == end) {
      end = max_pos;
      ans++;
    }
  }
  return ans;
}

#endif /* JOBS_WERIDE_REACHEND */
