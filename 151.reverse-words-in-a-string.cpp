/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int wordcnt = 0;
    string res = "";
    if (s.size() == 1) {
      return s;
    }
    string word = "";
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == ' ') {
        if (wordcnt == 0) {
          if (word.size() != 0) {
            res = word;
            wordcnt++;
          }
        } else {
          if (word.size() != 0) {
            res = res + ' ' + word;
            wordcnt++;
          }
        }
        word = "";
      } else {
        word = s[i] + word;
      }
      if (i == 0) {
        if (word.size() != 0) {
          if (wordcnt == 0) {
            res = res + word;
          } else {
            res = res + ' ' + word;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sol;
  string s = "EPY2giL";
  cout << sol.reverseWords(s) << "over" << endl;
  return 0;
}
