/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if (n > m) return false;
    vector<int> cnt(26, 0);
    int distinct_count = 0;
    for (char c : s1) {
      ++cnt[c - 'a'];
      if (cnt[c - 'a'] == 1) ++distinct_count;
    }
    vector<int> sub_cnt(26, 0);
    int slow = 0, fast = 0;
    int distinct_count_slow = 0;
    while (fast < m) {
      char ch = s2[fast] - 'a';
      if (cnt[ch] > 0) {
        ++sub_cnt[ch];
        if (sub_cnt[ch] == cnt[ch]) ++distinct_count_slow;
        // cout << "distinct_count_slow: " << distinct_count_slow << endl;
        // cout << "distinct_count: " << distinct_count << endl;
        while (slow <= fast && distinct_count_slow == distinct_count) {
          // cout << slow << " " << fast << endl;
          if (fast - slow + 1 == n) return true;
          if (fast - slow + 1 < n) break;
          char ch_slow = s2[slow] - 'a';
          if (cnt[ch_slow] > 0 && sub_cnt[ch_slow] == cnt[ch_slow]) {
            // cout << "ch_slow: " << char(ch_slow + 'a') << endl;
            --distinct_count_slow;
          }
          --sub_cnt[ch_slow];
          ++slow;
        }
      }
      ++fast;
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  cout << s.checkInclusion("obcoaaob", "eidbaoooabcd") << endl;
  return 0;
}