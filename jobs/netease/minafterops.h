#ifndef JOBS_NETEASE_MINAFTEROPS
#define JOBS_NETEASE_MINAFTEROPS

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

int minimumMaxAfterOperation(std::vector<int>& nums, int k, int x) {
  // write code here
  // descending order
  std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
  if (nums[0] == nums[nums.size() - 1]) {
    int n = k / nums.size();
    return nums[0] - n * x;
  }
  std::priority_queue<int> pq(nums.begin(), nums.end());
  while (k > 0) {
    int top = pq.top();
    pq.pop();
    int n = std::min(k, (top - pq.top()) / x + 1);
    k -= n;
    top -= n * x;
    pq.push(top);
  }
  return pq.top();
}

#endif /* JOBS_NETEASE_MINAFTEROPS */
