#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int count(int i, int start = 9) {
    if (i == 0) return start;
    return (start - i) * count(i - 1, start);
  }
  int dfs(int i, int mask, string& sn) {
    if (i >= sn.size()) return 1;
    int res = 0, cur = sn[i] - '0';
    for (int j = (i == 0) ? 1 : 0; j < cur; ++j) {
      if ((mask & (1 << j)) == 0) {
        res += (int)sn.size() - 2 - i >= 0 ? count(sn.size() - 2 - i, 9 - i) : 1;
      }
    }
    if ((mask & (1 << cur)) == 0) res += dfs(i + 1, mask + (1 << cur), sn);
    return res;
  }
  int countSpecialNumbers(int n) {
    if (n < 10) return n;
    int res = 9;
    string sn = to_string(n);
    for (int i = 0; i < sn.size() - 2; ++i) {
      res += 9 * count(i);
    }
    return res + dfs(0, 0, sn);
  }
};