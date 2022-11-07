#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    vector<vector<char>> maps(128);
    for (int i = 0; i < maps.size(); i++) {
      maps[i].push_back(i);
    }
    for (int i = 0; i < mappings.size(); i++) {
      maps[mappings[i][0]].push_back(mappings[i][1]);
    }
    vector<string> combins;
    string cur = "";
    dfs(combins, cur, sub, maps, 0, 0, 0);
    for (int i = 0; i < combins.size(); i++) {
      if (s.find(combins[i]) != string::npos) {
        cout << combins[i] << endl;
        return true;
      }
    }
    return false;
  }
  void dfs(vector<string>& combins, string& cur, string sub, vector<vector<char>>& maps) {
    if (cur.size() == sub.size()) {
      combins.push_back(cur);
      return;
    }
    int i = cur.size();
    char raw = sub[i];
    for (int j = 0; j < maps[raw].size(); j++) {
      cur += maps[raw][j];
      dfs(combins, cur, sub, maps);
      cur.pop_back();
    }
  }
};
