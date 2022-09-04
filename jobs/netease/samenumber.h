#ifndef JOBS_NETEASE_SAMENUMBER
#define JOBS_NETEASE_SAMENUMBER

#include <algorithm>
#include <iostream>
#include <vector>

int samenumber(const std::vector<int>& nums, int k) {
  // write code here
  std::vector<int> counts(k + 1, 0);
  for (int num : nums) {
    int res = num % k;
    if (res < 0) {
      res += k;
    }
    counts[res]++;
  }
  int res = 0;
  for (int i = 0; i <= k; ++i) {
    res = std::max(res, counts[i]);
  }
  return res;
}

#endif /* JOBS_NETEASE_SAMENUMBER */
