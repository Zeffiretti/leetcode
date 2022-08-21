#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include <stdio.h>

class Solution {
 public:
  string largestPalindromic(string num) {
    string res = "";
    int len_half = 0;
    vector<int> num_cnt(10, 0);
    bool all_zero = true;
    for (char i : num) {
      num_cnt[i - '0']++;
      if (num_cnt[i - '0'] > 0) {
        all_zero = false;
      }
    }
    if (all_zero) {
      return "0";
    }
    for (int i = 0; i < 10; ++i) {
      if (num_cnt[i] > 1) {
        int l = num_cnt[i] / 2;
        string app = string(l, i + '0');
        res = app + res + app;
        num_cnt[i] = num_cnt[i] % 2;
        len_half += l;
      }
    }
    int i = 9;
    while (i >= 0 && num_cnt[i] == 0) {
      --i;
    }
    if (i >= 0) {
      res = res.substr(0, len_half) + to_string(i) + res.substr(len_half);
    }
    i = 0;
    while (res[i] == '0') {
      res.erase(res.begin());
      res.erase(res.end() - 1);
    }
    if (res == "") {
      res = "0";
    }
    return res;
  }
};