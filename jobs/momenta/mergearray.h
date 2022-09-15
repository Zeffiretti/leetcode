#ifndef JOBS_MOMENTA_MERGEARRAY
#define JOBS_MOMENTA_MERGEARRAY

#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> mergeArray(const std::vector<std::vector<int>>& arrays) {
  std::vector<int> result;
  std::priority_queue<std::vector<int>> pq;
  size_t m = arrays.size();
  for (size_t i = 0; i < m; ++i) {
    if (!arrays[i].empty()) {
      std::vector<int> elem = {arrays[i][0], static_cast<int>(i), 0};
      pq.push(elem);
    }
  }
  while (!pq.empty()) {
    // pop the top element
    std::vector<int> elem = std::move(pq.top());
    pq.pop();
    result.push_back(elem[0]);
    if (elem[2] + 1 < arrays[elem[1]].size()) {
      std::vector<int> e = {arrays[elem[1]][elem[2] + 1], elem[1], elem[2] + 1};
      pq.push(std::move(e));
    }
  }
  return result;
}

#endif /* JOBS_MOMENTA_MERGEARRAY */
