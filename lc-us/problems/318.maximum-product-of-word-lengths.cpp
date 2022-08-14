/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
#include <cstdint>
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int maxProduct(const vector<string>& words) {
    vector<uint32_t> masks(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
      for (const auto& c : words[i]) {
        masks[i] |= 1 << (c - 'a');
      }
    }
    int res = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if ((masks[i] & masks[j]) == 0) {
          res = max(res, static_cast<int>(words[i].size() * words[j].size()));
        }
      }
    }
    return res;
  }
};
// @lc code=end
