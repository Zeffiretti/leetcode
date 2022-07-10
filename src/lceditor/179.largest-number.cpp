/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    vector<string> strs;
    for (auto num : nums) {
      strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), [](const string & a, const string & b) {
      return a + b > b + a;
    });
    string res;
    for (auto str : strs) {
      res += str;
    }
    if (res[0] == '0') {
      return "0";
    }
    return res;
  }
};
// @lc code=end

