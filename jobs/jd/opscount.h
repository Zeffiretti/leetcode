#ifndef JOBS_JD_OPSCOUNT
#define JOBS_JD_OPSCOUNT
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> getPrimes(int n) {
  std::vector<int> primes;
  for (int i = 2; i < n; ++i) {
    bool is_prime = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      primes.push_back(i);
    }
  }
  return primes;
}

std::vector<int> buildCounts(int n) {
  std::vector<int> counts(100001);
  counts[1] = 0;
  for (int i = 2; i <= n; ++i) {
    counts[i] = i - 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; i * j <= n; ++j) {
      counts[i * j] = std::min(counts[i * j - 1] + 1, std::min(counts[i * j], counts[i] + counts[j] + 1));
    }
  }
  std::vector<int> primes = getPrimes(n);
  for (int i = 0; i < primes.size(); ++i) {
    counts[primes[i]] = counts[primes[i] - 1] + 1;
  }
  return counts;
}

int minOperation(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  std::vector<int> counts = buildCounts(nums[nums.size() - 1]);
  int res = 0;
  for (int i = 0; i < nums.size(); ++i) {
    res += counts[nums[i]];
  }
  return res;
}

#endif /* JOBS_JD_OPSCOUNT */
