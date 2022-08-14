/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */
#include <vector>
#include "utils.h"
// @lc code=start
class Solution {
 public:
  using ll = long long;
  int countVowelPermutation(int n) {
    vector<ll> counts(5, 1);

    for (int i = 1; i < n; i++) {
      vector<ll> tmp_counts(counts);
      counts[0] = (tmp_counts[1] + tmp_counts[2] + tmp_counts[4]) % 1000000007;
      counts[1] = (tmp_counts[0] + tmp_counts[2]) % 1000000007;
      counts[2] = (tmp_counts[1] + tmp_counts[3]) % 1000000007;
      counts[3] = tmp_counts[2] % 1000000007;
      counts[4] = (tmp_counts[2] + tmp_counts[3]) % 1000000007;
    }
    return (counts[0] + counts[1] + counts[2] + counts[3] + counts[4]) % 1000000007;
  }
};
// @lc code=end
