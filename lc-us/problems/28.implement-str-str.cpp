/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> kmp_table(string s) {
    vector<int> table(s.size(), 0);
    int i = 1, j = 0;
    while (i < s.size()) {
      if (s[i] == s[j]) {
        table[i] = j + 1;
        i++;
        j++;
      } else if (j > 0) {
        j = table[j - 1];
      } else {
        table[i] = 0;
        i++;
      }
    }
    return table;
  }
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> table = kmp_table(needle);
    int i = 0, j = 0;
    while (i < haystack.size()) {
      if (haystack[i] == needle[j]) {
        i++;
        j++;
      } else if (j > 0) {
        j = table[j - 1];
      } else {
        i++;
      }
      if (j == needle.size()) return i - j;
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  string haystack = "hellabcdabcdabdabdo";
  string needle = "abcdabd";
  auto table = s.kmp_table(needle);
  for (auto i : table) {
    cout << i << " ";
  }
  cout << endl;
  cout << s.strStr(haystack, needle) << endl;
  return 0;
}
