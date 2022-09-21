#ifndef JOBS_WATERDROP_USCOUNT
#define JOBS_WATERDROP_USCOUNT
#include <vector>

int usCount(int n) {
  std::vector<int> dp(n + 1, 0);
  int sum = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] * 26 * i - i + 1;
    dp[i] %= 1000000007;
    sum += dp[i];
    sum %= 1000000007;
  }
  return sum;
}

#endif /* JOBS_WATERDROP_USCOUNT */
