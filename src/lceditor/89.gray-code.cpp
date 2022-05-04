/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    for (int i = 0; i < n; i++) {
      int size = res.size();
      for (int j = size - 1; j >= 0; j--) {
        res.push_back(res[j] | (1 << i));
      }
    }
    return res;
  }

//  private:
//   vector<int> grayCode(int n, int i) {
//     vector<int> res;
//     if (i == 0) {
//       res.push_back(0);
//     }
//     if (i == n) {
//       res.push_back(1);
//     }
//     vector<int> left = grayCode(n, i - 1);
//     vector<int> right = grayCode(n, i);
//     for (int j = 0; j < left.size(); j++) {
//       res.push_back(left[j] + 2 ^ right[j]);
//     }
//     return res;
//   }
};
// @lc code=end

