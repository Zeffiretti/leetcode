/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0;
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (long i = 2; i < n; ++i) {
      if (is_prime[i]) {
        for (long j = i * i; j < n; j += i) {
          is_prime[j] = false;
        }
      }
    }
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (is_prime[i])
        ++count;
    }
    return count;
  }
};
// @lc code=end

