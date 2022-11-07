#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> removeAnagrams(vector<string>& words) {
    if (words.size() == 1) return words;
    vector<string> res;
    res.push_back(words[0]);
    unordered_map<char, int> m;
    for (int i = 1; i < words.size(); i++) {
      if (words[i].size() != words[i - 1].size()) {
        res.push_back(words[i]);
        continue;
      } else {
        m.clear();
        for (int j = 0; j < words[i - 1].size(); j++) {
          m[words[i - 1][j]]++;
        }
        bool flag = true;
        for (int j = 0; j < words[i].size(); j++) {
          if (m.find(words[i][j]) == m.end()) {
            res.push_back(words[i]);
            flag = false;
            break;
          } else {
            m[words[i][j]]--;
            if (m[words[i][j]] == 0) {
              m.erase(words[i][j]);
            }
          }
        }
        if (flag && !m.empty()) {
          res.push_back(words[i]);
        }
      }
    }
    return res;
  }
};
