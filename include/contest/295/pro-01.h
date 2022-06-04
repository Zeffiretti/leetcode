#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      count[s[i] - 'a']++;
    }
    int res = INT_MAX;
    vector<int> count_target(26, 0);
    for (int i = 0; i < target.size(); ++i) {
      count_target[target[i] - 'a']++;
    }
    for (int i = 0; i < target.size(); ++i) {
      res = min(res, count[target[i] - 'a'] / count_target[target[i] - 'a']);
    }
    return res;
  }
};

