#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestIdealString(string s, int k) {
    int res = 0;
    vector<int> indexes(26, -1);
    vector<int> dp(s.size(), 1);
    for (int i = 0; i < s.size(); ++i) {
      int begin = s[i] - k - 'a';
      begin = max(begin, 0);
      int end = s[i] + k - 'a';
      end = min(end, 25);
      for (int c = begin; c <= end; ++c) {
        if (indexes[c] != -1) {
          int pos = indexes[c];
          dp[i] = max(dp[i], dp[pos] + 1);
        }
      }
      indexes[s[i] - 'a'] = i;
      res = max(res, dp[i]);
    }
    return res;
  }
};
