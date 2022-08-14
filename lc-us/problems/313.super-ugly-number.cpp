/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  using ll = long long;
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n <= 0) return false;
    if (n == 1) return true;
    vector<ll> t(primes.size(), 0);
    vector<ll> k(n);
    k[0] = 1;
    for (int i = 1; i < n; i++) {
      k[i] = INT_MAX;
      for (int j = 0; j < primes.size(); j++) {
        k[i] = min(k[i], k[t[j]] * primes[j]);
      }
      for (int j = 0; j < primes.size(); j++) {
        if (k[i] == k[t[j]] * primes[j]) t[j]++;
      }
    }
    return k[n - 1];
  }
};
// @lc code=end
