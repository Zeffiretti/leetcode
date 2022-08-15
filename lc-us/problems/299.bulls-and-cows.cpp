/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string getHint(string secret, string guess) {
    int a = 0, b = 0;
    vector<int> count(10, 0);
    for (int i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) {
        a++;
      } else {
        count[secret[i] - '0']++;
        count[guess[i] - '0']--;
      }
    }
    for (int i = 0; i < count.size(); i++) {
      if (count[i] > 0) {
        b += count[i];
      }
    }
    return to_string(a) + "A" + to_string(b) + "B";
  }
};
// @lc code=end
