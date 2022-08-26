#ifndef JOBS_MICROSOFT_ALIGNEDSET
#define JOBS_MICROSOFT_ALIGNEDSET

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace alignedset {
int solution(std::vector<int>& A, int M) {
  // write your code in C++ (g++ 6.2.0)
  if (M == 1) {
    return A.size();
  }
  std::vector<int> pos(M, 0);
  for (int i = 0; i < A.size(); ++i) {
    int idx = A[i] % M;
    if (idx < 0) idx += M;
    pos[idx]++;
  }
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    ans = std::max(ans, pos[i]);
  }
  return ans;
}
}  // namespace alignedset

#endif /* JOBS_MICROSOFT_ALIGNEDSET */
