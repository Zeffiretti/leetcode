#ifndef JOBS_MOBVISTA_MAXFORM
#define JOBS_MOBVISTA_MAXFORM
#include <iostream>
#include <string>
#include <vector>

int findMaxForm(const std::vector<std::string>& strs, int m, int n) {
  // m个1和n个0能组成多少个字符串
  if (strs.empty()) {
    return 0;
  }
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (auto str : strs) {
    int ones = 0;
    int zeros = 0;
    for (auto c : str) {
      if (c == '0') {
        zeros++;
      } else {
        ones++;
      }
    }
    for (int i = m; i >= zeros; i--) {
      for (int j = n; j >= ones; j--) {
        dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
      }
    }
  }
  return dp[m][n];
}

#endif /* JOBS_MOBVISTA_MAXFORM */
