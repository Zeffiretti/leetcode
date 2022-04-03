/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
 public:
  int numTilings(int n) {
    if (n < 3) return n;
    int mod = 1e9 + 7;
    long d0 = 0, d1 = 1, d2 = 2, d3 = 0;
    long t0 = 0, t1 = 1, t2 = 2, t3 = 0;

    for (int i = 3; i <= n; i++) {
      d3 = (d2 + d1 + 2 * t1) % mod;
      t3 = (t2 + d2) % mod;

      d1 = d2, d2 = d3;
      t1 = t2, t2 = t3;
    }
    return d3;
  }
};
// @lc code=end

