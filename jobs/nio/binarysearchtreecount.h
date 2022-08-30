#ifndef JOBS_NIO_BINARYSEARCHTREECOUNT
#define JOBS_NIO_BINARYSEARCHTREECOUNT

#include <iostream>
#include <vector>

using ll = long long;

ll binarySearchTreeCount(int n) {
  std::vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] += dp[j - 1] * dp[i - j];
    }
  }
  return dp[n];
}

#endif /* JOBS_NIO_BINARYSEARCHTREECOUNT */
