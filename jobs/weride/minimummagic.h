#ifndef JOBS_WERIDE_MINIMUMMAGIC
#define JOBS_WERIDE_MINIMUMMAGIC
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <vector>

using ll = long long;
ll minAfterCompensation(std::vector<ll>& nums, int compen) {
  std::sort(nums.begin(), nums.end());
  std::map<ll, int> value_count;
  for (auto num : nums) {
    if (value_count.find(num) == value_count.end()) {
      value_count[num] = 1;
    } else {
      value_count[num]++;
    }
  }
  ll res = nums[0];
  ll n = value_count[res];
  while (n < nums.size()) {
    int next = res + compen;
  }
  return res;
}

#endif /* JOBS_WERIDE_MINIMUMMAGIC */
