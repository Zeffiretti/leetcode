#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string greatestLetter(string s) {
    vector<bool> uppercase(26, false);
    vector<bool> lowercase(26, false);
    for (auto c : s) {
      if (c >= 'A' && c <= 'Z') {
        uppercase[c - 'A'] = true;
      } else if (c >= 'a' && c <= 'z') {
        lowercase[c - 'a'] = true;
      }
    }
    string res;
    for (int i = 0; i < 26; ++i) {
      if (uppercase[i] && lowercase[i]) {
        res = 'A' + i;
      }
    }
    return res;
  }
};