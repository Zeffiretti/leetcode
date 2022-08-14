#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string smallestNumber(string pattern) {
    int n = pattern.size();
    string res(n + 1, '0');
    vector<bool> used(10, false);
    used[1] = true;
    int val = 1;
    int minimum = 1;
    int decrease_cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pattern[i] == 'I') {
        res[i] = '0' + minimum;
        used[minimum] = true;
        while (used[minimum]) minimum++;
        for (int m = 1; m <= decrease_cnt; m++) {
          res[i - m] = '0' + minimum;
          used[minimum] = true;
          while (used[minimum]) minimum++;
        }
        decrease_cnt = 0;
        while (used[val]) {
          val++;
        }
        minimum = min(minimum, val);
      } else {
        decrease_cnt++;
      }
    }
    int i = n;
    res[i] = '0' + minimum;
    used[minimum] = true;
    while (used[minimum]) minimum++;
    for (int m = 1; m <= decrease_cnt; m++) {
      res[i - m] = '0' + minimum;
      used[minimum] = true;
      while (used[minimum]) minimum++;
    }
    decrease_cnt = 0;
    while (used[val]) {
      val++;
    }
    minimum = min(minimum, val);
    return res;
  }
};