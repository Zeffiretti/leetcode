#ifndef JOBS_MICROSOFT_REHABILITATION
#define JOBS_MICROSOFT_REHABILITATION
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
namespace rehabitalition {

int solution(vector<int>& A, int X, int Y) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  vector<vector<int>> dp(X + 1, vector<int>(A.size(), INT_MAX));
  dp[1][0] = A[0];
  for (int i = 1; i < A.size(); ++i) {
    dp[1][i] = min(dp[1][i - 1], A[i]);
  }
  for (int i = 2; i <= X; ++i) {
    for (int j = 0; j < A.size(); ++j) {
    }
  }
  return 0;
}
}  // namespace rehabitalition
#endif /* JOBS_MICROSOFT_REHABILITATION */
