#include <vector>

class Solution {
 public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    }
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
      if (dp[i] >= 1e9 + 7) {
        dp[i] %= static_cast<int>(1e9 + 7);
      }
    }
    return dp[n];
  }
};