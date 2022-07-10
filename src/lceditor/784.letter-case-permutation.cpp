/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<int> letter_indexes;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        letter_indexes.push_back(i);
      }
      if (s[i] >= 'A' && s[i] <= 'Z') {
        letter_indexes.push_back(i);
        s[i] = s[i] - 'A' + 'a';
      }
    }
    int counts = 1 << letter_indexes.size();
    vector<string> res;
    for (int i = 0; i < counts; i++) {
      string tmp = s;
      for (int j = 0; j < letter_indexes.size(); j++) {
        int index = letter_indexes[j];
        if ((i >> j) & 1) {
          tmp[index] = tmp[index] + 'A' - 'a';
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};
// @lc code=end

