#ifndef JOBS_SANGFOR_MAXOVERLAP
#define JOBS_SANGFOR_MAXOVERLAP
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using ll = long long;

ll maxOverlap(std::vector<std::vector<int>>& intervals) {
  ll res = 0;
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
  // 优先队列，小的在前
  std::priority_queue<int, std::vector<int>, std::greater<int>> priority_ends;
  std::vector<ll> current_overlaps(intervals.size(), 0);
  for (int i = 0; i < intervals.size(); ++i) {
    while (!priority_ends.empty() && priority_ends.top() < intervals[i][0]) {
      priority_ends.pop();
    }
    current_overlaps[i] = priority_ends.size() + 1;
    priority_ends.push(intervals[i][1]);
  }
  for (int i = 0; i < intervals.size(); ++i) {
    res += std::max(res, current_overlaps[i] - 1);
  }
  return res;
}

#endif /* JOBS_SANGFOR_MAXOVERLAP */
