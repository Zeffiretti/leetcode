#ifndef JOBS_MICROSOFT_MERGEARRAY
#define JOBS_MICROSOFT_MERGEARRAY

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace mergearray {
int solution(std::vector<int>& A, std::vector<int>& B) {
  std::vector<bool> visited(100000 + 1, false);
  for (int i = 0; i < A.size(); ++i) {
    visited[std::max(A[i], B[i])] = true;
  }
  for (int i = 1; i <= 100000; ++i) {
    if (!visited[i]) {
      return i;
    }
  }
  return 100000 + 1;
}
}  // namespace mergearray

#endif /* JOBS_MICROSOFT_MERGEARRAY */
