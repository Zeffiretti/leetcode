#ifndef JOBS_MICROSOFT_PRACTICE
#define JOBS_MICROSOFT_PRACTICE

// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using ll = long long;
int solution(vector<vector<int> >& A) {
  // write your code in [LANGVER]
  int n = A.size(), m = A[0].size();
  if (n == 0 || m == 0) {
    return 0;
  }
  vector<ll> rows_sum(n, 0), cols_sum(m, 0);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      rows_sum[i] += A[i][j];
      cols_sum[j] += A[i][j];
      sum += A[i][j];
    }
  }
  std::cout << "sum = " << sum << std::endl;
  int rows_cnt = 0, cols_cnt = 0;
  ll pre_sum = 0;
  for (int i = 0; i < n; ++i) {
    if (pre_sum == sum - rows_sum[i] - pre_sum) {
      ++rows_cnt;
    }
    pre_sum += rows_sum[i];
  }
  if (rows_cnt == 0) {
    return 0;
  }
  pre_sum = 0;
  for (int j = 0; j < m; ++j) {
    if (pre_sum == sum - cols_sum[j] - pre_sum) {
      ++cols_cnt;
    }
    pre_sum += cols_sum[j];
  }
  std::cout << "rows_cnt=" << rows_cnt << " cols_cnt=" << cols_cnt << std::endl;
  return rows_cnt * cols_cnt;
}

#endif /* JOBS_MICROSOFT_PRACTICE */
