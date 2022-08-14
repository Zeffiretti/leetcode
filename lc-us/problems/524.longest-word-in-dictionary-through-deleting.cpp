/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string findLongestWord(string s, vector<string> &dictionary) {
    vector<string> tmp_dict = dictionary;
    for (auto c : s) {
      for (int i = 0; i < tmp_dict.size(); i++) {
        if (!tmp_dict[i].empty() && tmp_dict[i][0] == c) {
          tmp_dict[i].erase(0, 1);
        }
      }
    }
    string res;
    for (int i = 0; i < dictionary.size(); ++i) {
      if (tmp_dict[i].empty()) {
        if (dictionary[i].size() > res.size()) {
          res = dictionary[i];
        } else if (dictionary[i].size() == res.size()) {
          res = res < dictionary[i] ? res : dictionary[i];
        }
      }
    }
    return res;
  }
};
// @lc code=end

