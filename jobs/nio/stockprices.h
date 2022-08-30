#ifndef JOBS_NIO_STOCKPRICES
#define JOBS_NIO_STOCKPRICES

#include <algorithm>
#include <vector>

using ll = long long;

ll stockProfits(const std::vector<int>& prices) {
  ll ans = 0;
  for (int i = 1; i < prices.size(); ++i) {
    ans += std::max(0, prices[i] - prices[i - 1]);
  }
  return ans;
}

#endif /* JOBS_NIO_STOCKPRICES */
